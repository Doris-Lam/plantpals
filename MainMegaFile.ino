#include <Wire.h>
#include "SparkFunHTU21D.h"

//Soil Mosture Declrations
#define SensorPin A0 
float sensorValue = 0;

//Create an instance of the object
HTU21D myHumidity;


void setup()
{
  Serial.begin(9600);


  myHumidity.begin();
}

void loop()
{
  //Humidity and Sensor Value
  float humd = myHumidity.readHumidity();
  float temp = myHumidity.readTemperature();

  Serial.print("Temperature:");
  Serial.print(temp, 1);
  Serial.print("C");
  Serial.print(" Humidity:");
  Serial.print(humd, 1);
  Serial.print("%");

  Serial.println();

  //Soil Moisture Sensor
   for (int i = 0; i <= 100; i++) 
 { 
   sensorValue = sensorValue + analogRead(SensorPin); 
   delay(1); 
 } 
 sensorValue = sensorValue/100.0; 
 Serial.print("Soil Moisture: ");
 Serial.println(sensorValue); 

 //Light Sensor
 int analogValue = analogRead(A3);

  Serial.print("Light: ");
  Serial.print(analogValue);   // the raw analog reading

  // We'll have a few threshholds, qualitatively determined
  if (analogValue < 10) {
    Serial.println(" - Dark");
  } else if (analogValue < 200) {
    Serial.println(" - Dim");
  } else if (analogValue < 500) {
    Serial.println(" - Light");
  } else if (analogValue < 800) {
    Serial.println(" - Bright");
  } else {
    Serial.println(" - Very bright");
  }

  delay(1000);
}
