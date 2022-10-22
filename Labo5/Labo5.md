## Nota voor de ATMega328 chipversie dus de versie ZONDER 'p' op het einde : 

Er bestaat een variant van de ATMega328p ZONDER de letter 'p' op het einde. Bij deze chip zal bovenstaande methode niet werken en zijn nog enkele extra stappen nodig:
Ga naar File > Preferences
Kopiëer en plak onderstaande URL in het veld Additional Boards Manager URLs
   https://mcudude.github.io/MiniCore/package_MCUdude_MiniCore_index.json
en sluit het venster.
Ga naar Tools > Board > Boards Manager
Scroll helemaal naar beneden tot je MiniCore ziet staan, klik erop en klik vervolgens op Install
Als het installeren klaar is sluit je het boards manager venster
Belangrijke volgende stap is om onder tools vervolgens board ditmaal bij "MiniCore" de ATMega328 te selecteren
Kies bij Variant vervolgens 328 / 328A

Herinner dat bij het branden van de bootloader hier altijd de selectie gekozen worden van de chip en bord dat we willen branden, niet waarmee we branden

Na voorgaande puntjes nog even te checken kiezen we onder tools ten slotte ook hier het item Burn Bootloader. 
Zodra je dit doet zie je opnieuw de tx en rx led`s op de Nano knipperen en even later is het van de ATMega    branden klaar.
# 5.2 De nieuwe ATMega"Arduino" testen


5.2.1 Blinky


Om zeker te zijn dat de kersverse bootloader op onze ATMega  goed werkt  testen we eerst even de ‘blink’ schakeling.

Op een echte Arduino Uno of Nano stuurt deze example sketch de ingebouwde led aan. Uiteraard is die led nu wel nog afwezig.
We voegen dus een LED toe op pin 15 =  PB1 = digitale uitgang D9 met nodige serieweerstand.

De 'blink' code zal je dus ook moeten aanpassen om deze pin te gebruiken


Het uploaden van onze sketch doen we opnieuw via de Arduino Nano en dezelfde schakeling als hierboven
door in de IDE op het moment dat we de sketch willen uploaden  tegelijkertijd met het icoontje upload ook de ‘shift’ op ons keyboard in te drukken.
