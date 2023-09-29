# 2. Serial Communication


## 2.1. Serial.Begin()

je hebt dit commando reeds gebruikt maar nu je iets beter weet hoe RS232 werkt is dit een goed moment om het toch even te herbekijken...
Ga naar de pagina van Serial.begin() op de Arduino referenties paginas ( arduino.cc -> reference ) Lees deze pagina volledig door. 

Herken je wat je leerde in de theorie ?


## 2.2. Observatie

Schrijf een Arduino sketch waarmee je een tekst-string van max. 64 characters vanuit de terminal naar de arduino kan sturen.
De arduino moet vervolgens 3 seconden later diezelfde tekst terugsturen vanuit de Arduino naar de terminal

Sluit de scoop aan op de TX en RX pinnen van de Arduino. Zoals je weet komen deze lijnen van de UART.
Je gebruikt dus beide kanalen van de scoop en plaatst RX en TX mooi onder elkaar.

Bekijk op de scoop wat er gebeurt bij het versturen van de data.

Wellicht had je bij het schijven van de code voor bovenstaande oefening 9600 Baud gekozen als snelheid...
Kijk eens terug op Arduino.cc wat de laagste transmissie snelheid is dat je kan selecteren, pas je code aan met deze laagste snelkeid,
bekijk opnieuw TX en RX op de scoop.



## 2.3. Software serial

Het probleem met de UART van de Arduino is dat dze reeds in gebruik is om te communiceren met onze laptop.
Hiervoor zit op de Arduino nog een extra chip die het "quasi" RS232 signaal ( de spanningen zijn 0V en 5V ) uit de UART naar een serial-to-USB chip stuurt.
Dat is ook de reden dat ondanks de verbinding via USB verloopt, je in de device manager van je laptop de verbinding kan tóch terug zal vinden als een "com poort".
Zo'n com poort is normaal gesproken ook een fysieke RS232 interface, doch énkel nog gespecialiseerde "semi-rugged"
en bepaalde professionele laptops bezitten nog zo'n klassieke 9-pin's DB connector.

Er is echter een mogelijkheid om softwarematig een 2de UART te creëren op de Arduino.

Hoe dit mogelijk is zal je beter begrijpen eens we wat verder in de cursus het stukje 'timers' achter de kiezen hebben.
Om zo'n softwarematige UART te creëren hoef je enkel de Software.serial library te installeren.

Meer uitleg over Software serial kan je hier vinden: https://www.arduino.cc/en/Reference/softwareSerial


Voor deze opdracht met software-serial vorm je groepjes per twee.

Bouw nu opnieuw élk individueel een schakeling met een trimmer aangesloten tussen Vcc en GND en met de middenloper op de analoge ingang A0.
Sluit eveneens een LED aan op één van de PWM uitgangen. Vervolgens ga je beide Arduino's met elkaar verbinden via een seriële verbinding.
De bedoeling is dat de trimmer's telkens de LED besturen op de andere Arduino. Dus de trimmer op Arduino1 moet de LED op Arduino2 besturen en omgekeerd.

Schrijf de code om dit te doen en test de communicatie: doe dit stapgewijs !!!

- schrijf éérst de code voor één led in de ene Arduino en één potentiometer op de andere.
- schrijf vervolgens de code voor de omgekeerde weg
- pas als vorige twee delen werken combineer je de code 


Post de code van oefeing 2.3 in digitap. In je arduino sketch schrijf je in comments de naam van persoon waar je mee samenwerkte.
Zoals steeds post je énkel het .ino bestand en geen folders of zip files.
