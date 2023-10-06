# 3. Bootloaders

## 3.1: Werken met een AT-Tiny


### 3.1.1 Algemeen


De AT-Tiny is een mini versie van de ATmega328p microcontroler die het hart vormt van de Arduino.
De ATtiny85 is een chip met 8 pinnen waarvan er reeds twee nodig zijn voor de voedingsspanning. Er zijn m.a.w. slecht 6 nuttige pinnen.
Als we ook nog ten alle tijde willen communiceren met de chip dan blijven slechts 2 bruikbare pinnen over..
Afhankelijk van de versie heeft hij 2 (ATtiny25), 4 (ATtiny45) of 8Kbytes (ATtiny85) aan geheugen.
Er zijn ook nog enkele andere (grotere) versies van de ATtiny maar die komen hier niet aan bod.

De AT-Tiny is natuurlijk zoals zijn naam doet vermoeden vrij klein.
Ook al is hij beperkt qua aansluitingen in veel schakelingen hebben we eingelijk niet meer nodig dan dat en is hij dus ideaal geschikt.

Om met de Arduino-IDE sketches te kunnen uploaden naar deze microcontroler moet deze laatste hiervoor reeds een stukje software bevatten.
Dit stukje software, zoals we reeds besproken hebben in de theorie, noemen we de bootloader.

Om zo’n bootloader op onze microcontroler-chip te branden hebben we nu wel wat extra hardware nodig.
Zoals besproken noemen we deze hardware een ‘ISP’ of ‘In-System-Programmer’. Vaak spreken we ook gewoon simpelweg van een ‘programmer’.
Dit laatste is eigenlijk een groepsnaam want ook heel wat andere soorten micro chips
zoals cpld’s, fpga’s, eeprom’s worden ook met hun versie van zo’n ‘programmer’ van code of data voorzien.

Om ons wat geld te besparen hebben het ontwikkel-team van Arduino gelukkig een stukje software geschreven
waardoor we een bestaande Arduino hardware ook als programmer kunnen gebruiken voor een nieuwe chip!

![tinyusb](https://github.com/BrianVanCampen/MicroControllers/assets/91600019/2b81166d-f791-40ff-b2a3-750c1665c0a2)

### 3.1.2 Toevoegen ATTiny aan de Arduino-IDE


Het eerste probleem is dat we nu moeten oplossing is dat ATtiny niet voorkomt in de lijst van beschikbare boards/chips in de IDE.
Gelukkig heeft iemand van MIT reeds een library gemaakt voor onze IDE te vinden op github. ATtiny Board Library - door David Mellis Ph.D. MIT Media Lab.

Deze library toevoegen aan de IDE doen we als volgt: ga naar File en dan Preferences.
Er opent een venster met diverse instellingen en onderaan zien we Additional Boards Manager URLs

Copy en Paste daar nu de volgende URL: https://raw.githubusercontent.com/damellis/attiny/ide-1.6.x-boards-manager/package_damellis_attiny_index.json klik vervolgens op Ok

Hierna gaan we naar Tools dan Board: en we kiezen bovenaan Board Manager Als we door de lijst scrollen komen we ergens de volgende tekst tegen:


![attiny](https://github.com/BrianVanCampen/MicroControllers/assets/91600019/facbffce-5f1a-4c08-8a3f-5053ea7b4b1c)

Bij het klikken op de tekst verschijnt net zoals in de afbeelding hierboven ook rechts een knop Install 
Na het drukken op install is de IDE even bezig met installeren en krijgen we terug ons vertrouwde scherm.


### 3.1.3 De Arduino Nano als Programmer


Om de Arduino Nano als programmer te gebruiken moeten we deze eerst laden met de ArduinoISPsketch.
Je sluit daartoe de Arduino Nano aan op een leeg breadbordje, dus met geen enkele pin van de Nano verbonden!

Kies vervolgens in het File menu van de Arduino-IDE uit de lijst Examples de sketch ArduinoISP
Je zorgt dat bij tools zeker het bord Arduino Nano geselecteert staat en vervolgens upload je de code naar de Nano

Als dit klaar is hebben we onze Nano omgetovert in een micro-controller programmer voor Atmel chips.
We zorgen er vervolgens voor dat hij zeker niet langer spanning krijgt door de usb kabel los te koppelen.


### 3.1.4 Branden van de bootloader


Nu het branden van een bootloader zelf.Om dit te doen moeten we de ATtiny aansluiten aan een programmer.
In dit geval een Arduino Nano. Maak hiervoor de onderstaande schakeling.

![tinysprogrrammer](https://github.com/BrianVanCampen/MicroControllers/assets/91600019/0bca0ece-5b02-4cc6-be0e-00d5dee1dd22)

Als we alles juist aangesloten hebben kunnen we terug effectief overgaan tot het branden zelf. We pluggen nu de usb kabel van onze laptop terug in onze Arduino Nano programmer

Vervolgens kiezen we in de Arduino IDE bij tools en als programmer: Arduino as ISP

Belangrijke volgende stap is om onder tools vervolgens board ditmaal ATtiny25/45/85 te kiezen, maar ook bij processor niet vergeten om ATtiny85 te selecteren!
Herinner dat bij het branden van de bootloader hier altijd de selectie gekozen worden van de chip en bord dat we willen branden, niet waarmee we branden

Na voorgaande puntjes nog even te checken kiezen we onder tools ten slotte het item Burn Bootloader.
Zodra je dit doet zie je opnieuw de tx en rx led`s op de Nano knipperen en even later is het van de Tiny branden klaar. 

## 3.2 De AT-Tiny programmeren


### 3.2.1 Blinky op de Tiny


Om zeker te zijn dat de kersverse bootloader op onze AT-Tiny goed werkt  bouwen we eerst een ‘blink’ schakeling.
Je schrijft hier echter wél zelf de sketch want de AT-Tiny chip heeft uiteraard géén ingebouwde LED.. 

Aan welke pin je best de LED moet hangen zoek je op in de pinout de chip ATTiny-pinout    (zie ook bij 'hulpdocumenten')

Probeer deze aansluitingen ook eens te vinden in de  Datasheet

En toch nóg even herhalen voor wie het niet meer weet: een LED heeft een  serie-weerstand  !!!!

Het uploaden van onze sketch doen we opnieuw via de Arduino Nano en dezelfde schakeling als hierboven
door in de IDE op het moment dat we de sketch willen uploaden  tegelijkertijd met het icoontje upload ook de ‘shift’ op ons keyboard in te drukken.


### 3.2.2 PWM met de Tiny


Probeer nu met 2 drukknoppen, ééntje 'up' en ééntje 'down' een PWM signaal naar een LED te sturen. De LED doe je feller of minder fel branden m.b.v. de drukknoppen. ( Gebruik PB0 voor de LED )

Hoe moet je het uploaden combineren met de drukknoppen en de LED op dezelfde pinnen?
Hoe kan je nog code uploaden nadat je al eens een sketch op de Tiny hebt gezet waar de communicatie pinnen nu een input of output geworden zijn?

Gelukkig is hier rekening mee gehouden.
Nét na het resetten (of het aanschakelen van de voeding ) van de AT-Tiny zal deze éérst gedurende een bepaalde tijd de pinnen configureren zodat deze dienen om code up te loaden.
Even later pas zal onze sketch beginnen runnen. Dit noemen we de "programming window".




-> Laat de code van oefening 3.2.2 op in digitap.
     Vergeet niet in commentaar in jou code te zetten wat er aan welke pinnen is aangesloten ...
