char inputString[64];  
boolean stringComplete = false;  // Een vlag om aan te geven of de tekst compleet is ontvangen

void setup() {
  Serial.begin(9600); 
}

void loop() {
  while (Serial.available()) {
    char inChar = Serial.read(); 
    int strLen = strlen(inputString);

    if (inChar == '\n') {
      inputString[strLen] = '\0';  
      stringComplete = true; 
      break;
    }
    
    
    
    if (strLen < 63) { 
      inputString[strLen] = inChar;
      inputString[strLen + 1] = '\0'; 
    }
  }
  
  if (stringComplete) {
    //wait 2 sec
    delay(3000);
    
    // Stuur de ontvangen tekst terug naar de terminal
    Serial.println("Ontvangen tekst: ");
    Serial.println(inputString);
    
    // Reset de buffer en vlag
    inputString[0] = '\0';
    stringComplete = false;
  }
}
