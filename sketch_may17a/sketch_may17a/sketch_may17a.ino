
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

const char* ssid=" 와이파이 이름 "; // 와이파이 이름, 비밀번호
const char* password = "와이파이 비밀번호";

String url = "http://www.kma.go.kr/wid/queryDFSRSS.jsp?zone=4119060300"; // 파싱할 url

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid,password);
  while (WiFi.status() != WL_CONNECTED){
      delay(500);
      Serial.print(".");
  }
  Serial.println(" ");
  Serial.println("WiFi connected");
  Serial.println(" IP address : ");
  Serial.println(WiFi.localIP());
}

void loop() {
  // put your main code here, to run repeatedly:

}
