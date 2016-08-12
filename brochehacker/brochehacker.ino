/*
 * Broche Hacker Firmware
 * by Lana-chan
 *
 * LED driver code (c) 2009 BlushingBoy.net
 */

#include "TimerOne.h"
#include "display.h"
#include "glider.h"
#include "tetris.h"

void setup() {
  Timer1.initialize(200);
  for (int i = 0; i < 16; i++)
    pinMode(pins[i], OUTPUT);
  for (int i = 0; i < 4; i++)
    pinMode(button[i], INPUT_PULLUP);
  Timer1.attachInterrupt(doubleBuffer);
  //Serial.begin(9600);
}

/* ---- high level screen functions
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
// ---- */

// main loop
void loop() {
  if(state == ST_GLIDER) runGlider();
  else if(state == ST_TETRIS) runTetris();
  delay(DELAY);
}
