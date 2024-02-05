#include <Servo.h> 
Servo horizontal; // servo sumbu horizontal
int servoh = 180; 
int servohLimitHigh = 175;
int servohLimitLow = 5;


Servo vertical; // servi sumbu vertikal
int servov = 45; 
int servovLimitHigh = 100;
int servovLimitLow = 1;

// LDR pin connections
// name = analogpin;
int ldrlt = A0; //LDR top left - BOTTOM LEFT <--- BDG
int ldrrt = A3; //LDR top rigt - BOTTOM RIGHT
int ldrld = A1; //LDR down left - TOP LEFT
int ldrrd = A2; //ldr down rigt - TOP RIGHT

void setup(){
horizontal.attach(9);
vertical.attach(10);
horizontal.write(180);
vertical.write(45);
delay(2500);
}
void loop() {
int lt = analogRead(ldrlt);
int rt = analogRead(ldrrt);
int ld = analogRead(ldrld);
int rd = analogRead(ldrrd);
int dtime = 10; int tol = 90;
int avt = (lt + rt) / 2;
int avd = (ld + rd) / 2;
int avl = (lt + ld) / 2;
int avr = (rt + rd) / 2;
int dvert = avt - avd; 
int dhoriz = avl - avr; 

if (-1*tol > dvert || dvert > tol) 
 {
 if (avt > avd)
 {
 servov = ++servov;
 if (servov > servovLimitHigh)
 {servov = servovLimitHigh;}
 }
 else if (avt < avd)
 {servov= --servov;
 if (servov < servovLimitLow)
 { servov = servovLimitLow;}
 }
 vertical.write(servov);
 }
if (-1*tol > dhoriz || dhoriz > tol) //pengecekan perbedaan toleransi disaat mengubah sudut horizontal
 {
 if (avl > avr)
 {
 servoh = --servoh;
 if (servoh < servohLimitLow)
 {
 servoh = servohLimitLow;
 }
 }
 else if (avl < avr)
 {
 servoh = ++servoh;
 if (servoh > servohLimitHigh)
 {
 servoh = servohLimitHigh;
 }
 }
 else if (avl = avr)
 {
 delay(5000);
 }
 horizontal.write(servoh);
 }
 
 delay(dtime);
 
}
