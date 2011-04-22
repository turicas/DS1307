#include <string.h>
#include <Wire.h>
#include <DS1307.h>

char dateTime[20];
int *RTCValues;

char *fromNumberToWeekDay(int dayOfWeek) {
    char *nameOfTheDay = (char *) malloc(10 * sizeof(char));
    if (dayOfWeek == 0) {
        sprintf(nameOfTheDay, "Sunday");
    }
    else if (dayOfWeek == 1) {
        sprintf(nameOfTheDay, "Monday");
    }
    else if (dayOfWeek == 2) {
        sprintf(nameOfTheDay, "Tuesday");
    }
    else if (dayOfWeek == 3) {
        sprintf(nameOfTheDay, "Wednesday");
    }
    else if (dayOfWeek == 4) {
        sprintf(nameOfTheDay, "Thrusday");
    }
    else if (dayOfWeek == 5) {
        sprintf(nameOfTheDay, "Friday");
    }
    else if (dayOfWeek == 6) {
        sprintf(nameOfTheDay, "Saturday");
    }
    else {
        sprintf(nameOfTheDay, "Not found");
    }

    return nameOfTheDay;
}

void setup() {
    Serial.begin(9600);

    DS1307.begin();
}

void loop() {
    RTCValues = DS1307.getDate(); //TODO: use a new structure?
    //Year: four-digit. Example: 2011
    //Month: two-digit, from 01 to 12
    //Day of month, from 01 to 31
    //Day of week, from 0 (sunday) to 6 (saturday)
    //Hour: 24-hour format, from 0 to 23
    //Minute: from 0 to 59
    //Second: from 0 to 59

    sprintf(dateTime, "%04d-%02d-%02d %02d:%02d:%02d", RTCValues[0],
            RTCValues[1], RTCValues[2], RTCValues[4], RTCValues[5],
            RTCValues[6]);
    Serial.print(dateTime); //TODO: ...
    Serial.print(" - day of week: ");
    Serial.println(fromNumberToWeekDay(RTCValues[3]));

    delay(5000);
}
