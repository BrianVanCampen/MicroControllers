byte Numbers[] { // 0 -> 9
  B00111111, 
  B00000110, 
  B01011011, 
  B01001111, 
  B01100110, 
  B01101101, 
  B01111101,
  B00000111, 
  B01111111, 
  B01101111, 
};

int y = 0;
bool start = false;

void setup() {
  DDRB = B00001111; //  cathodes en knoppen (cathodes output en knoppen als input)
  DDRC = B01111111; //  anodes output van A0 -> RST(PC0 -> PC6) ,A6 zit niet in register 
}

void loop() {
  int Timer[4] = {y % 10, y / 10 % 10, y / 100 % 10, y / 1000 % 10}; // Getal berekenen voor elke cathode 
  //geeft weer wat er op het display komt staan
  // 1ste , 10de , 100ste , 1000ste van een getal modulo gebruiken zodat er geen foute optelling kan gebeuren bv 23 in de 2de spot en telt 3 op bij de 4de   
  
  if (PINB & B00010000){
    start = !start; //button1 = Timer start/stoppen
    } 
  if (PINB & B00100000){
    y = 0; //button2 =  Timer resetten
    } 
  if (y != 9999 && start){
    y++; // Timer optellen
    } 

  for (byte i = 0; i < 4; i++) { // Loopen door cathodes
    PORTB |= B00001111; // Cathodes uit
    PORTB &= ~(B00001000 >> i); // Cathode aan
    PORTC |= Numbers[Timer[i]]; // Nodige anodes aanzetten voor nummer
    delay(1);
    PORTC &= ~(Numbers[Timer[i]]); // Anodes uit
  }
}
