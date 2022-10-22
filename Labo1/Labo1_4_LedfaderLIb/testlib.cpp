#include "testlib.h"


fader::fader(int pin)
{
  pinMode(pin, OUTPUT);
  _pin = pin;
  
}


void fader::fadein()
{
 for (int i = 0; i < 255; i++){ 
    analogWrite(_pin, i); 
    delay(5);
 }
}

void fader::fadeout()
{
for (int i = 255; i > 0; i--){ 
    analogWrite(_pin, i);
    delay(5);
  }
}
