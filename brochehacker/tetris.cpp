#include "tetris.h"

static byte board[11] = {0,0,0,0,0,0,0,0,0,0,0};
static byte sprite[11] = {0,0,0,0,0,0,0,0,0,0,0};

const byte MIDDLE = 2;
byte fallCycles = 50;
boolean initTetris = true;

byte cycle;
byte block;
byte orientation;
char x; // char for signedness
char y;

// outputs both board and sprite muxed into screen
void blitScreen() {
  for(byte i = 3; i < 11; i++)
    screen[i-3] = board[i] | sprite[i];
}

// makes sprite be a single block at x and y
void blitSprite() {
  memset(sprite,0,8);
  byte offset = block*8 + orientation*2;
  char _y = y-1;
  sprite[++_y] = (blocks[offset]        & 0b11110000);
  sprite[++_y] = (blocks[offset]<<4     & 0b11110000);
  sprite[++_y] = (blocks[offset + 1]    & 0b11110000);
  sprite[++_y] = (blocks[offset + 1]<<4 & 0b11110000);
  for(byte i = 0; i < 4; i++) {
    _y = y+i;
    if(x < 0) sprite[_y]<<=-x;
    else sprite[_y]>>=x;
  }
  
  blitScreen();
}

// --- collision routines

//checks if piece can go left (false if collides)
boolean checkLeft() {
  for(byte i = 0; i < 4; i++)
    if(sprite[i+y] & 0b10000000) return false;
  if(checkSidewaysCollision(-1)) return false;
  return true;
}

//checks if piece can go right (false if collides)
boolean checkRight() {
  for(byte i = 0; i < 4; i++)
    if(sprite[i+y] & 0b00000001) return false;
  if(checkSidewaysCollision(1)) return false;
  return true;
}

// checks for board collision (true if collides)
boolean checkSidewaysCollision() { // default to no offset
  return checkSidewaysCollision(0);
}
boolean checkSidewaysCollision(char offset) {
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

// checks collision if block goes one down (true if collides)
boolean checkBottomCollision() {
  if(sprite[11] & 0b11111111) return true;
  byte _y;
  for(byte i = 0; i < 4; i++) {
    _y = i+y;
    if(sprite[_y-1] & board[_y]) return true;
  }
}

// check if block can rotate (false if collides)
boolean checkRotation() {
  byte oldOrientation = orientation;
  orientation++;
  if(orientation >= 4) orientation = 0;
  blitSprite();
  boolean result = checkSidewaysCollision();
  // TODO: check if out of bounds (how??)
  orientation = oldOrientation;
  blitSprite();
  return !result;
}

// ---

// commit block to board and spawn a new block
void newBlock() {
  for(byte i = 0; i < 11; i++)
    board[i] |= sprite[i];

  block = random(6);
  orientation = 0;
  x = MIDDLE;
  y = 0;
  blitSprite();
}

// loop function for tetris
void runTetris() {
  // init variables - new game
  if(initTetris) {
    initTetris = false;
    cycle = 0;
    newBlock();
    memset(board,0,8);
  }
  
  byte btn = buttonState();
  if(btn & BUTTON_1) { // move left
    if(checkLeft()) {
      x--;
      blitSprite();
    }
  } else if(btn & BUTTON_2) { // move right
    if(checkRight()) {
      x++;
      blitSprite();
    }
  } else if(btn & BUTTON_4) { // rotate
    if(checkRotation()) {
      orientation++;
      if(orientation >= 4) orientation = 0;
      blitSprite();
    }
  }

  cycle++;
  if(cycle >= fallCycles) {
    cycle = 0;
    if(checkBottomCollision()) {
      newBlock();
    } else {
      y++;
      blitSprite();
    }
  }
}

