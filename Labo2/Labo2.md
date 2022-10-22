# 2.3. Software serial

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

    schrijf éérst de code voor één led in de ene Arduino en één potentiometer op de andere.
    schrijf vervolgens de code voor de omgekeerde weg
    pas als vorige twee delen werken combineer je de code 


Post de code van oefeing 2.3 in digitap. In je arduino sketch schrijf je in comments de naam van persoon waar je mee samenwerkte.
Zoals steeds post je énkel het .ino bestand en geen folders of zip files.
