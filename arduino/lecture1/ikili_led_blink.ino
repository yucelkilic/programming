void setup() {
  // LED’e güç vereceğimiz çıkış pini belirtiliyor.
  pinMode(4, OUTPUT);
  pinMode(8, OUTPUT);

}

void loop() {
  // 4 numaralı pine güç veriyoruz.
  digitalWrite(4, HIGH);
  // 8 numaralı pinden gücü kesiyoruz.
  digitalWrite(8, LOW);
  // Gecikme zamanı.
  delay(500);
  // 4 numaralı pinden gücü kesiyoruz.
  digitalWrite(4, LOW);
  // 8 numaralı pine güç veriyoruz.
  digitalWrite(8, HIGH);
  delay(500);

}
