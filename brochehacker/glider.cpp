#include "glider.h"
#include "display.h"

// hacker anim loop
void runGlider() {
  static byte animCycles = 10;
  static byte animFrame = 0;
  static byte cycleCount = 0;
  static byte FRAMES = 8;
  static byte FSTART = 6;
  
  cycleCount++;
  if(cycleCount >= animCycles) {
    cycleCount = 0;
    animFrame++;
    if(animFrame >= FRAMES) animFrame = 0;
    // drawFrame(&anim[animFrame*8]);
    for(byte i = 0; i < 8; i++)
      screen[i] = anim[(animFrame+FSTART)*8+i];
  }
  byte btn = buttonState();
  if(btn & BUTTON_1) {
    animCycles = 40;
    cycleCount = animCycles;
    animFrame = 0;
    FRAMES = 2;
    FSTART = 0;
  } else if(btn & BUTTON_2) {
    animCycles = 40;
    cycleCount = animCycles;
    animFrame = 0;
    FRAMES = 2;
    FSTART = 4;
  } else if(btn & BUTTON_3) {
    animCycles = 10;
    cycleCount = animCycles;
    animFrame = 0;
    FRAMES = 8;
    FSTART = 6;
  } else if(btn & BUTTON_4) {
    state = ST_TETRIS;
  }
}
