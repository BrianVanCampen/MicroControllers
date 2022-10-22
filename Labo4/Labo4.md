# 4.1 I2C

## 4.1.1 Algemeen

In de theorie leerde je reeds wat I2C is, in dit labo gaan we er praktisch mee aan de slag.
Ondertussen weet je ook al iets over de AT-Tiny. Dus we maken meteen de combinatie van de twee.


## 4.1.2 Toevoegen Library

Om I2C te kunnen gebruiken op de AT-Tiny moeten we éérst even een library toevoegen aan de Arduino-IDE.  
Je download deze library van github met deze link:  TinyWire 
Verplaats dit bestand "TinyWire-master.zip" voor de eenvoud even naar je desktop.
Vervolgens start je de Arduino-IDE op en ga je naar sketch en dan include-library .
Hier selecteer je "add .ZIP Library " , klik je vervolgens op "Desktop " en tenslotte op "TinyWire-master.zip"


## 4.1.3 Basics

Zoals beschreven in de theorie is er bij I2C steeds sprake van een master device en slave devices.
Hoe je dat nu juist doet met een Arduino kan je lezen op de onderstaande voorbeelden.

### 4.1.3.1 MasterWriter:
Lees eerst het voorbeeld op de arduino website:  arduino.cc MasterWriter

Bouw nu dit voorbeeld met de AT-Tiny als Master en de  Arduino Nano als slave.
In de .ino code van de AT-Tiny vervang je echter de lijn:

#include <Wire.h>

door de volgende lijntjes:

#include <twi.h>
#include <TinyWire.h>

In de rest van de Tiny code zorg je dat overal waar "Wire" staat je dit vervangt door "TinyWIre" 
Je voegt ook twee 4k7 pull-up weerstanden toe aan de SDA en SCL lijnen.

Met "Slave Receiver" code in de Arduino Nano en de met de "TinyWire" aangepaste "Master Sender" code in de AT-Tiny zou je nu op de seriële monitor een getal moeten zien optellen.


### 4.1.3.2 MasterReader:
Lees het voorbeeld op de arduino website:  arduino.cc MasterReader

Bouw opnieuw het voorbeeld met de Arduino Nano als Master en de AT-Tiny als slave
Lees nu de volgende code in de AT-Tiny:

#include <twi.h>
#include <TinyWire.h>
int x=0;
void setup() {
      TinyWire.begin(8);                
      TinyWire.onRequest(requestEvent);
} 
void loop() {
      delay(1500);
      x++;
      if (x>254) x=0;
}
void requestEvent() {
      TinyWire.write(x);
}

en volgende code in de Arduino Nano:

#include <Wire.h>
void setup() {
      Wire.begin();        
      Serial.begin(57600);
}  
void loop() {
      Wire.requestFrom(8, 1);    

      while (Wire.available()) { 
            int c = Wire.read(); 
            Serial.println(c);
      }
  delay(500);
}

 Je voegt ook hier twee 4k7 pull-up weerstanden toe aan de SDA en SCL lijnen.

Met deze "Master Receiver" code in de Arduino Nano en  "Slave Sender" code in de AT-Tiny zou je opnieuw op de seriële monitor een getal moeten zien optellen.


## 4.1.4 Master en Slave

Bouw en schrijf nu eens zelf de code voor de ontbrekende opstellingen, namelijk :

     Arduino Nano als MasterWriter en de AT-Tiny als SlaveReceiver.

Gebruik hier een drukknop op de Nano en een LED op de Tiny ter visualisatie.
 

     Arduino Nano als SlaveWriter en de AT-Tiny als MasterReceiver.

Gebruik hier een LED op de Nano en een drukknop op de Tiny ter visualisatie.

Bekijk op de website van Arduino.cc ook even het volgende commando:   Wire.setClock(clockFrequency)


## 4.1.5 Servo

In de volgende oefening maken we gebruik van een servo. 
Lees daarom eventjes deze uitleg en het voorbeeld 'knob' op de arduino website: arduino.cc Servo
Bouw ook de schakeling bij 'knop' en test eventje de servo uit je bakje.


## 4.1.6 Remote Sensor

Vaak staat een sensor op een stukje afstand van de centrale sturing.
Zeker als het gaat om een analoge sensor kunnen lange draden heel wat storing opnemen die potentieel het signaal van de sensor verstoren. Denk aan een warmte voeler in een wasmachine die relatief ver kan staan van de printplaat met de was-programma sturing.

In onze opdracht lossen we dit op door de 'sensor',  hier de 10k trimmer, in te lezen met de AT-Tiny en vervolgens die waarde door te sturen naar onze Arduino Nano.
Op deze manier kunnen we sensor tot op 1 meter afstand plaatsen van de servo zonder last te hebben van storing onderweg.

    Voeg dus een trimmer toe op de AT-Tiny en stuur de toestand ( dus 0 .. 1023) van de analoge ingang met I2C door naar de Arduino Nano.
    Met de ontvangen waarde ga je nu een Servo aansturen vanuit de Arduino Nano en wel zodat de Servo mooi gelijk gaat bewegen met het draaien aan de potentiometer. 
    De Nano is de MasterReceiver




-> Laat de code van oefening 4.1.6 op in digitap.  ( Dit zijn twee bestanden !!  -> Tiny + Nano !)

     Vergeet niet in commentaar de nodige aansluitingen te vermelden ...
