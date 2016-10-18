#include "broche_eeprom.h"
#include <EEPROM.h>

// todo:
// - AnimationStorage must be stored in 512byte EEPROM
// - serial interface for replacing animations and text from external device


void saveEEPROM() {
  // save AnimationStorage into eeprom
}

void loadEEPROM() {
  // loads eeprom contents into AnimationStorage. likely only called during boot
}
