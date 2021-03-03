#include <DHT.h>
#include <DHT_U.h>

#define DHTPIN 2
#define DHTTYPE DHT22
#define ATOMIZER 7

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ATOMIZER, OUTPUT);
  dht.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(2000); //DHT22 response time = 2000 ms, DHT11 response time = 1000 ms
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  if (isnan(h) || isnan(t)){
    Serial.println("Failed to read from DHT Sensor!");
    return;
  }
  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" % || ");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.print(" \xC2\xB0");
  Serial.print("C\n");

  //Change 20 to your own number
  if (h <= 20){
    //The water atmoizer will turn ON if the humidity is too low
    digitalWrite(ATOMIZER, HIGH);  
  }
  else {
    //The water atomizer will not turn on if the humidity is over the number you set
    digitalWrite(ATOMIZER, LOW); 
   }
}
