#include <Wire.h>
#include <DS1307.h>

void setup() {
    DS1307.begin();
    DS1307.setDate(2011, 04, 22, 6, 12, 31, 30);
}

void loop() {
    //Do nothing...
}
