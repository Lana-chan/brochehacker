#include "tetris.h"

void blitScreen() {
  for(byte i = 0; i < 8; i++)
    screen[i] = board[i] | sprite[i];
}

void blitSprite(byte block, byte orientation, byte x, byte y) {
  for(byte i = 0; i < 4; i++) {
    sprite[i+y]   = (blocks[block*4 + orientation]     & 0b11110000)>>x;
    sprite[i+y+1] = (blocks[block*4 + orientation]     & 0b00001111)>>x;
    sprite[i+y+2] = (blocks[block*4 + orientation + 1] & 0b11110000)>>x;
    sprite[i+y+3] = (blocks[block*4 + orientation + 1] & 0b00001111)>>x;
  }
}

void startTetris() {
  state = 1;
}

void runTetris() {
  static byte block;
  static byte orientation;
  static byte x;
  static byte y;

  byte btn = buttonState();
  if(btn & BUTTON_1) {
    if(x < 4) x++;
  } else if(btn & BUTTON_2) {
    if(y < 4) y++;
  } else if(btn & BUTTON_4) {
    orientation++;
    if(orientation >= 4) {
      orientation = 0;
      block++;
      if(block >= 7) block = 0;
    }
    x = 0;
    y = 0;
  }
  
  blitSprite(block, orientation, x, y);
  blitScreen();
}

