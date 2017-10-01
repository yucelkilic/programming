/*
 HC-SR04 Ping uzaklık sensörü ile park sensörü yapma:
 VCC => arduino 5v
 GND => arduino GND
 Echo => Arduino pin 7
 Trig => Arduino pin 6

 Bu kod tüm kamu kullanımına açıktır.
 e-posta: yucelkilic@antalyasinavkoleji.com
 */


#define echoPin 7 // Echo Pin
#define trigPin 6 // Trigger Pin
#define LEDPin 13 // LED Pin
#define buzzerPin 8 // Buzzer Pin

int maksimumUzaklik = 400; // Sensörün maksimum mesafe ölçümü
int minimumUzaklik = 0; // Sensörün minimum mesafe ölçümü
long sure, mesafe;

void setup() {
 Serial.begin (9600);
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);
 pinMode(LEDPin, OUTPUT);
 pinMode(buzzerPin, OUTPUT);
}

void loop() {
/* Aşağıdaki süreç en yakın cismin uzaklığını gönderilen ses dalgası ile
yansıyan ses dalgası arasındaki süreden hesaplamaktadır.*/
 digitalWrite(trigPin, LOW);
 delayMicroseconds(2);

 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10);

 digitalWrite(trigPin, LOW);
 // ses dalgasının geri dönmesi için geçen süre ölçülüyor
 sure = pulseIn(echoPin, HIGH);

 //cm cinsinden mesafe hesaplmama.
 mesafe = sure/58.2;

 if (mesafe >= maksimumUzaklik || mesafe <= minimumUzaklik){
 /* Sensörün algılamadığı sınır aralığı, uyarı olarak seri porttan "-1"
 gönder.*/
  Serial.println("-1");
 }
 else {
 /* Başarılı okuma sonucu LED ve buzzerı tetikle*/
  Serial.print("Uzaklık: ");
  Serial.print(mesafe); // cm biriminde.
  Serial.println(" cm");
  digitalWrite(LEDPin, HIGH);
  tone(buzzerPin, 440);
  delay(mesafe * 10);
  digitalWrite(LEDPin, LOW);
  noTone(buzzerPin);
  delay(mesafe * 10);
 }

 // Her okumada 50 ms bekle
 delay(50);
}
