#include <LiquidCrystal.h>

const int rs = 8, en = 9, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // Menyetting karakter LCD baris & kolom:
  lcd.begin(16, 2);
  // Mengeprint text:
  lcd.print("Happy New Year! .New Year, New Me :)");
  delay(1000);
}

void loop() {
  // to move it offscreen left:
  for (int positionCounter = 0; positionCounter < 20; positionCounter++) {
    // scroll one position left:
    lcd.scrollDisplayLeft();
    delay(150);
  }
  // memberi delay diakhir dalam keseluruhan loop:
  delay(1000);
}