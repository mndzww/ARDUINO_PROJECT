#include <LiquidCrystal.h>

LiquidCrystal lcd(1, 2, 4, 5, 6, 7); 
// Mendeklarasi LCD objek menjadi parameter : (rs, enable, d4, d5, d6, d7)
const int trigPin = 9;
const int echoPin = 10;
long duration;
int distanceCm;

void setup() {
  // Mendeklarasikan tampila LCD dengan spesifikasi pixel (tinggi & lebar)
  lcd.begin(16,2); 
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distanceCm= (duration*0.034) /2;
  // Mengatur sekuensial/bagian pixel text display LCD
  lcd.setCursor(0,0); 
  lcd.print("Jarak: "); 
  lcd.print(distanceCm); 
  lcd.print(" cm");
  delay(10);
}