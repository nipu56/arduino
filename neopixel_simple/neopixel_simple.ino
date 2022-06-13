#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif
#define PIN            13
#define NUMPIXELS      3

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int delayval = 500;
SoftwareSerial BT(2, 3);
void setup() {
  if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
  pixels.begin();
  Serial.begin(9600);
  BT.begin(9600);
  
}

void loop() {
   if (BT.available() > 2) { // 수신받은 데이터가 2개 초과일 때
    r = BT.read();          // 첫번째 데이A터는 r에 저장(R의 RGB값)
    g = BT.read();          // 두번째 데이터는 g에 저장(G의 RGB값)
    b = BT.read();          // 세번째 데이터는 b에 저장(B의 RGB값)
    
    BT.flush();   // 통신 내용 초기화
  
    Serial.print("Red = "); // 시리얼 모니터에 RGB값 출력
    Serial.println (r);
    Serial.print("Green = ");
    Serial.println(g);
    Serial.print("Blue = ");
    Serial.println(b);
     for(int i=0;i<NUMPIXELS;i++){
      pixels.setPixelColor(i, pixels.Color(r,g,b));
      pixels.show(); //
      delay(500);
    }
}
