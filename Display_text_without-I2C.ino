#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // Menyetting karakter LCD baris & kolom:
  lcd.begin(16, 2);
  // Mengeprint text:
  lcd.print("Hello World");
  delay(1000);
}

void loop() {
  
  // Menggeser karakter text ke kiri:
  for (int positionCounter = 0; positionCounter < 13; positionCounter++) {
    lcd.scrollDisplayLeft();
    delay(150);
  }

  // Menggeser karakter text ke kanan:
  for (int positionCounter = 0; positionCounter < 29; positionCounter++) {
    lcd.scrollDisplayRight();
    delay(150);
  }

  // Mengembalikan karakter text ke tengah:
  for (int positionCounter = 0; positionCounter < 16; positionCounter++) {
    // scroll one position left:
    lcd.scrollDisplayLeft();
    // wait a bit:
    delay(150);
  }
  // memberi delay diakhir dalam keseluruhan loop:
  delay(1000);

}
