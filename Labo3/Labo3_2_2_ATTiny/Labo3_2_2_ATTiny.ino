const int buttonPin1 = 1;    
const int buttonPin2 = 2; 
const int ledPin =  0;      
volatile int i=0;


void setup() {

  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);

}

void loop() {


analogWrite(ledPin, i);  

if (digitalRead(buttonPin1) && i < 255) i++;
if (digitalRead(buttonPin2) && i > 0) i--;
delay(30);
analogWrite(ledPin, i);
    
    
    
}
