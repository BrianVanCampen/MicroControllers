#include "testlib.h"

fader fader(6);
void setup() {

}

void loop() {
fader.fadein();
fader.fadeout();
delay(1000);
}
