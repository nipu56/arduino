#include <Adafruit_NeoPixel.h>
#include<SoftwareSerial.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif
#define PIN            13
#define NUMPIXELS      3

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
int r;
int g;
int b;

SoftwareSerial BTSerial = SoftwareSerial(9,10);
void setup() {
  pixels.begin();
  Serial.begin(115200);
  BTSerial.begin(115200);
  
}

void loop() {
   if (BTSerial.available() > 0) { // 수신받은 데이터가 2개 초과일 때
    String strData = BTSerial.readStringUntil('\n');
    Serial.println(strData.toInt());
    r = (strData.toInt() / 1000000);
    g = (strData.toInt() / 1000 - r * 1000);
    b = (strData.toInt() - r * 1000000 - g * 1000) ; 
 


    Serial.println(r);
    Serial.println(g);
    Serial.println(b);
    
  
     for(int i=0;i<NUMPIXELS;i++){
      pixels.setPixelColor(i, pixels.Color(r,g,b));
      pixels.show(); //
      delay(500);
    }
}
}
