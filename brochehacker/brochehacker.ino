/* single max7219 controller for attiny85
 * 160726 svetlana tovarisch
 */
 
// attiny85 pins
#define MAX_DIN 0 // data in
#define MAX_CS  3 // chip select (aka load)
#define MAX_CLK 4 // clock

// registers
#define MAX_NOP 0x00 // no operation
#define MAX_DEC 0x09 // decode mode
#define MAX_INT 0x0a // intensity
#define MAX_SCN 0x0b // scan limit
#define MAX_SDN 0x0c // shutdown
#define MAX_TST 0x0f // display test

#define ANIM_DLY 600

void putByte(byte data) {
  for(byte i = 8; i > 0; i--) {
    // pulse to start bit
    digitalWrite(MAX_CLK, LOW);
    // send bit i
    digitalWrite(MAX_DIN, data & (0x01 << i-1));
    // end bit pulse
    digitalWrite(MAX_CLK, HIGH);
  }
}

void sendMax(byte reg, byte data) {
  // select chip
  digitalWrite(MAX_CS, LOW);
  putByte(reg);
  putByte(data);
  digitalWrite(MAX_CS, HIGH);
}

void maxInit() {
  sendMax(MAX_SCN, 0x07); // display all digits
  sendMax(MAX_DEC, 0x00); // led matrix mode
  sendMax(MAX_SDN, 0x01); // no shutdown
  sendMax(MAX_TST, 0x00); // no test
  for(byte row = 1; row <= 8; row++) {
    sendMax(row, 0); // turn all LEDs off
  }
  sendMax(MAX_INT, 0x0f); // max intensity
}

void setup() {
  pinMode(MAX_DIN, OUTPUT);
  pinMode(MAX_CS , OUTPUT);
  pinMode(MAX_CLK, OUTPUT);
  
  // delay para inicializacao do MAX
  // evita problemas ao ligar, tirando necessidade de reset
  delay(500);
  
  maxInit();
}

void loop() {
  /*sendMax(1,0b00000000);
  sendMax(2,0b00011000);
  sendMax(3,0b00011000);
  sendMax(4,0b00000110);
  sendMax(5,0b00000110);
  sendMax(6,0b01111110);
  sendMax(7,0b01111110);
  sendMax(8,0b00000000);
  
  delay(ANIM_DLY);
  
  sendMax(1,0b00000000);
  sendMax(2,0b01100110);
  sendMax(3,0b01100110);
  sendMax(4,0b00011110);
  sendMax(5,0b00011110);
  sendMax(6,0b00011000);
  sendMax(7,0b00011000);
  sendMax(8,0b00000000);
  
  delay(ANIM_DLY);
  
  sendMax(1,0b00000000);
  sendMax(2,0b00000110);
  sendMax(3,0b00000110);
  sendMax(4,0b01100110);
  sendMax(5,0b01100110);
  sendMax(6,0b00011110);
  sendMax(7,0b00011110);
  sendMax(8,0b00000000);
  
  delay(ANIM_DLY);
  
  sendMax(1,0b00000000);
  sendMax(2,0b01100000);
  sendMax(3,0b01100000);
  sendMax(4,0b00011110);
  sendMax(5,0b00011110);
  sendMax(6,0b01111000);
  sendMax(7,0b01111000);
  sendMax(8,0b00000000);
  
  delay(ANIM_DLY);*/
  
  sendMax(1,0b00000000);
  sendMax(2,0b00011110);
  sendMax(3,0b00011110);
  sendMax(4,0b01100110);
  sendMax(5,0b01100110);
  sendMax(6,0b00000110);
  sendMax(7,0b00000110);
  sendMax(8,0b00000000);
  
  delay(ANIM_DLY);
  
  sendMax(1,0b00000000);
  sendMax(2,0b01111000);
  sendMax(3,0b01111000);
  sendMax(4,0b00011110);
  sendMax(5,0b00011110);
  sendMax(6,0b01100000);
  sendMax(7,0b01100000);
  sendMax(8,0b00000000);
  
  delay(ANIM_DLY);
  
  sendMax(1,0b00000000);
  sendMax(2,0b01111110);
  sendMax(3,0b01111110);
  sendMax(4,0b00000110);
  sendMax(5,0b00000110);
  sendMax(6,0b00011000);
  sendMax(7,0b00011000);
  sendMax(8,0b00000000);
  
  delay(ANIM_DLY);
  
  sendMax(1,0b00000000);
  sendMax(2,0b00011000);
  sendMax(3,0b00011000);
  sendMax(4,0b00011110);
  sendMax(5,0b00011110);
  sendMax(6,0b01100110);
  sendMax(7,0b01100110);
  sendMax(8,0b00000000);
  
  delay(ANIM_DLY);
}
