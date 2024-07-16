int noiseBin = 12;
int noiseInput = A0;

void setup() {
  Serial.begin(9600);
  Serial.println("Noice detection");
  pinMode(noiseInput, INPUT);
  pinMode(noiseBin, INPUT);
}

void loop() {
  Serial.print("Noise: ");
  Serial.print(digitalRead(noiseBin));
  Serial.print(", Level: ");
  Serial.println(analogRead(noiseInput));
  delay(200);
}
