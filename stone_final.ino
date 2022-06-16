#include <Adafruit_NeoPixel.h>
#include<SoftwareSerial.h>
#ifdef __AVR__
 #include <avr/power.h>
#endif
#define PIN            13
#define NUMPIXELS      3

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800); // 네오픽셀 핀설정, 픽셀의 개수, 핀의 위치
String r;
String g;
String b;

SoftwareSerial BTSerial = SoftwareSerial(9,10);
void setup() {
  pixels.begin();
  BTSerial.begin(115200);
  
}

void loop() {
   if (BTSerial.available() > 0) { // 수신받은 데이터가 2개 초과일 때
    
    String strData = BTSerial.readStringUntil('\n');
    int first = strData.indexOf(",");
    int second = strData.indexOf(",",first+1);
    
    r = (strData.substring(0,first));
    g = (strData.substring(first+1,second));
    b = (strData.substring(second+1,strData.length())) ; 
    
    for(int i=0;i<NUMPIXELS;i++){
     pixels.setPixelColor(i, pixels.Color(r.toInt(),g.toInt(),b.toInt()));
      pixels.show(); //
      delay(500);
    }
}
}
