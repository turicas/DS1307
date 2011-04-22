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

#include <stdlib.h>
#include "DS1307.h"

void DS1307Class::begin() {
    //TODO: begin Wire
}

void DS1307Class::setDate(uint8_t year, uint8_t month, uint8_t day,
                          uint8_t hour, uint8_t minue, uint8_t second) {
    //TODO: write the values to RTC
}

uint8_t *DS1307Class::getDate() {
    uint8_t *values = (uint8_t *) malloc(6 * sizeof(uint8_t));

    //TODO: read from RTC and populate values

    return values;
}

DS1307Class DS1307;
