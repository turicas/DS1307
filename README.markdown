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

<div style="height: 350px; line-height: 350px; text-align: center">
    <img src="https://github.com/turicas/DS1307/raw/master/photos/DS1307-front-back.jpg" style="vertical-alignt: middle; max-height: 100%" />
    <br />
    <img src="https://github.com/turicas/DS1307/raw/master/photos/DS1307-Arduino.jpg" style="vertical-alignt: middle; max-height: 100%" />
</div>
<br />
<div style="text-align: center">
    DS1307 RTC module (front and back) from SparkFun and Arduino with connected to DS1307 RTC module.
</div>



Thanks To
=========

Based on [Wiring.org.co RTC example](http://wiring.org.co/learning/libraries/realtimeclock.html) and [Daniel Gonçalves post at LusoRobótica Forum](http://lusorobotica.com/index.php/topic,681.0.html).
