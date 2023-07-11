/* YourDuino Electronic Brick Test
Temperature Sensor DS18B20
- Connect cable to Arduino Digital I/O Pin 2
terry@yourduino.com */
#include <LiquidCrystal.h>
float vol = 0;
/*-----( Import needed libraries )-----*/
#include <OneWire.h>
#include <DallasTemperature.h>



LiquidCrystal lcd(49,48,47,46,45,44);

/*-----( Declare Constants )-----*/
#define ONE_WIRE_BUS 3 /*-(Connect to Pin 3 )-*/

/*-----( Declare objects )-----*/
/* Set up a oneWire instance to communicate with any OneWire device*/
OneWire ourWire(ONE_WIRE_BUS);

/* Tell Dallas Temperature Library to use oneWire Library */
DallasTemperature sensors(&ourWire);

/*-----( Declare Variables )-----*/

/*================================================================================================================================*/
void setup() /*----( SETUP: RUNS ONCE )----*/
{
/*-(start serial port to see results )-*/
 lcd.begin(16,2);
delay(1000);
Serial.begin(9600);

//Serial.println("Temperature Sensor DS18B20");
//delay(1000);

/*-( Start up the DallasTemperature library )-*/
sensors.begin();
}/*--(end setup )---*/

/*================================================================================================================================*/
void loop() /*----( LOOP: RUNS CONSTANTLY )----*/
{
Serial.println();
//Serial.print("Requesting temperature...");
sensors.requestTemperatures(); // Send the command to get temperatures


//Serial.print("Device 1 (index 0) = ");
//Serial.print(sensors.getTempCByIndex(0));
//Serial.println(" Degrees C");
//Serial.print("Device 1 (index 0) = ");
Serial.print(sensors.getTempFByIndex(0));
 lcd.clear();
lcd.print("Water Temp");
lcd.setCursor(0,1);
lcd.print(sensors.getTempFByIndex(0));
Serial.println(" Degrees F");
delay(1000);

}
