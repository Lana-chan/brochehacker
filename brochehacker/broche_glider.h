#pragma once

#ifndef GLIDER_H_   /* Include guard */
#define GLIDER_H_

/*
 * glider animation
 */

#include "broche_display.h"

const byte FRAMES = 4;
const byte anim[] = {
  B00000000,
  B00011000,
  B00011000,
  B00000110,
  B00000110,
  B01111110,
  B01111110,
  B00000000,
  
  B00000000,
  B01100110,
  B01100110,
  B00011110,
  B00011110,
  B00011000,
  B00011000,
  B00000000,
  
  B00000000,
  B00000110,
  B00000110,
  B01100110,
  B01100110,
  B00011110,
  B00011110,
  B00000000,
  
  B00000000,
  B01100000,
  B01100000,
  B00011110,
  B00011110,
  B01111000,
  B01111000,
  B00000000
};

void runGlider();

#endif // GLIDER_H_
