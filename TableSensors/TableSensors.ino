//Analog sensorPorts
int sensorPort0 = A0;
int sensorPort1 = A1;
int sensorPort2 = A2;
int sensorPort3 = A3;
int sensorPort4 = A4;
int sensorPort5 = A5;
//Analog sensorPort Values
int sensorPortValue0 = 0;
int sensorPortValue1 = 0;
int sensorPortValue2 = 0;
int sensorPortValue3 = 0;
int sensorPortValue4 = 0;
int sensorPortValue5 = 0;


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
  // Print findings
  //Serial.println((String)"Values: " +sensorPortValue0+", "+sensorPortValue1+", "+ sensorPortValue2+", "+sensorPortValue3+", "+sensorPortValue4+", "+sensorPortValue5+"."); 
  //Add up the values and see if they are above the threshhold
  int totalValue = sensorPortValue0 + sensorPortValue1 + sensorPortValue2 + sensorPortValue3 + sensorPortValue4 + sensorPortValue5;
  double ratio = totalValue/2500.0;
  if(ratio > 1.0)
  {
    ratio =1.0;
  }
  int brightness = ratio*255;
  //Serial.println((String) "Brightness: " + brightness);
  //send the value over bluetooth
  Serial.write(brightness);
  Serial.flush();

  //Loop Delay timer
  delay(500);//delay in miliseconds
}
