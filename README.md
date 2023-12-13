## Overview

Arduino library, for all architectures, to reading analog inputs and correct convertation to temperature in Celsius.<br>

Support thermocoupler PT1000 and NTC10K for max 12-bit ADC.<br>

This function scan analog input, convert value to Celsius, get 5 samples and do averange value from this.<br>

## Example

1. include library
```
#include <KB_Temperature.h>
```

2. select which class need use
	1. use NTC10K class and define (A, B, C, D, E, F, G, H)<br>
A - input analog pin (example: 8)<br>
B - resistance of NTC thermocoupler (example: 10000)<br>
C - resistance of external resistor in circuit, real value with tolerance measured with voltmeter (example: 10157)<br>
D - beta coeficient, this parameter write you producer of thermocoupler (example: 3950)<br>
E - nominal temperature in Kelvin, standard nominal is 25 degree in Celsius (example: 298.15)<br>
F - count of values in analog-digital convert table for your device resolution, in esp32 is 12-bit = 4095, in other can be 10-bit = 1023 (example: 4095)<br>
G - input power supply for NTC thermocoupler (example: 3.3)<br>
H - value of error temperature difference (example: -5)<br>

	2. use PT1000 class and define (A, B, C, D, E)<br>
A - input analog pin (example: 5)<br>
B - relation between temperature and voltage (voltage at 100°C minus voltage at 0°C) (example: 1.88)<br>
C - value of error temperature difference (example: -26)<br>
D - count of values in analog-digital convert table for your device resolution, in esp32 is 12-bit = 4095, in other can be 10-bit = 1023 (example: 4095)<br>
E - input power supply for PT1000 thermocoupler (example: 3.3)<br>

```
float tempXY_temperature;
TemperatureNTC10K tempXY(8, 10000, 10157, 3950, 298.15, 4095, 3.3, -5);

float tempAB_temperature;
TemperaturePT1000 tempAB(5, 1.88, -26, 4095, 3.3);
```

2. include begin() function in setup()
```
void setup()
{
	tempXY.begin();
	
	tempAB.begin();
}
```

3. use library function
```
void loop()
{
	tempXY.NTC10K(tempXY_temperature);
	
	Serial.print("NTC10K temperature: ");
	Serial.print(tempXY_temperature);
	lcd.write(0xdf);
	Serial.println("C");
	
	tempAB.PT1000(tempAB_temperature);
	
	Serial.print("PT1000 temperature: ");
	Serial.print(tempAB_temperature);
	lcd.write(0xdf);
	Serial.println("C");
}
```

Return both values in Celsius.<br>