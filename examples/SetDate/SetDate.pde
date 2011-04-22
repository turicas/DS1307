#include <Wire.h>
#include <DS1307.h>

void setup() {
    DS1307.begin();
    DS1307.setDate(2011, 04, 22, 5, 12, 31, 30);
    //Year: four-digit. Example: 2011
    //Month: two-digit, from 01 to 12
    //Day of month, from 01 to 31
    //Day of week, from 0 (sunday) to 6 (saturday)
    //Hour: 24-hour format, from 0 to 23
    //Minute: from 0 to 59
    //Second: from 0 to 59
}

void loop() {
    //Do nothing...
}
