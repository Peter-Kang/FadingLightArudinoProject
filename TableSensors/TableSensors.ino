//Analog sensorPorts
int sensorPort0 = A0;
int sensorPort1 = A1;
int sensorPort2 = A2;
int sensorPort3 = A3;
int sensorPort4 = A4;
int sensorPort5 = A5;
//Moving average values
int sensorValue0 = 0;
int sensorValue1 = 0;
int sensorValue2 = 0;
int sensorValue3 = 0;
int sensorValue4 = 0;
int sensorValue5 = 0;
//Analog sensorPort Values / boolean value storage
int sensorPortValue0 = 0;
int sensorPortValue1 = 0;
int sensorPortValue2 = 0;
int sensorPortValue3 = 0;
int sensorPortValue4 = 0;
int sensorPortValue5 = 0;
// Threshhold values for each port
int sensorPort0Threshhold = 200;
int sensorPort1Threshhold = 150;
int sensorPort2Threshhold = 150;
int sensorPort3Threshhold = 200;
int sensorPort4Threshhold = 180;
int sensorPort5Threshhold = 180;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(38400); // baud rate
}

void loop() {
  //Read in the values
  sensorPortValue0 = analogRead(sensorPort0);
  sensorPortValue1 = analogRead(sensorPort1);
  sensorPortValue2 = analogRead(sensorPort2);
  sensorPortValue3 = analogRead(sensorPort3);
  sensorPortValue4 = analogRead(sensorPort4);
  sensorPortValue5 = analogRead(sensorPort5);
  //Average the values
  sensorValue0 = (sensorPortValue0 + sensorValue0 )/2;
  sensorValue1 = (sensorPortValue1 + sensorValue1 )/2;
  sensorValue2 = (sensorPortValue2 + sensorValue2 )/2;
  sensorValue3 = (sensorPortValue3 + sensorValue3 )/2;
  sensorValue4 = (sensorPortValue4 + sensorValue4 )/2;
  sensorValue5 = (sensorPortValue5 + sensorValue5 )/2;
  // Threshhold the values
  sensorPortValue0 = (int) sensorValue0 > sensorPort0Threshhold;
  sensorPortValue1 = (int) sensorValue1 > sensorPort1Threshhold;
  sensorPortValue2 = (int) sensorValue2 > sensorPort2Threshhold;
  sensorPortValue3 = (int) sensorValue3 > sensorPort3Threshhold;
  sensorPortValue4 = (int) sensorValue4 > sensorPort4Threshhold;
  sensorPortValue5 = (int) sensorValue5 > sensorPort5Threshhold;

  // Print findings
  //Add up the values and see if they are above the threshhold
  int totalValue = sensorPortValue0 + sensorPortValue1 + sensorPortValue2 + sensorPortValue3 + sensorPortValue4 + sensorPortValue5;
  //Serial.println((String)"Total Value: "+totalValue);
  //send the value over bluetooth
  Serial.write(totalValue);
  Serial.flush();

  //Loop Delay timer
  delay(500);//delay in miliseconds
}
