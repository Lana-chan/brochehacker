#include "glider.h"
#include "display.h"

// hacker anim loop
void runHacker() {
  static byte animCycles = 50;
  static byte animFrame = 0;
  static byte cycleCount = 0;
  
  cycleCount++;
  if(cycleCount >= animCycles) {
    cycleCount = 0;
    animFrame++;
    if(animFrame >= FRAMES) animFrame = 0;
    drawFrame(&anim[animFrame*8]);
  }
  byte btn = buttonState();
  if(btn & BUTTON_1) {
    animCycles-=10;
  } else if(btn & BUTTON_2) {
    animCycles+=10;
  } else if(btn & BUTTON_4) {
    state = ST_TETRIS;
  }
}
