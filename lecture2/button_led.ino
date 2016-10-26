// LED pinlerini ve buton pinlerini tanımlıyoruz.
const int LEDyellowPin = 11;
const int LEDredPin = 12;
const int buttonPin = 2;
int butonDurumu = 0;

void setup() {
// Buton pinini dijital giriş olarak tanımlıyoruz.
  pinMode(buttonPin, INPUT);
  digitalWrite(buttonPin, HIGH);
// LED pinini dijital çıkış olarak tanımlıyoruz.
  pinMode(LEDyellowPin, OUTPUT);
  pinMode(LEDredPin, OUTPUT);
  // Serial port ile iletişimi başlatıyoruz.
  Serial.begin(9600);

}

void loop() {
// Buton durumunu okuyoruz.
  butonDurumu = digitalRead(buttonPin);
  // Buton durumunu ekrana yazdırıyoruz.
  Serial.println(butonDurumu);

  /* Butona basıldığında buton durumu digital 0 (LOW) olacaktır.
  Bu durumda LED çıkışlarını digital 1 (HIGH) yapıyoruz.

  */
  if (butonDurumu == HIGH)
  {
    digitalWrite(LEDredPin, LOW);
    digitalWrite(LEDyellowPin, HIGH);
  }else
  {
    digitalWrite(LEDredPin, HIGH);
    digitalWrite(LEDyellowPin, LOW);
  }
}
