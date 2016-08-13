#include "tetris.h"

static byte board[8] = {0,0,0,0,0,0,0,0};
static byte sprite[8] = {0,0,0,0,0,0,0,0};  

// outputs both board and sprite muxed into screen
void blitScreen() {
  for(byte i = 0; i < 8; i++)
    screen[i] = board[i] | sprite[i];
}

// makes sprite be a single block at x and y
void blitSprite(byte block, byte orientation, byte x, byte y) {
  memset(sprite,0,8);
  byte offset = block*8 + orientation*2;
  sprite[y]   = (blocks[offset]        & 0b11110000)>>x;
  sprite[y+1] = (blocks[offset]<<4     & 0b11110000)>>x;
  sprite[y+2] = (blocks[offset + 1]    & 0b11110000)>>x;
  sprite[y+3] = (blocks[offset + 1]<<4 & 0b11110000)>>x;
}

// initializes tetris variables
void startTetris() {
  state = ST_TETRIS;
}

// loop function for tetris
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

