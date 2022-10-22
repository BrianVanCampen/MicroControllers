

//logica van groen naar rood
  /*
  // portD
  PORTD = 0B00010000;
  delay(1000);    
  PORTD = 0B00000000; 
  PORTD = 0B00100000;
  delay(1000);
  PORTD = 0B00000000; 
  PORTD = 0B01000000;
  delay(1000);
  PORTD = 0B00000000;
  PORTD = 0B10000000;
  delay(1000);
  PORTD = 0B00000000;
  PORTB = 0B00000001;
  delay(1000);
  PORTB = 0B00000000;
  PORTB = 0B00000010;
  delay(1000);
  PORTB = 0B00000000;
  PORTB = 0B00000100;
  delay(1000);
  PORTB = 0B00000000;
  PORTB = 0B00001000;
  delay(1000);
  PORTB = 0B00000000;
  PORTB = 0B00010000;
  delay(1000);
  PORTB = 0B00000000;
  

*/
int i = 0;

void setup() {
  DDRB |= B00011111; // Initialisatie led 1-5
  DDRD |= B11110000; // Initialisatie led 6-9
  DDRC |= B00000000; // Initialisatie knoppen
}

void loop() {
  if (i < 4) PORTD |= (B00010000 << i); // Led 1-5 aansturen
  
  if (i >= 4) PORTB |= (B00000001 << i-4); // Led 6-9 aansturen

  if (PINC & B00000001 && i < 8) {
    delay(200);
    PORTD &= !(B00010000 << i); // Led 1-5 resetten
    PORTB &= !(B00000001 << i-4); // Led 6-9 resetten
    i++;
  }
  
  if (PINC & B00000010 && i > 0) {
    delay(200);
    PORTD &= !(B00010000 << i); // Led 1-5 resetten
    PORTB &= !(B00000001 << i-4); // Led 6-9 resetten
    i--;
  }
}
