# UV Meter

This simple yet effective project will provide a way to the UV levels in your area, which is helpful to determine what level of sun protection is needed on a particular day. Readings can be displayed on the 7 segment display and are stored on the SD card for easy tracking.									


## Bill of materials
|Qty | Code | Description |
| --- | --- | --- |
|1 | [XC4410](http://jaycar.com.au/p/XC4410) | Arduino Uno |
|1 | [XC4536](http://jaycar.com.au/p/XC4536) | Datalogging shield |
|1 | [XC3714](http://jaycar.com.au/p/XC3714) | 7 Segment Display Module |
|1 | [WB2022](http://jaycar.com.au/p/WB2022) | Cat5 solid core cable |
|1 | [XC4518](http://jaycar.com.au/p/XC4518) | UV sensor module |


## Software Libraries
| Library | Author  | Version |
| --- | --- | --- |
| RTCLib | Adafruit | 1.2.0 |
| SdFat | Bill Greiman | 1.0.7 |


## Connection table
| 7Segment Module | UNO | UV | Description |
| --- | ---- | ----| --- |
| DIN | 8 | | Data to module |
| CS | 9 |  | Chip select |
| CLK | 7 | | Clock signal |
| | A1 | out | Sensor output |
|VCC | 5V | + | Positive Rail |
| GND | GND | - | Ground |

###### Notes:
* Do not connect UV Meter to `A4` or `A5`, as these are needed to talk to the RTC.
* DIN/CS/CLK has had trouble connecting to the HW SPI on pins 13,12,11. Bit-bang on 9,8,7 is fine for our purposes.

## Assembly instructions

1. Remove all header pins as per databook instructions
2. solder 5 lots of solid core wire
1. hot glue module onto shield
3. solder in place 5 wires
2. solder header onto UV meter (note: XC3714 module has 5 header pins, which we can use 3 of to connect.)
4. mount uv meter over wires
5. wire uv meter to A1, 5v gnd.
