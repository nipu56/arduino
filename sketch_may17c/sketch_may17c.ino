int seg_pin[]= {10,11,12,13};
int seg[] = {2,3,4,5,6,7,8,9};
int delayTime = 5;
byte data[] = {0xFC, 0x60, 0xDA, 0xF2, 0x66, 0xB6, 0xBE, 0xE4, 0xFE, 0xE6};
void setup() {
  for (int i=0; i < 4;i++)
  {
    pinMode(seg_pin[i],OUTPUT);
  }
  for (int i=0; i<8;i++)
  {
    pinMode(seg[i],OUTPUT);
  }

}



void loop()
{
  show(4,1);                //첫 번째 자리, 1출력
  delay(delayTime);         //0.005초 일시정지
  show(3,2);                //두 번째 자리, 2출력
  delay(delayTime);         //0.005초 일시정지
  show(2,3);                //세 번째 자리, 3출력
  delay(delayTime);         //0.005초 일시정지
  show(1,4);                //네 번째 자리, 4출력
  delay(delayTime);
}
void show(int position, int number) {
  //4자리 중 원하는 자리 선택
  for(int i = 0; i < 4; i++) {
    if(i + 1 == position){
      digitalWrite(seg_pin[i], LOW);
    } else {
      digitalWrite(seg_pin[i], HIGH);
    }
  }

  //8개 세그먼트를 제어해서 원하는 숫자 출력
  for(int i = 0; i < 8; i++){
     byte segment = (data[number] & (0x01 << i)) >> i;
     if(segment == 1){
       digitalWrite(seg[7-i], HIGH);
     } else {
       digitalWrite(seg[7 - i], LOW);
     }
  }
}
