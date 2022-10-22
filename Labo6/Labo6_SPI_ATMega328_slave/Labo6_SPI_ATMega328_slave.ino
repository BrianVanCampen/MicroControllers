#include <Servo.h>
#include <SPI.h>

Servo myservo;

volatile boolean ss;
volatile byte rx;
volatile byte tx=0x0; 

void setup() {
    SPCR |= _BV(SPE);
    ss = false;
    SPI.attachInterrupt();

    pinMode(10, OUTPUT);
    Serial.begin(9600);
    myservo.attach(9);
}

ISR (SPI_STC_vect) {
  rx = SPDR;
  ss = true; 
}

void loop() {
  
  tx=0x00;     
  SPDR = tx;

  tx++;
  if (tx>254) tx=0;

  
  if (ss) { 
    Serial.println(rx);
    myservo.write(rx);
    delay(15);
   
  }

}
