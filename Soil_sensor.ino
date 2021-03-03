#define SOILPOWER 4
#define SOILREAD A0

void setup() {
  Serial.begin(9600);
  pinMode(SOILPOWER, OUTPUT);
  
}

//Create a function returns the soil moisture level from Analog read
int readSoil(){
    digitalWrite(SOILPOWER, HIGH);
    delay(10);
    int val = analogRead(SOILREAD);
    digitalWrite(SOILPOWER, LOW);
    return val;
}

void loop() {
  // put your main code here, to run repeatedly:
  int s = readSoil();
  if (isnan(s)){
    Serial.print("Soil sensor is connected incorrectly.\n");  
  }
  Serial.print("Soil: ");
  Serial.print(s);
  Serial.print("\n");
} 
