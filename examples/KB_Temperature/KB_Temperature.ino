#include <KB_Temperature.h>


float tempXY_temperature;
TemperatureNTC10K tempXY(8, 10000, 11000, 3950, 298.15, 4095, 3.3, -5);

float tempAB_temperature;
TemperaturePT1000 tempAB(5, 1.88, -26, 4095, 3.3);


void setup()
{
	tempXY.begin();
	tempAB.begin();
}

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