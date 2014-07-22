delta - atxmega128a1 XPLAIN dev board
===========

Guide to setup ATxMega128a1 with LUFA and the AVRISP-MKII programmer using the
on board USB, 
[Blog Post from Dean Camera](http://fourwalledcubicle.com/blog/2010/02/mein-server).

Note with the latest AVR Stuido 6, you can't program the chip using the faked 
AVRISP-MKII. It polls the TDI line looking for an active chip and the line is
busy since it's tied to both the AT90USB1287 and the ATxMega128a1.

## Dependencies

I'm working with Ubuntu development enviorment.
Install the avr-gcc and the libs associated with atxmega chips.

    $ sudo apt-get install avr-libc gcc-avr

## Build

Created a series of small programs to test each layer of functionality before
starting the integration process.

### ledTest build

This is the programing statment for the atxmega128a1. Change the x128a1 option
for somehting else.

    $ sudo avrdude -p x128a1 -b 9600 -c avrisp2 -e -v -U flash:w:dev/ledTest/ledTest.hex -P usb

## Bugs

For bug reports and issues use the 
[github issues page](https://github.com/rosasaul/delta/issues), try to make
sure I'll be able to reproduce the issue.

## Copyright and Licence

delta is an open source drone desgin, built from the ground up.
Copyright (C) 2013 Saul Rosa

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.

## Author Information

This module was written by Saul Rosa <rosa.saul@megaframe.org>.

I'm an electrical engineer who uses a lot of code to get my work done. This
drone is a hoby project. It uses embeded controllers to interface hardware, 
and machine learning to control stabilization.

