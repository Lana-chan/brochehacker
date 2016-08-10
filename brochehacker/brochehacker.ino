/*
 * Broche Hacker Firmware
 * by Lana-chan
 *
 * LED driver code (c) 2009 BlushingBoy.net
 */

#include "TimerOne.h"

const byte DELAY = 10;
const byte ST_HACKER = 0;
const byte ST_TETRIS = 1;

const byte BUTTON_1 = B0001;
const byte BUTTON_2 = B0010;
const byte BUTTON_3 = B0100;
const byte BUTTON_4 = B1000;

const byte rows[8] = {9, 14, 8, 12, 1, 7, 2, 5};
const byte cols[8] = {13, 3, 4, 10, 6, 11, 15, 16};
const byte pins[16] = {0, 1, 2, 3, 5, 6, 7, 8, 9, 10, 14, 15, 16, 17, 18, 19};
byte screen[8] = {0, 0, 0, 0, 0, 0, 0, 0};
volatile byte screenRow = 0;
volatile byte screenCol = 0;

const byte button[4] = {4, 12, 11, 13};
byte state = ST_HACKER;

const byte FRAMES = 4;
const byte anim[] = {
  B00000000,
  B00011000,
  B00011000,
  B00000110,
  B00000110,
  B01111110,
  B01111110,
  B00000000,
  
  B00000000,
  B01100110,
  B01100110,
  B00011110,
  B00011110,
  B00011000,
  B00011000,
  B00000000,
  
  B00000000,
  B00000110,
  B00000110,
  B01100110,
  B01100110,
  B00011110,
  B00011110,
  B00000000,
  
  B00000000,
  B01100000,
  B01100000,
  B00011110,
  B00011110,
  B01111000,
  B01111000,
  B00000000
};

void setup() {
  Timer1.initialize(100);
  for (int i = 0; i < 16; i++)
    pinMode(pins[i], OUTPUT);
  for (int i = 0; i < 4; i++)
    pinMode(button[i], INPUT_PULLUP);
  Timer1.attachInterrupt(doubleBuffer);
  //Serial.begin(9600);
}

// interrupt routine
void doubleBuffer() {
  // reset the previous iteration
  digitalWrite(translatePin(rows[screenRow]), HIGH); // set previous off
  digitalWrite(translatePin(cols[screenCol]), LOW);  // set previous off
  // go to the next iteration...
  // go to the next screenCol, wrap if necessary
  screenCol++;
  if (screenCol >= 8) {
    screenCol = 0;
    // when screenCol wraps, go to the next screenRow, wrap if necessary
    screenRow++;
    if (screenRow >= 8) {
      screenRow = 0;
    }
  }
  // set this iteration
  //if((screen[screenRow]<<8-screenCol)&B1 == B1) {
  if(screen[screenRow] & (B10000000 >> screenCol)) {
    digitalWrite(translatePin(rows[screenRow]), LOW);  // set this on
    digitalWrite(translatePin(cols[screenCol]), HIGH); // set this on
  } else {
    digitalWrite(translatePin(rows[screenRow]), HIGH); // set this off
    digitalWrite(translatePin(cols[screenCol]), LOW);  // set this off
  }
}

byte translatePin(byte original) {
  return pins[original - 1];
}

// ---- high level screen functions
void allOFF() {
  for (int i = 0; i < 8; i++)
    screen[i]=0;
}

void on(byte row, byte column) {
    screen[column-1] |= (B1<<(row-1)); 
}

void off(byte row, byte column) {
    screen[column-1] &= ~(B1<<(row-1)); 
}
// ----

// returns which buttons are being pressed
byte buttonState() {
  byte bstate = 0;
  static byte blatch = 0;
  for(byte i = 0; i < 4; i++) {
    if(digitalRead(button[i]) == LOW && !(blatch & B1<<i)) {
      bstate |= B1<<i;
      blatch |= B1<<i;
    } else if(digitalRead(button[i]) == HIGH && (blatch & B1<<i)) {
      blatch &= ~(B1<<i);
    }
  }
  return bstate;
}

// hacker anim loop
void runHacker() {
  static byte animCycles = 50;
  static byte animFrame = 0;
  static byte cycleCount = 0;
  
  cycleCount++;
  if(cycleCount >= animCycles) {
    cycleCount = 0;
    animFrame++;
    if(animFrame >= FRAMES) animFrame = 0;
    drawFrame(animFrame);
  }
  byte btn = buttonState();
  if(btn & BUTTON_1) {
    animCycles-=10;
  } else if(btn & BUTTON_2) {
    animCycles+=10;
  }
}

// copy animation frame to screen
void drawFrame(byte frame) {
  memcpy(&screen, &anim[frame*8], 8);
}

// main loop
void loop() {
  if(state == ST_HACKER) runHacker();
  delay(DELAY);
}
