const int ledPin1 = 9;    // Pin voor de eerste LED
const int ledPin2 = 10;   // Pin voor de tweede LED
const int upButtonPin = 2;     // Pin voor de "Omhoog" knop
const int downButtonPin = 3;   // Pin voor de "Omlaag" knop
const int toggleButtonPin = 4; // Pin voor de "Toggle" knop

volatile int intensity1 = 0;   // Intensiteit van de eerste LED
volatile int intensity2 = 0;   // Intensiteit van de tweede LED
volatile bool selectedLED = false; // Welke LED is geselecteerd

void setup() {
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(upButtonPin, INPUT_PULLUP);
  pinMode(downButtonPin, INPUT_PULLUP);
  pinMode(toggleButtonPin, INPUT_PULLUP);

  // Configureer interrupts voor de "Omhoog" en "Omlaag" knoppen
  attachInterrupt(digitalPinToInterrupt(upButtonPin), increaseIntensity, FALLING);
  attachInterrupt(digitalPinToInterrupt(downButtonPin), decreaseIntensity, FALLING);
}

void loop() {
  // Lees de status van de toggle-knop
  bool toggleState = digitalRead(toggleButtonPin);

  // Bepaal welke LED geselecteerd is
  if (toggleState) {
    selectedLED = !selectedLED;
  }

  // Update de intensiteit van de geselecteerde LED
  if (selectedLED) {
    analogWrite(ledPin1, intensity1);
    analogWrite(ledPin2, 0); // Zet de tweede LED uit
  } else {
    analogWrite(ledPin1, 0); // Zet de eerste LED uit
    analogWrite(ledPin2, intensity2);
  }
}

void increaseIntensity() {
  if (selectedLED) {
    intensity1 = min(intensity1 + 10, 255); // Verhoog intensiteit van LED1
  } else {
    intensity2 = min(intensity2 + 10, 255); // Verhoog intensiteit van LED2
  }
}

void decreaseIntensity() {
  if (selectedLED) {
    intensity1 = max(intensity1 - 10, 0); // Verlaag intensiteit van LED1
  } else {
    intensity2 = max(intensity2 - 10, 0); // Verlaag intensiteit van LED2
  }
}
