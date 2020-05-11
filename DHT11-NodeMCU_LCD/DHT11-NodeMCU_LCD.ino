#include <LiquidCrystal_I2C.h>
#include <DHT.h>
#define DHTPIN D4
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  // initialize DHT11
  dht.begin();
  // initialize the LCD
  lcd.begin();
  // Turn on the blacklight
  lcd.backlight();
}

void loop() {
  // put your main code here, to run repeatedly:
  float temp = dht.readTemperature();
  float humi = dht.readHumidity();
  Serial.print("Temp: ");
  Serial.print(temp);
  Serial.print("  Humi: ");
  Serial.println(humi);

  // LCD Display
  lcd.setCursor(0,0);
  lcd.print("Temp : ");
  lcd.print(temp);

  // LCD cursor change
  lcd.setCursor(0,1);
  lcd.print("Humi : ");
  lcd.print(humi);
  
  delay(1000);

}
