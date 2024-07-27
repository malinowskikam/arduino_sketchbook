#include <SoftwareSerial.h>

#define BT_RX 11
#define BT_TX 10

#define TEMP_PIN A1

SoftwareSerial mySerial(BT_TX, BT_RX); // RX, TX

void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);
  
}

void loop()
{
  float read = 0;
  for(int i = 0; i < 64; i++) {
    read += analogRead(TEMP_PIN);
    delay(5);
  }
  float temp = (read * 500.0) / (1024.0 * 64);
  // float temp = analogRead(A1) * 500.0 / 1024.0;
  Serial.println(temp);
  mySerial.println(temp);
  // if (mySerial.available()) Serial.write(mySerial.read());
  // if (Serial.available()) mySerial.write(Serial.read());
  delay(1000);
}
