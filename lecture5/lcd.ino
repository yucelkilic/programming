/*
 Arduino ile LCD ekran kullanımı
 Bu kod tüm kamu kullanımına açıktır.
 e-posta: yucelkilic@antalyasinavkoleji.com
 */

#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);

void setup() {
lcd.begin(16,2);
lcd.clear();
lcd.print("Merhaba Dunya!");
}

void loop() {

}
