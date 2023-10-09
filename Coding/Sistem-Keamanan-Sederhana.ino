#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);  // Alamat I2C LCD: 0x27, Jumlah kolom: 16, Jumlah baris: 2

const int pirPin = 2; // Pin sensor PIR
const int ledMerahPin = 3; // Pin LED
const int ledHijauPin = 4; // Pin LED

void setup() {
  pinMode(pirPin, INPUT);
  pinMode(ledMerahPin, OUTPUT);
  pinMode(ledHijauPin, OUTPUT);

  lcd.init(); // Inisialisasi LCD
  lcd.backlight(); // Aktifkan backlight LCD
  lcd.clear(); // Bersihkan layar LCD
  lcd.setCursor(5, 0);
  lcd.print("Status:");
}

void loop() {
  int pirState = digitalRead(pirPin);
  
  if (pirState == HIGH) { // Gerakan terdeteksi
    lcd.setCursor(0, 1);
    lcd.println("Terdeteksi Orang");
    digitalWrite(ledMerahPin, HIGH); // Nyalakan LED
    digitalWrite(ledHijauPin,LOW);
    delay(1000); // Beri waktu untuk LED menyala
    digitalWrite(ledMerahPin, LOW); // Matikan LED

  } else { // Tidak ada gerakan yang terdeteksi
    lcd.setCursor(0, 1);
    lcd.println("     Normal     ");
    digitalWrite(ledHijauPin,HIGH);
  }
}
