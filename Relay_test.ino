/*Readme:
This code consist of 3 different tests. Make sure you comment out the unused test and leave only one at a time
Test 1 - Turns 1 motor on/off every 5 seconds.
Test 2 - Turns 2 motor on/off alternatively every 5 seconds. 
Test 3 - Turns fan and pump on/off alternatively every 5 seconds.
*/

#define MOTOR 9 //test 1 and 2
#define MOTOR2 10 //test 2
//***Uncomment the following and comment the above MOTOR, MOTOR2 for test 3****
/*
#define FAN 9 //test 3
#define PUMP 10 //test 3
*/

void setup() {
  // put your setup code here, to run once:
  pinMode(MOTOR, OUTPUT); //test 1
  pinMode(MOTOR2, OUTPUT); //test 1 and 2

  pinMode(PUMP, OUTPUT); //test 3
  pinMode(FAN, OUTPUT);  //test 3
}

void loop() {
  //-------------------Test 1 - one Motor test-----------------------------------
  //The motor should turn on and off alternatively
  digitalWrite(MOTOR, HIGH);
  delay(5000);
  digitalWrite(MOTOR, LOW);

  //-------------------Test 2 - Two motors test----------------------------------
  //Two motors should turn on and off alternatively
  digitalWrite(MOTOR, LOW);
  digitalWrite(MOTOR2, HIGH);
  delay(5000);
  digitalWrite(MOTOR, HIGH);
  digitalWrite(MOTOR2, LOW);

  
  //-------------------Test 3 - Fan and Pump test--------------------------------
  //Fan and pump should turn on and off alternatively
  digitalWrite(PUMP, HIGH);
  digitalWrite(FAN, LOW);
  delay(5000);
  digitalWrite(PUMP, LOW);
  digitalWrite(FAN, HIGH);
}
