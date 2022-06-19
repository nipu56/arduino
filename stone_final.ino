#include <Adafruit_NeoPixel.h> // 네오픽셀 사용을 위한 라이브러리 
#include<SoftwareSerial.h> // 블루투스 통신 사용을 위한 라이브러리
#ifdef __AVR__
 #include <avr/power.h>
#endif
#define PIN            13 //네오픽셀의 핀번호
#define NUMPIXELS      3  // 네오픽셀의 비트개수

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800); // 네오픽셀 핀설정, 픽셀의 개수, 핀의 위치
String r;
String g;
String b;

SoftwareSerial BTSerial = SoftwareSerial(9,10);
void setup() {
  pixels.begin();
  BTSerial.begin(115200); //블루투스 4.0 통신을 위한 통신값
  
}

void loop() {
   if (BTSerial.available() > 0) {
    String strData = BTSerial.readStringUntil('\n'); // 블루투스 통신으로 값을 받음 ex)255,255,255 ~ 0,0,0
    int first = strData.indexOf(",");  // 수신받은 데이터를 rgb 색상으로 쪼개기 위해 사용할 문자
    int second = strData.indexOf(",",first+1);
    
    r = (strData.substring(0,first)); //처음위치부터 ,까지 ex)255
    g = (strData.substring(first+1,second)); //, 다음 위치부터 ,까지 ex)255
    b = (strData.substring(second+1,strData.length())) ;  //,부터 마지막까지 ex)255
    
    for(int i=0;i<NUMPIXELS;i++){
     pixels.setPixelColor(i, pixels.Color(r.toInt(),g.toInt(),b.toInt())); // string 값을 인트형으로 변
      pixels.show(); //
      delay(500);
    }
}
}
