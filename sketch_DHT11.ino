#include <DHT.h> // Gọi thư viện DHT
const int DHTPIN = 4; // Đọc dữ liệu từ DHT11 ở chân 2 của arduino
const int DHTTYPE = DHT11; //Khai báo loại cảm biến. Có 2 loại DHT11 và DHT22
DHT dht(DHTPIN, DHTTYPE);

#include <Wire.h>
#include<LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
//0x27 là địa chỉ màn hình trong bus I2C. Phần này chúng ta không cần phải quá bận tâm vì hầu hết màn hình (20x4,...) đều như thế này!
//16 là số cột của màn hình (nếu dùng loại màn hình 20x4) thì thay bằng 20
//2 là số dòng của màn hình (nếu dùng loại màn hình 20x4) thì thay bằng 4
void setup() {
  Serial.begin(9600);
  dht.begin();// Khởi động cảm biến

  lcd.init(); //Khởi động màn hình.
  lcd.backlight();//Bật đèn nền
}

void loop() {
 // Đọc nhiệt độ, độ ẩm từ DHT11
 float h = dht.readHumidity();
 float t = dht.readTemperature();
 // Hiển thị ra Serial Monitor
 Serial.print("DO AM: ");
 Serial.println(h);
 Serial.print("NHIET DO: ");
 Serial.println(t);
 Serial.println();
 delay(1000);
 // Hiển thị ra màn hình LCD
 lcd.setCursor(0,0);
 lcd.print("DO AM: ");
 lcd.setCursor(7,0);
 lcd.print(h);
 lcd.setCursor(12,0);
 lcd.print("%");
 lcd.setCursor(0,1);
 lcd.print("NHIET DO: ");
 lcd.setCursor(10,1);
 lcd.print(t);
 lcd.setCursor(14,1);
 lcd.print("C");
 delay(100);
 
 

}
