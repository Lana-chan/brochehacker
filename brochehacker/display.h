/*
 * display and buttons
 * globals
 */
 
#include "Arduino.h"

#ifndef DISPLAY_H_   /* Include guard */
#define DISPLAY_H_

const byte DELAY = 10;
const byte ST_HACKER = 0;
const byte ST_TETRIS = 1;
byte state = ST_HACKER;

const byte button[4] = {4, 12, 11, 13};
const byte BUTTON_1 = 0b0001;
const byte BUTTON_2 = 0b0010;
const byte BUTTON_3 = 0b0100;
const byte BUTTON_4 = 0b1000;
const byte HELD_1 = 0b00010000;
const byte HELD_2 = 0b00100000;
const byte HELD_3 = 0b01000000;
const byte HELD_4 = 0b10000000;

const byte rows[8] = {9, 14, 8, 12, 1, 7, 2, 5};
const byte cols[8] = {13, 3, 4, 10, 6, 11, 15, 16};
const byte pins[16] = {0, 1, 2, 3, 5, 6, 7, 8, 9, 10, 14, 15, 16, 17, 18, 19};
byte screen[8] = {0, 0, 0, 0, 0, 0, 0, 0};
volatile byte screenRow = 0;
volatile byte screenCol = 0;

byte translatePin(byte original);
void drawFrame(byte frame);
void doubleBuffer();
byte buttonState();

#endif // DISPLAY_H_
