# MAX5719
Arduino Library for the Maxim Integrated MAX5719 20-bit DAC

See the Maxim Integrated datasheet for details [MAX5719](https://datasheets.maximintegrated.com/en/ds/MAX5717-MAX5719.pdf)

## Class, Methods, Defines

## Defines
### MAX5719_MAJOR
### MAX5719_MINOR
### MAX5719_PATCH
##### Description
These defines can be used to determine the current version of the library being used in your code.


## Constructor
### MAX5719(uint8_t SSPIN, uint8_t LDAC)
##### Description
Instantiation of the DAC Library sets the Slave Select Pin and LDAC Pin. Call to begin() initializes the DAC and the Slave Select Pin is pulled High
##### Syntax
`MAX5719 myDAC(SSPIN, LDAC);`
##### Parameters
SSPIN: (parameter required) Slave Select Pin of the DAC on the SPI bus
LDAC: (parameter required) LDAC Input. A falling edge updates the internal DAC latch.
##### Return
None
##### Example
```C++
// Instantiation of MAX5719 Digital Potentiometer
MAX5481 myDAC(5, 7);
```
