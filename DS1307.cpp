/*
  DS1307.cpp - DS1307 Real-Time Clock library
  Copyright (c) 2011 Álvaro Justen aka Turicas.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

extern "C" {
    #include <inttypes.h>
    #include <stdlib.h>
    #include <string.h>
    #include <stdio.h>
}

#include "DS1307.h"
#include "Wire.h"


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

int fromDecimalToBCD(int decimalValue) {
    return ((decimalValue / 1000) * 16 * 16 * 16) +
           ((decimalValue / 100) * 16 * 16) +
           ((decimalValue / 10) * 16) +
           (decimalValue % 10);
}

int fromBCDToDecimal(int BCDValue) {
    return ((BCDValue / (16 * 16 * 16)) * 1000) +
           ((BCDValue / (16 * 16)) * 100) +
           ((BCDValue / 16) * 10) +
           (BCDValue % 16);
}

void DS1307Class::begin() {
    Wire.begin();
}

void DS1307Class::setDate(int year, uint8_t month, uint8_t dayOfMonth,
                          uint8_t dayOfWeek, uint8_t hour, uint8_t minute,
                          uint8_t second) {
    Wire.beginTransmission(DS1307_ADDRESS);
    Wire.send(0); //stop oscillator

    //Start sending the new values
    Wire.send(fromDecimalToBCD(second));
    Wire.send(fromDecimalToBCD(minute));
    Wire.send(fromDecimalToBCD(hour));
    Wire.send(fromDecimalToBCD(dayOfWeek));
    Wire.send(fromDecimalToBCD(dayOfMonth));
    Wire.send(fromDecimalToBCD(month));
    Wire.send(fromDecimalToBCD(year));

    Wire.send(0); //start oscillator
    Wire.endTransmission();
}

int *DS1307Class::getDate() {
    int *values = (int *) malloc(7 * sizeof(int));

    Wire.beginTransmission(DS1307_ADDRESS);
    Wire.send(0); //stop oscillator
    Wire.endTransmission();
    Wire.requestFrom(DS1307_ADDRESS, 7);

    for (int i = 6; i >= 0; i--) {
        values[i] = fromBCDToDecimal(Wire.receive());
    }
    //TODO: 24-hour time?

    return values;
}

DS1307Class DS1307;
