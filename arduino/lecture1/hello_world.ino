void setup() {
  // Seri iletişim hızı yaklaşık olarak 1000 karakter olarak başlatılır.
  Serial.begin(9600);
}

void loop() {
  // Ekrana yazı yazdırıp, satır atlıyor.
  Serial.println(“Merhaba Dünya!”);
  // Döngü içindeki bekleme zamanı
  delay(1000);
}
