#include "broche_glider.h"

// glider is the animation code for the badge
// named for its original animation code which presented a game of life glider

// hacker anim loop
void runGlider() {
  static byte animFrame = 0;
  static byte cycleCount = 0;
  
  cycleCount++;
  if(cycleCount >= store.anim1Speed) {
    cycleCount = 0;
    animFrame++;
    if(animFrame >= store.anim1Frames) animFrame = 0;
    // drawFrame(&anim[animFrame*8]);
    for(byte i = 0; i < 8; i++)
      screen[i] = store.anim1Data[animFrame*8+i];
  }
  byte btn = buttonState();
  if(btn & BUTTON_1) {
    // replace calls to store to an arbitrary call
    // this sets the arbitrary call to anim1
    //initAnim1();
  } else if(btn & BUTTON_2) {
    // this sets the arbitrary call to anim2
    //initAnim2();
  } else if(btn & BUTTON_3) {
    state = ST_TETRIS;
  } else if(btn & BUTTON_4) {
    state = ST_TEXT;
  }
}
