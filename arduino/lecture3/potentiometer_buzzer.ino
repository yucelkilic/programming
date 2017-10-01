/*
  AnalogReadSerial
  Pin A0'dan, potansiyometrenin gönderdiği analog değeri okur,
  Map fonksiyonu ile PWM dönüşümü 0-255 aralığında gerçekleşerek,
  Buzzer'a gönderilir. Buzzer'da gelen değer oranında ses çıkarır.
  Potansiyometrenin ortanca pinini A0'a bağlayınız.
  Dış pinlerinden birini +5V'a diğerini ground (GND)'ye bağlayınız.
  Buzzer'ın + ucunu ~3 numaralı pine. Diğerini ground (GND)'ye bağlayınız

  Bu kod tüm kamu kullanımına açıktır.
  e-posta: yucelkilic@antalyasinavkoleji.com
*/

// Reset tuşuna bastığınızda işleyecek rutinler:
void setup() {
  // A0 input olarak ayarlanıyor.
  pinMode(A0,INPUT);
  // PWM pinlerimizden 3.'sünü çıkış pini olarak ayarlıyoruz
  pinMode(3, OUTPUT);
  // Saniye'de 9600 bitlik bir seri iletişim başlatılıyor.
  Serial.begin(9600);
}

// Döngü sonsuza kadar çalışan kısım:
void loop() {
  // Analog girişlerden 0.'nın değeri okunuyor:
  int sensorDegeri = analogRead(A0);
  // Potansiyometre'den alınan değer map komutu ile PWM sınırlarına dönüştürülüyor.
  // Çünkü PWM çıkışları bu sınır aralığında çıkış verebiliyor.
  byte buzzerDegeri = map(sensorDegeri, 0, 1023, 0, 255);
  // Okunan 3. PWM pinin çıkış değeri ekrana yazdırılıyor
  Serial.println(buzzerDegeri);
  // Program kararlılığı için geçikme ekleniyor. Değer değişebilir.
  delay(100);
  // Buzzer'a ne miktarda ses çıkaracağı söylenmesi için değer gönderiliyor.
  analogWrite(3, buzzerDegeri);
}
