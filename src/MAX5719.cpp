/*****
 * MAX5719.cpp
 *
 * Created on: 01-8-2021
 *     Author: Robert F. Chapman <Robert.F.Chapman@gmail.com>
 *             Copyright (c) 2021-Current Robert F. Chapman
 *  
 *  This file is part of MAX5719 Library for Arduino Micro(s).
 *
 *  This Library is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.

 *  This Library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with Foobar.  If not, see <https://www.gnu.org/licenses/>.
 */
 
#include <MAX5719.h>
#include <SPI.h>



MAX5719::MAX5719(uint8_t ss, uint8_t ldac)
{
     pinMode(ss, OUTPUT);
     pinMode(ldac, OUTPUT);

     _SS = ss;  // Set Slave Select Pin
     _LDAC = ldac;
}


void MAX5719::begin(void)
{
     SPI.begin();
     digitalWrite(_SS, HIGH);  // Make sure CE is HIGH at initialization 
     digitalWrite(_LDAC, HIGH); // Make sure LDAC is HIGH at initialization
}


void MAX5719::setOutput(double voltage) {
 
   uint32_t code = (uint32_t)(voltage / 5.0 * 0xFFFFFF);
 
   digitalWrite(_SS, LOW);
   digitalWrite(_LDAC, HIGH);

   delay(2);

   SPI.transfer((code & 0x00FF0000) >> 16);
   SPI.transfer((code & 0x0000FF00) >> 8);
   SPI.transfer((code & 0x000000FF));
   
   delay(2);

   digitalWrite(_SS, HIGH);
   digitalWrite(_LDAC, LOW);
 
 }

