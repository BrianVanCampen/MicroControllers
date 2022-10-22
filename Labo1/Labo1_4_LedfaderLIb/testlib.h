#ifndef tl
#define tl

#include "Arduino.h"



class fader{
  
  public:
  fader(int pin);
  void fadein();
  void fadeout();
  private: 
  int _pin;
  };





#endif
