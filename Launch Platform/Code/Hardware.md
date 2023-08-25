# Hardware

## Servo

- MC-410 
- 
### Data
- travel distance 90 deg (0-180 in code)
- Power consumtion: @ 6V -> max@stall: 1A; max@move ca. 0.7A; min: 0.6A 
- https://asset.conrad.com/media10/add/160267/c1/-/en/000404753DS01/datasheet-404753-modelcraft-standard-servo-bms-410c-analogue-servo-gear-box-material-plastic-connector-system-jr.pdf


## Presure sensor
- generic chinesium
### Data 
- Pinout: green: Data; Red 5v; Black GND
- Green give a Voltage corelating to the presure * 0.936329588 (at 5V it maxes out -> presure > 5 Bar)

## LCD
-  https://github.com/johnrickman/LiquidCrystal_I2C this lib and only this lib
- 