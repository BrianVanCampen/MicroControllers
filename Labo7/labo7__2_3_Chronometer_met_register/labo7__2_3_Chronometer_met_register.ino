byte getal[] {
  B00111111, // Getal 0
  B00000110, // Getal 1
  B01011011, // Getal 2
  B01001111, // Getal 3
  B01100110, // Getal 4
  B01101101, // Getal 5
  B01111101, // Getal 6
  B00000111, // Getal 7
  B01111111, // Getal 8
  B01101111, // Getal 9
};

int tel = 0;
bool start = false;

void setup() {
  DDRB |= B00001111; // Initialisatie cathodes en knoppen
  DDRC |= B01111111; // Initialisatie anodes
}

void loop() {
  int teller[4] = {tel % 10, tel / 10 % 10, tel / 100 % 10, tel / 1000 % 10}; // Getal berekenen voor elke cathode

  if (PINB & B00010000) start = !start; // Timer start/stoppen
  if (PINB & B00100000) tel = 0; // Timer resetten
  if (tel != 9999 && start) tel++; // Timer optellen

  for (byte i = 0; i < 4; i++) { // Loopen door cathodes
    PORTB |= B00001111; // Cathodes resetten
    PORTB &= ~(B00001000 >> i); // Cathode aanzetten
    PORTC |= getal[teller[i]]; // Nodige anodes aanzetten voor getal
    delay(1);
    PORTC &= ~(getal[teller[i]]); // Anodes uitzetten
  }
}
