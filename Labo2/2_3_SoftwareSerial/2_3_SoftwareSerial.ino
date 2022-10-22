// Gewerkt met Sten Hulsbergen
#include <SoftwareSerial.h>

SoftwareSerial mySerial(5, 6); // RX, TX

int trimmer = A0;
int led = 9;

void setup() {
  Serial.begin(57600);
  mySerial.begin(57600);

  pinMode(trimmer, INPUT);
  pinMode(led, OUTPUT);

  while (!Serial) {
  }
}

void loop() {
  int waardeTrimmer = analogRead(trimmer);
  waardeTrimmer = map(waardeTrimmer, 0, 1023, 0, 255);

  Serial.println("OUTPUT: " + String(waardeTrimmer));
  mySerial.write(waardeTrimmer);

  int waardeTrimmerSerial = mySerial.read();
  Serial.println("INPUT: " + String(waardeTrimmerSerial));

  analogWrite(led, waardeTrimmerSerial);
}
