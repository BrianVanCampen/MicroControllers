# 6.1 SPI

## 6.1.1 Algemeen

In de theorie hebben we naast I2C ook SPI uitvoerig besproken en dus is nu opnieuw het praktisch werken ermee aan de beurt.
Je hebt na de AT-Tiny nu ook de bootloader op een ATMega328p gezet en dis keer gebruiken we deze om over SPI mee te communiceren.

We hebben het geluk dat wer de Arduino Nano als programmer kunnen gebruiken,
maar hierdoor mogen we niet uit het oog verliezen dat ook al ziet hij er uit als een Arduino we hier echt wel met een programmer te maken hebben.
Dat wil zeggen dat we nooit én de programmeer-verbindingen én de componenten van onze te bouwen schakeling tegelijk gaan aansluiten.
Bij de AT-Tiny was de aanpak om op ons breadboard twee zones te houden.
Dat is hier lastiger omdat we dan télkens eveneens het kristal en de condensators van de oscillator mee zouden moeten verhuizen.
Hier zal je dus telkens de verbindingen moeten maken en terug losmaken.
Als je goed kijkt welke verbindingen de programmer gebruikt zal je goed begrijpen waarom !

 

## 6.1.2 De SPI library

Om op een eenvoudig wijze een SPI communicatie op te zetten maken we gebruik van de SPI library.
Bekijken nu even de beschrijving van deze library op de Arduino.cc website: https://www.arduino.cc/en/reference/SPI
Met de beschrijving uit de theorie zou je nu je weg moeten kunnen vinden hier.

 Bekijk vooral even de commando's
  

            SPISettings()
            beginTransaction()
            transfer()
            begin()


## 6.1.3 Remote Servo

Om wat je net gelezen hebt nu even om te zetten in een echte schakeling gaan we een analoge spanning meten en doorsturen naar onze kersverse breadboard Arduino
De Arduino Nano is hier uiteraard de Master en de ATMega328p breadboard opstelling is de SPI Slave

De SPI code voor de master moet je nu na het lezen van alle informatie kunnen samenstellen.
Probeer het dus even zelf en spring niet direct op zoek naar kan en klare code op google...

Wat betreft de slave echter hebben we een ander verhaal.
De SPI library is namelijk onvolledig en bevat énkel de code om van de Arduino een Master te maken.
Omdat de meeste schakelingen de Arduino als master hebben en een sensor, actuator,.. als slave
hebben de makers van de SPI library dat stuk als niet noodzakelijk gevonden en achterwege gelaten.
We beperken deze oefening daarom tot het sturen van data vanuit de Nano naar de bradboard Arduino

Uiteraard wil dat nog niet zeggen dat de Microcontroller zélf niet in staat is spi-slave te worden!
Om van onze breadboard Arduino een slave te maken moeten we dit alleen een laagje dieper gaan implementeren.
Omdat dit duidelijk buiten het bestek van deze oefening zou vallen krijg je daarom hier de basiscode voor de slave
Je zal ze uiteraard verder moeten aanvullen om de nodige code te krijgen voor de opdracht
Het SPI gedeelte echter is klaar hier:

#include SPI.h
volatile boolean ss;
volatile byte rx; // ontvangen byte
volatile byte tx=0x0; // te zenden byte

void setup() {

          SPCR |= _BV(SPE);
          ss = false;
          SPI.attachInterrupt();
}

ISR (SPI_STC_vect) {
          rx = SPDR;
          ss = true;
}

void loop() {

          // ---verzenden---
           tx=0x00; // tx is de waarde die verzonden wordt naar de Master
           SPDR = tx;

        // ---ontvangen---
          if (ss) { // rx bevat de waarde die van de Master komt }
}

De 'slave select' kan je vrij kiezen op de Master.
Die heb je als programmeur immers zelf in handen omdat er meerdere slaves mogelijk zijn.
Aan de kant van onze breadboard ATMega verwacht de slave code hier echter dat je pin 10 gebruikt als "Slave Select"

De slave code verwacht verder nog volgende instellingen:
- De data wordt gelezen/geschreven in het begin van de klok
- De klok-cyclus start bij een opgaande flank

Welke klok-snelheid kan en mag je kiezen voor deze schakeling... ?



Post de code van oefening 6.1.3 in digitap. Schrijf duidelijk in de comments of het gaat om de master of de slave.
Vergeet niet om de twee ino codes te posten, Master én Slave.
Zoals steeds post je énkel het .ino bestand en geen folders of zip files
