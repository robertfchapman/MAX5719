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
// Instantiation of MAX5719 DAC
MAX5719 myDAC(5, 7);
```

## begin()

Initializes SPI and places the chip-select and LDAC pins in their inactive states.

```C++
myDAC.begin();
```

## setCode(uint32_t code)

Writes a raw 20-bit code to the DAC. Values greater than `MAX5719::MAX_CODE`
(`0xFFFFF`) are clamped to full scale. The library places the code in the first
20 bits of the MAX5719's 24-clock SPI frame.

```C++
myDAC.setCode(0x80000); // Approximately midscale
```

## setOutput(double voltage)

Compatibility helper that converts a voltage from 0 V to 5 V to the nearest
20-bit code and calls `setCode()`. Values outside that range are clamped.

```C++
myDAC.setOutput(2.5); // Approximately midscale
```
