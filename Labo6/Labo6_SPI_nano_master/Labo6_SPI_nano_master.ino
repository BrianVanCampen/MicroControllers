#include <SPI.h>

byte rx;
byte tx=0x00;

byte ss=10; // slave select lijn

void setup() {
  pinMode(ss, OUTPUT);
  digitalWrite(ss, HIGH);

  SPI.begin(); 
  SPI.beginTransaction(SPISettings(20000, MSBFIRST, SPI_MODE0));

  tx=0x0;
}

void loop() {
    tx= analogRead(A0)/4;
    digitalWrite(ss,LOW);   // slave selecteren
    SPI.transfer(tx);
    delay(1);
    digitalWrite(ss,HIGH);  // slave release
    delay(100);
}
