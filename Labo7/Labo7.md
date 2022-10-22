# 7.1 I/0 Operaties met registers

Om mogelijke verwarring tegen te gaan: de oefeningen hieronder make we terug met de Arduino Nano.


## 7.1.1 Blink

Bij de typische Arduino instructies was onze eerste kennismaking de "blink sketch".
Dit doen we nu nog eens over doch dit keer schrijven we de code zelf én maken we hiervoor gebruik
van de interne registers in de microcontroller die de in- en uitgangspinnen van de ATMega328p besturen.
We spreken hier dus over de ATMega die in de Arduino Nano zit en niet de losse chip.



## 7.1.2 Up/Down LED-bar

Als tweede oefening besturen we 9 LED's op uitgang D4 tot D12 met behulp van 2 drukknoppen.

De twee drukknoppen zijn "up" en "down".
Onze reeks LED's bestaat uit 3 groene, vervolgens 3 gele en tenslotte 3 rode LED's.
Bij de start van het programma moet de éérste groene LED branden, de rest is uit.
Bij het drukken op "up" moet de 2de groene LED branden en gaat de eerste uit. Zo doorlopen we de 9 LED's.
De functie van de drukknop "down" is dan uiteraard hetzelfde maar in de andere richting.

Zowel de in- als uitgangen stuur je aan via de registers van de MCU. Probeer met slimme bitoperaties je code zo eenvoudig mogelijk te houden.


## 7.1.3 Chronometer met registers

We nemen hier even de opdracht terug van de chrono-meter uit Arduino programming.
Dat was een chronometer gebruikmakende van alle 4 de digits van de 7-segment display uit ons bakje.
Elke milliseconde telt deze chronometer éénje op van 0000 tot 9999 ms.

Schrijf hiervoor een BCD-to-7segment" methode om de display aan te sturen die dit doet door direct de registers aan te spreken.
Er zijn twee drukknoppen, ééntje hiervan start en stopt de chronometer, de andere reset de teller terug naar "0000".
De drukknoppen lees je eveneens in via registers ( zonder interrupt, gewone input).

Denk, vooral bij de uitgangen, goed aan wat een 'poort' wil zeggen en optimaliseer je code en pinaansluitingen door hier nuttig gebruik van te maken.
Als je dit op de juiste manier doet zal je merken dat jou code merkelijk eenvoudiger wordt t.o.v de versie met Arduino-code ...

![image](https://user-images.githubusercontent.com/91600019/197348166-956daf5a-68df-42f6-a1fc-1ef54d1902fe.png)



# 7.2 I/O Access

## 7.2.1 snelheidstest

Om te illustreren wat het effect is van de Arduino-library code op de snelheid waarmee de GPIO bereikbaar zijn doen we een meting.
Schrijf een simpele Arduino sketch die een digitale pin hoog zet, hier na direct terug laag en dit oneindig blijft herhalen.
Bekijk vervolgens het signaal op de uitgang van deze pin met een scoop.
Doe nu hetzelfde maar nu door direct de registers van de GPIO aan te spreken.
Je zet terug dezelfde pin op hoog en direct terug laag in de loop
Bekijk nu opnieuw het signaal op de uitgang en vergelijk met het vorige resultaat



De code van oefening 7.1.2 en 7.1.3 laad je op hier in digitap.
Je post hierbij énkel de .ino bestanden.
Dus géén zip files en géén container folders! ( Dus ook geen tar.gz of andere archief types ... )
