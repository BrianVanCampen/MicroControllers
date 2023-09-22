const int trimmerPinD9 = A0; // Trimmeer op A0 voor D9
const int trimmerPinD10 = A1; // Trimmeer op A1 voor D10
const int pwmPinD9 = 9; // PWM-uitgang D9
const int pwmPinD10 = 10; // PWM-uitgang D10

void setup() {
  pinMode(pwmPinD9, OUTPUT);
  pinMode(pwmPinD10, OUTPUT);
}

void loop() {
  // Lees de analoge waarden van de trimmers (0-1023) en converteer naar een duty cycle (0-255).
  int dutyCycleD9 = map(analogRead(trimmerPinD9), 0, 1023, 0, 255);
  int dutyCycleD10 = map(analogRead(trimmerPinD10), 0, 1023, 0, 255);

  // Stel de duty cycles in voor D9 en D10.
  analogWrite(pwmPinD9, dutyCycleD9);
  analogWrite(pwmPinD10, dutyCycleD10);

  // Voeg hier code toe om de frequentie te meten en weer te geven op de seriële monitor.
}