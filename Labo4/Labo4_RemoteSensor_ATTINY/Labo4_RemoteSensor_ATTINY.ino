#include <twi.h>
#include <TinyWire.h>

int trimmer = PB3;

void setup() {
  pinMode(trimmer, INPUT);
  TinyWire.begin(8);                
  TinyWire.onRequest(requestEvent);
}

void loop() {
}

void requestEvent() {
  int a = analogRead(trimmer);
  a = map(a, 0, 1023, 0, 180);
  TinyWire.write(a);
}
