#include <Wire.h>
#include <Servo.h>

Servo servo;

int ser = 9;

void setup() {
  servo.attach(ser);
  Wire.begin();   
}

void loop() {
  Wire.requestFrom(8, 1);     
    while (Wire.available()) {
      int c = Wire.read();
      servo.write(c);
  }
  delay(100);
}
