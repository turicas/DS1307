DS1307 Arduino Library
======================

If do you need to know date and time in your Arduino project, so you need a Real-Time Clock (or RTC).

One of the most famous RTC ICs is DS1307, from Dallas Semiconductor.

This IC uses I²C to communicate with Arduino and this implementation is just a layer above Wire library.


Installation
============

Download the tarball, uncompress it and put the directory `DS1307` inside your personal library folder (`~/sketchbook/libraries/` -- on UNIX like SOs) or in the Arduino library folder on the system (`/usr/share/arduino/libraries` on GNU/Linux -- requires root access).


Examples
========

For now that are only 2 examples: `SetDate` and `ReadDate` -- the names autoexplain. :-)


Hardware
========

There is a [RTC module with DS1307 sold by SparkFun](http://www.sparkfun.com/products/99).
