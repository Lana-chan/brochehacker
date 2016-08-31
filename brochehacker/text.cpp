#include "text.h"
#include "display.h"

boolean textInit = true;
char msg[] = "This is a test text this is another test text! ";

byte textX;           // x position scrolling
byte textPos;         // message character position
byte textCycle;       // cycle count
byte textDelay = 8;  // number of cycles between frames
char lookup[256];     // lookup table

void initializeText() {
  int i;
  for (i = 0; i < 256; i++)
    lookup[i] = 0;
  for (i = 0; charmap[i]; i++)
    lookup[charmap[i]] = i;
}

void runText() {
  if(textInit) {
    textInit = false;
    textX = 0;
    textPos = 0;
    textCycle = 0;

    initializeText();
  }

  textCycle++;
  if(textCycle >= textDelay) {
    for(byte i = 0; i < 8; i++) {
      // for each line in screen, scroll it left
      screen[i] <<= 1;
      // fill rightmost column with next next letter
      screen[i] |= (pgm_read_byte_near(charset + lookup[msg[textPos]]*8 + i) >> 7-textX) & 0x01;
    }
    textX++;
    if(textX >= 6) {
      textX = 0;
      textPos++;
      if(msg[textPos] == 0) textPos = 0;
    }
    textCycle = 0;
  }
}

