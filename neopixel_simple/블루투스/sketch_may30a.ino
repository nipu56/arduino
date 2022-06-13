#include <SoftwareSerial.h>

SoftwareSerial BTserial(4,5);

void setup()
{
  Serial.begin(9600);
  Serial.println("HELLO");
  BTserial.begin(9600);
}

void loop()
{
  while (BTserial.available())
  {
    byte data = BTserial.read();
    Serial.write(data);
  }
    while (Serial.available())
  {
    byte data = Serial.read();
    BTserial.write(data);
  }
  
}
