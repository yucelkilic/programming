/*
  AnalogReadSerial
  Pin A0'dan analog girişi değerini okur, Serial Monitor'e sonuçları yazdırır.
  Potansiyometrenin ortanca pinini A0'a bağlayınız.
  Dış pinlerinden birini +5V'a diğerini ground (GND)'ye bağlayınız.

  Bu kod tüm kamu kullanımına açıktır.
  e-posta: yucelkilic@antalyasinavkoleji.com
*/

// Reset tuşuna bastığınızda işleyecek rutinler:
void setup() {
  // A0 input olarak ayarlanıyor.
  pinMode(A0,INPUT);
  // Saniye'de 9600 bitlik bir seri iletişim başlatılıyor.
  Serial.begin(9600);
}

// Döngü sonsuza kadar çalışan kısım:
void loop() {
  // Analog girişlerden 0.'nın değeri okunuyor:
  int sensorDegeri = analogRead(A0);
  // Okunan değer yazdırılıyor:
  Serial.println(sensorDegeri);
  // Kararlılık için geçikme zamanı.
  delay(100);
}
