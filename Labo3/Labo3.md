# 3.2 De AT-Tiny programmeren


## 3.2.1 Blinky op de Tiny


Om zeker te zijn dat de kersverse bootloader op onze AT-Tiny goed werkt  bouwen we eerst een ‘blink’ schakeling.
Je schrijft hier echter wél zelf de sketch want de AT-Tiny chip heeft uiteraard géén ingebouwde LED.. 

Aan welke pin je best de LED moet hangen zoek je op in de pinout de chip ATTiny-pinout    (zie ook bij 'hulpdocumenten')

Probeer deze aansluitingen ook eens te vinden in de  Datasheet

En toch nóg even herhalen voor wie het niet meer weet: een LED heeft een  serie-weerstand  !!!!

Het uploaden van onze sketch doen we opnieuw via de Arduino Nano en dezelfde schakeling als hierboven
door in de IDE op het moment dat we de sketch willen uploaden  tegelijkertijd met het icoontje upload ook de ‘shift’ op ons keyboard in te drukken.


## 3.2.2 PWM met de Tiny


Probeer nu met 2 drukknoppen, ééntje 'up' en ééntje 'down' een PWM signaal naar een LED te sturen. De LED doe je feller of minder fel branden m.b.v. de drukknoppen. ( Gebruik PB0 voor de LED )

Hoe moet je het uploaden combineren met de drukknoppen en de LED op dezelfde pinnen?
Hoe kan je nog code uploaden nadat je al eens een sketch op de Tiny hebt gezet waar de communicatie pinnen nu een input of output geworden zijn?

Gelukkig is hier rekening mee gehouden.
Nét na het resetten (of het aanschakelen van de voeding ) van de AT-Tiny zal deze éérst gedurende een bepaalde tijd de pinnen configureren zodat deze dienen om code up te loaden.
Even later pas zal onze sketch beginnen runnen. Dit noemen we de "programming window".




-> Laat de code van oefening 3.2.2 op in digitap.
     Vergeet niet in commentaar in jou code te zetten wat er aan welke pinnen is aangesloten ...
