#include <DHT.h>
#include <DHT_U.h>
/*
Author: Julia Chen
Notes: 
This is testing code for the greenhouse setup. Change the if/else conditions based on need. 
The define pins are based on the hardware setup in the folder.
Please change the pin numbers if any hardware setup has been modified. 
For DHTTYPE: this is for DHT22, but change to DHT11 if using DHT11 in the physical setup.
You can change the SOILREAD pin to any ANALOG pin on the arduino board.
*/
#define FAN 2
#define PUMP 3
#define SOILREAD A0
#define SOILPWR 4
#define DHTPIN 5
#define DHTTYPE DHT22 
#define ATOM 6

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  //setup code, to run once:
  Serial.begin(9600);
  pinMode(SOILPWR, OUTPUT);
  pinMode (FAN, OUTPUT);
  pinMode (PUMP, OUTPUT);
  pinMode(ATOM, OUTPUT);
  pinMode (SOILREAD, INPUT);
  dht.begin();
}
int readSoil(){
  digitalWrite(SOILPWR, HIGH); //power on the soil
  delay(10);
  int val = analogRead(SOILREAD); //Analog read to get the sensor value
  digitalWrite(SOILPWR, LOW); //turn off the soil sensor
  return val;
}

//Run repeatedly
void loop() {
  int s = readSoil();
  float t = dht.readTemperature();
  float h = dht.readHumidity();
  
  delay(2000); //Give the sensor some time to respond
  
  if (isnan(t) || isnan(h)){
    Serial.print("DHT22 not connected");  
  }
  if (isnan(s)){
    Serial.print("Soil Sensor not connected");
  }
  Serial.print("Temperature:");
  Serial.print(t);
  Serial.print(" \xC2\xB0");
  Serial.print(" C \\");
  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print("%\n");
  Serial.print("Soil: ");
  Serial.print(s);
  Serial.print("\n");
  
  //--------------------HUMIDITY------------------------
  //humidity larger than "20" %
  if (h > 20){
    Serial.print("Atomizer On\n");
    digitalWrite(ATOM, 1);
  }
  else {
    Serial.print("Atomizer Off\n");
    digitalWrite(ATOM, 0);
  }
  //--------------------SOIL------------------------
  //Soil level larger than "200" 
  if (s > 200){
    Serial.print("Pump On\n");
    digitalWrite(PUMP, HIGH);
  }
  else {
    Serial.print("Pump Off\n");
    digitalWrite(PUMP, LOW);
   }
  //--------------------TEMPERATURE-------------------
  //temperature larger than "20" degree Celsius
  if (t > 20){ 
   Serial.print("Fan On\n");
   digitalWrite(FAN, 1);
  }
  else {
   Serial.print("Fan Off\n");
   digitalWrite(FAN, 0);
  }  
 
}
