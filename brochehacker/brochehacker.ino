/*
 * Broche Hacker Firmware
 * Licensed under GPLv3
 * http://mynameiser.in/
 */

#include "TimerOne.h"
#include "broche_eeprom.h"
#include "broche_display.h"
#include "broche_glider.h"
#include "broche_tetris.h"
#include "broche_text.h"

void setup() {  
  Timer1.initialize(200);
  for (int i = 0; i < 16; i++)
    pinMode(pins[i], OUTPUT);
  for (int i = 0; i < 4; i++)
    pinMode(button[i], INPUT_PULLUP);
  Timer1.attachInterrupt(doubleBuffer);

  if(digitalRead(button[0]) == LOW) {    // badge turned on with button 1
    delay(500);
    if(digitalRead(button[0]) == LOW) {  // button 1 stayed on for 500ms
      // enter serial mode for programming
    }
  }
}

// main loop
void loop() {
  if(state == ST_GLIDER) runGlider();
  else if(state == ST_TETRIS) runTetris();
  else if(state == ST_TEXT) runText();
  delay(DELAY);
}
