# 1.3. Clamper

Het doel van deze oefening is een dieper begrip te creëren wat het effect is van een PWM signaal op deze basiscomponenten 

bouw onderstaande schakeling:



Pas de code van de vorige oefening aan zodat je met de trimmer de duty-cycle deze PWM uitgang kan variëren tussen 5% en 95%

Meet met de scoop de uitgang bij een 5 tal verschillende duty-cycles. Probeer te verklaren wat je ziet!


# 1.4. PWM LED Fader Library

Je taak hier is om zélf een library te maken die LED's kan 'in-faden' en 'uit-faden',
m.a.w kan in lichtsterkte doen toenemen van helemaal uit tot volle sterkte,
en van volle sterkte tot volledig uit, en dit met behulp van analogWrite().

Bij Arduino programming zag je reeds hoe je libraries kon gebruiken en al een tip van de sluier dat ook zelf libraries schrijven kan, alsook  waar die dan staan.
Op de volgende link kan je meer in detail de uitleg vinden hoe dat nu precies moet zo'n library schrijven:

https://www.arduino.cc/en/Hacking/LibraryTutorial

De aanpak die we gebruiken is volgens de Object Oriented Programming principes.

De bedoeling is een een 'fader' Class te creëren met de methodes fadein() en fadeout().
Bij het aanmaken van een object geef je de gewenste PWM uitgang mee.
Deze methodes moet je de snelheid kunnen meegeven in milliseconden hoe lang het duurt om de LED's in- of uit te faden.

Zoals we reeds weten is een Arduino sketch eigenlijk C++ code, maar dan met enkel libraries als uitbreiding.
Uitbreidingen  om ook commando's te hebben zoals "digitalWrite()" die uiteraard geen standaard C++ code zijn.

Klassen creëren, zoals je reeds kon zien op bovenstaande Arduino.cc link, leunt dicht aan bij wat je reeds kent uit C#
Een goeie bron van informatie als je code toch niet doet wat je zou verwachten is volgende website: 

http://www.cplusplus.com/doc/tutorial/


De code van deze oefening laad je op hier in digitap.
Dit zullen meerdere bestanden zijn. Je post hierbij énkel de .ino .cpp .h en .txt bestanden.
Dus géén zip files en géén container folders! ( Dus ook geen tar.gz of andere archief types ... )

Voeg ook een eenvoudig tekstbestand toe ( .txt -> notepad bvb)  met je verklaring bij oefening 1.3
Van de andere deeltjes (1.1 & 1.2) hoef je niets in te dienen.
