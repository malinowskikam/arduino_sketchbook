#include <DHT11.h>

DHT11 dht11(3);

void setup()
{
  Serial.begin(9600);
  Serial.println("DHT11"); 
}
void loop()
{
  int temperature, humidity;

  int result = dht11.readTemperatureHumidity(temperature, humidity);

  if (result == 0) {
    Serial.print("Temperature:");
    Serial.print(temperature);
    Serial.print(" ,Humidity:");
    Serial.println(humidity);
  } else {
    Serial.println(DHT11::getErrorString(result));
  }
  delay(1000);                                  //opóźnienie między kolejnymi odczytami - 1 s
} 