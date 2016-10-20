void setup() {
  // LED’e güç vereceğimiz çıkış pini belirtiliyor.
  pinMode(4, OUTPUT);

}

void loop() {
  // 4 numaralı pine güç veriyoruz.
  digitalWrite(4, HIGH);
  // Gecikme zamanı.
  delay(500);
  // 4 numaralı pinden gücü kesiyoruz.
  digitalWrite(4, LOW);
  delay(500);

}
