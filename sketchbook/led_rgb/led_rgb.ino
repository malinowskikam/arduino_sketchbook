int ledR = 6;
int ledG = 3;
int ledB = 5;

void setup() {
  pinMode(ledR, OUTPUT);
  pinMode(ledG, OUTPUT);
  pinMode(ledB, OUTPUT);

  // digitalWrite(ledR, HIGH);
  // digitalWrite(ledG, HIGH);
  // digitalWrite(ledB, HIGH);

  analogWrite(ledR, 255);
  analogWrite(ledG, 0);
  analogWrite(ledB, 0);
}

void loop() {
  analogWrite(ledR, 255);
  analogWrite(ledG, 0);
  analogWrite(ledB, 0);

  delay(1000);
  for (int i = 0; i < 256; i++) {
    delay(10);
    analogWrite(ledG, i);
  }
  delay(1000);
}