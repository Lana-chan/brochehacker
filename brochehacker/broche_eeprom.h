#pragma once

#ifndef EEPROM_H_   /* Include guard */
#define EEPROM_H_

/*
 * code for eeprom storage and serial mode
 */
 
#include "Arduino.h"

// storage for the 512b eeprom
typedef struct AnimationStorage {
  byte anim1Frames;    // number of frames in animation
  byte anim1Speed;     // speed of animation
  byte anim1Data[120]; // 120 / 8 = 15 frames of animation

  byte anim2Frames;    // number of frames in animation
  byte anim2Speed;     // speed of animation
  byte anim2Data[120]; // 120 / 8 = 15 frames of animation
  
  char userMessage[140]; // 140 characters of text. it's a tweet, folks
  
  // 122 + 122 + 140 = 384 bytes !
} AnimationStorage;

extern AnimationStorage* store;

void loadEEPROM();
void saveEEPROM();
void setupSerial();
void loopSerial();

#endif // EEPROM_H_
