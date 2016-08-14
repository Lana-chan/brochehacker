#include "tetris.h"

static byte board[8] = {0,2,0,0,0,0,0,0};
static byte sprite[8] = {0,0,0,0,0,0,0,0};

const byte MIDDLE = 2;
byte block;
byte orientation;
char x = MIDDLE; // signedness
char y;

// outputs both board and sprite muxed into screen
void blitScreen() {
  for(byte i = 0; i < 8; i++)
    screen[i] = board[i] | sprite[i];
}

// makes sprite be a single block at x and y
void blitSprite() {
  memset(sprite,0,8);
  byte offset = block*8 + orientation*2;
  char _y = y-1;
  if(++_y >= 0) sprite[_y] = (blocks[offset]        & 0b11110000);
  if(++_y >= 0) sprite[_y] = (blocks[offset]<<4     & 0b11110000);
  if(++_y >= 0) sprite[_y] = (blocks[offset + 1]    & 0b11110000);
  if(++_y >= 0) sprite[_y] = (blocks[offset + 1]<<4 & 0b11110000);
  for(byte i = 0; i < 4; i++) {
    _y = y+i;
    if(_y >= 0) {
      if(x < 0) sprite[_y]<<=-x;
      else sprite[_y]>>=x;
    }
  }
}

// --- collision routines

//checks if piece can go left
boolean checkLeft() {
  for(byte i = 0; i < 4; i++)
    if(sprite[i+y] & 0b10000000) return false;
  if(checkCollision(-1)) return false;
  return true;
}

//checks if piece can go right
boolean checkRight() {
  for(byte i = 0; i < 4; i++)
    if(sprite[i+y] & 0b00000001) return false;
  if(checkCollision(1)) return false;
  return true;
}

// checks for board collision
boolean checkCollision() { // default to no offset
  return checkCollision(0);
}
boolean checkCollision(char offset) {
  byte _y;
  for(byte i = 0; i < 4; i++) {
    _y = i+y;
    if(offset < 0) {
      if(sprite[_y]<<-offset & board[_y]) return true;
    } else {
      if(sprite[_y]>>offset & board[_y]) return true;
    }
  }
  return false;
}

// ---

// initializes tetris variables
void startTetris() {
  state = ST_TETRIS;
}

// loop function for tetris
void runTetris() {
  byte btn = buttonState();
  if(btn & BUTTON_1) { // move left
    if(checkLeft()) x--;
  } else if(btn & BUTTON_2) { // move right
    if(checkRight()) x++;
  } else if(btn & BUTTON_4) {
    orientation++;
    if(orientation >= 4) {
      orientation = 0;
      block++;
      if(block >= 7) block = 0;
    }
    x = MIDDLE;
    y = 0;
  }
  
  blitSprite();
  blitScreen();
}

