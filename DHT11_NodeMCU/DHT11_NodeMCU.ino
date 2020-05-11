#include <DHT.h>
#define DHTPIN D4
#define DHTTYPE DHT11

// DHT11 객체 생성
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // 시리얼 통신으로 데이터를 PC로 보내기 초기화, 9600 baud 속도 
  Serial.begin(9600);
  
  // DHT11 초기화
  dht.begin();
}

void loop() {
  float temp = dht.readTemperature();
  float humi = dht.readHumidity();
  Serial.print("Temp: ");
  Serial.print(temp);
  Serial.print("    Humi: ");
  Serial.println(humi);
  delay(1000);
}
