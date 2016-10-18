#include "broche_eeprom.h"
#include <EEPROM.h>

// todo:
// - AnimationStorage must be stored in 512byte EEPROM
// - serial interface for replacing animations and text from external device

AnimationStorage *store = (AnimationStorage *) malloc(sizeof(AnimationStorage)); 

// save AnimationStorage into eeprom
void saveEEPROM() {
  EEPROM.put(0, *store);
}

// loads eeprom contents into AnimationStorage. likely only called during boot
void loadEEPROM() {
  EEPROM.get(0, *store);
}

// serial init
void setupSerial() {
  Serial.begin(9600);
}

// serial loop
void loopSerial() {
  Serial.println("Broche Hacker serial interface v0.2b");
  Serial.println("http://mynameiser.in/");
  Serial.println("SERIAL OK");

  byte serialMode = 1;
  char incomingMode;
  while(serialMode == 1) {
    while(Serial.available() < 1) {}
    incomingMode = (char)Serial.read();
    switch(incomingMode) {
      case 'T': // text message
        Serial.readStringUntil(10).toCharArray(store->userMessage, 140);
        Serial.println("Text OK");
        break;
      case 'S': // save to eeprom
        saveEEPROM();
        Serial.println("Save OK");
        break;
      case 'Q': // quit serial mode
        serialMode = 0;
        Serial.println("Quit OK");
        break;
      default:
        // unsupported
      break;
    }
  }
  Serial.end();
}

