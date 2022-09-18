#include <SoftwareSerial.h>
SoftwareSerial softSerial(2, 3); // RX, TX
 
void setup() 
{
  uint32_t baud = 115200;
  Serial.begin(baud);
  softSerial.begin(baud);
  Serial.print("SETUP!! @");
  Serial.println(baud);
}
 
void loop() 
{
    while(softSerial.available() > 0) 
    {
      char a = softSerial.read();
      if(a == "")
        continue;
      if(a != 'r' && a != 'n' && (a < 32))
        
        continue;
      Serial.print(a);
      if(softSerial.available()==1)
      {
        Serial.println();
      }
    }
    
    while(Serial.available() > 0)
    {
      char a = Serial.read();
      Serial.write(a);
      softSerial.write(a);
    }
}
