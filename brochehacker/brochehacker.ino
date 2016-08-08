/*
 * _8x8 LED matrix
 *
 * (c) 2009 BlushingBoy.net
 */

#include "TimerOne.h"

byte rows[8] = {9, 14, 8, 12, 1, 7, 2, 5};
byte cols[8] = {13, 3, 4, 10, 6, 11, 15, 16};
byte pins[16] = {0, 1, 2, 3, 5, 6, 7, 8, 9, 10, 14, 15, 16, 17, 18, 19};
byte screen[8] = {0, 0, 0, 0, 0, 0, 0, 0};
volatile byte screenRow = 0;
volatile byte screenCol = 0;

void setup() {
  Timer1.initialize(100);
  for (int i = 0; i <= 19; i++)
    pinMode(i, OUTPUT);
  Timer1.attachInterrupt(doubleBuffer);
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
  if((screen[screenRow]>>screenCol)&B1 == B1) {
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

// looping some LEDs routine
void loop() {
  allOFF();
  screen[0] = B00000000;
  screen[1] = B00011000;
  screen[2] = B00011000;
  screen[3] = B00000110;
  screen[4] = B00000110;
  screen[5] = B01111110;
  screen[6] = B01111110;
  screen[7] = B00000000;
  delay(600);
  allOFF();
  screen[0] = B00000000;
  screen[1] = B00011110;
  screen[2] = B00011110;
  screen[3] = B01100110;
  screen[4] = B01100110;
  screen[5] = B00000110;
  screen[6] = B00000110;
  screen[7] = B00000000;
  delay(600);
}
