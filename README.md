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
|1 | [HM3212](http://jaycar.com.au/p/HM3212) | Header Strip |


## Software Libraries
| Library | Author  | Version |
| --- | --- | --- |
| RTCLib | Adafruit | 1.2.0 |
| SdFat | Bill Greiman | 1.0.7 |


## Connection table
| 7Segment Module | UNO | UV | Description |
| --- | ---- | ----| --- |
| DIN | 7 | | Data to module |
| CS | 6 |  | Chip select |
| CLK | 8 | | Clock signal |
| | A0 | out | Sensor output |
|VCC | 5V | + | Positive Rail |
| GND | GND | - | Ground |

###### Notes:
* Do not connect UV Meter to `A4` or `A5`, as these are needed to talk to the RTC.
* DIN/CS/CLK has had trouble connecting to the HW SPI on pins 13,12,11. Bit-bang on 8,7,6 is fine for our purposes.

## Assembly instructions

1. hot glue module onto shield
2. solder 5 lots of solid core wire
3. solder in place
2. remove and reverse pins from uv sensor to turn around
4. mount uv meter over wires
5. wire uv meter to A0.
