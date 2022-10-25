

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
  DDRB = B00011111; // led 1-5 D4 -> D8 worden output
  DDRD = B11110000; // led 6-9 D9 -> D13 worden output 
  DDRC = B00000000; // knoppen op A0 -> A1 worden input
}

void loop() {
  if (i < 4) {
    PORTD |= (B00010000 << i); // Led 1->5 aansturen
    }
  if (i >= 4) {
    PORTB |= (B00000001 << i-4); // Led 6->9 aansturen
    }
    
//1->9
  if (PINC & B00000001 && i < 8) {
    delay(200);
    PORTD &= ~(B00010000 << i); // Led 1->5 uitzetten
    PORTB &= ~(B00000001 << i-4); // Led 6->9 uitzetten
    i++;
  }
//9->1
  if (PINC & B00000010 && i > 0) {
    delay(200);
    PORTD &= ~(B00010000 << i); // Led 1->5 uitzetten
    PORTB &= ~(B00000001 << i-4); // Led 6->9 uitzetten
    i--;
  }
}
