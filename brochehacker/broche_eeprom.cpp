#include "broche_eeprom.h"
#include "broche_display.h"
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
  pinMode(translatePin(rows[4]), OUTPUT);
  pinMode(translatePin(cols[4]), OUTPUT);
  digitalWrite(translatePin(rows[4]), CATLOW); // 4,4 on
  digitalWrite(translatePin(cols[4]), CATHIGH);
  delay(500);
  digitalWrite(translatePin(cols[4]), CATLOW);
  
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
      case 'A': // anim1
        while(Serial.available() < 1) {}
        store->anim1Frames = Serial.read();
        if(store->anim1Frames > 15) store->anim1Frames = 15;
        while(Serial.available() < 1) {}
        store->anim1Speed = Serial.read();
        Serial.readBytes(store->anim1Data, store->anim1Frames * 8);
        store->anim1Speed = 255 - store->anim1Speed; // inverse so 1 is slowest
        Serial.print(store->anim1Frames);
        Serial.print(" ");
        Serial.println(store->anim1Speed);
        Serial.println("Anim1 OK");
        break;
      case 'S': // save to eeprom
        saveEEPROM();
        Serial.println("Save OK");
        break;
      case 'D': // dump eeprom
        Serial.print("D");
        Serial.write(store->anim1Frames);
        Serial.write(store->anim1Speed);
        Serial.write((byte)strlen(store->userMessage));
        Serial.write(store->anim1Data, store->anim1Frames * 8);
        Serial.write(store->userMessage);
        Serial.print("\r\n");
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

