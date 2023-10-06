const int ledpin = PB0;//verbonden met pin 5 van ATTINY 
const int buttonUP = PB1;//verbonden met pin 6 van ATTINY
const int buttonDOWN = PB2;//verbonden met pin 7 van ATTINY
volatile int i=0;


void setup() {
  // put your setup code here, to run once:
  pinMode(ledpin, OUTPUT);
  pinMode(buttonUP, INPUT);
  pinMode(buttonDOWN, INPUT);
  Serial.begin(9600); 

}

void loop() {
  // put your main code here, to run repeatedly:

    analogWrite(ledpin, i);

    if (digitalRead(buttonUP) && i < 255){
      i++;//meer licht
      //i=i+10;

    }  
    if(digitalRead(buttonDOWN) && i > 0){
      i--;//minder licht
      //i=i-10;
    }
    delay(10);
    Serial.println("Led licht: ");
    Serial.println(i);
    analogWrite(ledpin,i);


}
