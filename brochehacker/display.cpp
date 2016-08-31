#include "display.h"

byte state = ST_GLIDER;
byte screen[8] = {0, 0, 0, 0, 0, 0, 0, 0};

byte translatePin(byte original) {
  return pins[original - 1];
}

// copy animation frame to screen
void drawFrame(int address) {
  memcpy(&screen, (void*)address, 8);
}

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
  return bstate | blatch<<4;
}

// interrupt routine
void doubleBuffer() {
  static byte screenRow = 0;
  static byte screenCol = 0;
  // reset the previous iteration
  digitalWrite(translatePin(rows[screenRow]), LOW); // set previous off
  digitalWrite(translatePin(cols[screenCol]), HIGH);  // set previous off
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
    digitalWrite(translatePin(rows[screenRow]), HIGH);  // set this on
    digitalWrite(translatePin(cols[screenCol]), LOW); // set this on
  } else {
    digitalWrite(translatePin(rows[screenRow]), LOW); // set this off
    digitalWrite(translatePin(cols[screenCol]), HIGH);  // set this off
  }
}
