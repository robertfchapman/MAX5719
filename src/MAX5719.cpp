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


void MAX5719::setCode(uint32_t code) {
   if (code > MAX_CODE) {
      code = MAX_CODE;
   }

   // The MAX5719 accepts a 24-clock frame. The 20-bit DAC code occupies
   // D23 through D4; the final four bits are don't-care bits.
   uint32_t frame = code << 4;

   digitalWrite(_SS, LOW);
   digitalWrite(_LDAC, HIGH);

   delay(2);

   SPI.transfer((frame >> 16) & 0xFF);
   SPI.transfer((frame >> 8) & 0xFF);
   SPI.transfer(frame & 0xFF);
   
   delay(2);

   digitalWrite(_SS, HIGH);
   digitalWrite(_LDAC, LOW);
}


void MAX5719::setOutput(double voltage) {
   uint32_t code;

   // Treat negative values and NaN as zero-scale.
   if (!(voltage > 0.0)) {
      code = 0;
   } else if (voltage >= 5.0) {
      code = MAX_CODE;
   } else {
      // Round to the nearest 20-bit code instead of truncating.
      code = (uint32_t)((voltage / 5.0 * MAX_CODE) + 0.5);
   }

   setCode(code);
}

