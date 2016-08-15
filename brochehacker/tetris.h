#pragma once
#ifndef TETRIS_H_   /* Include guard */
#define TETRIS_H_

#include "display.h"

const byte blocks[] = {
  0b01000100, // |
  0b01000100,
  0b00001111, // _
  0b00000000,
  0b00100010, // |
  0b00100010,
  0b00000000, // _
  0b11110000,

  0b01001110, // T
  0b00000000,
  0b01000110, // <
  0b01000000,
  0b00001110, // ^
  0b01000000,
  0b01001100, // >
  0b01000000,
  
  0b00000110, // []
  0b01100000,
  0b00000110,
  0b01100000,
  0b00000110,
  0b01100000,
  0b00000110,
  0b01100000,

  0b11000100, // L
  0b01000000,
  0b00101110,
  0b00000000,
  0b01000100,
  0b01100000,
  0b00001110,
  0b10000000,

  0b01100100, // J
  0b01000000,
  0b00001110,
  0b00100000,
  0b01000100,
  0b11000000,
  0b10001110,
  0b00000000,

  0b01000110, // S
  0b00100000,
  0b00000110,
  0b11000000,
  0b10001100,
  0b01000000,
  0b01101100,
  0b00000000,

  0b00100110, // Z
  0b01000000,
  0b00001100,
  0b01100000,
  0b01001100,
  0b10000000,
  0b11000110,
  0b00000000
};

boolean checkSidewaysCollision();
boolean checkSidewaysCollision(char offset);
boolean checkBottomCollision();
void blitScreen();
void blitSprite();
void startTetris();
void runTetris();

#endif // TETRIS_H_