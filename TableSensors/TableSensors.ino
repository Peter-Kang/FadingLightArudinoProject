#include <SoftwareSerial.h>

//Analog sensorPorts
int sensorPort0 = 0;
int sensorPort1 = 1;
int sensorPort2 = 2;
int sensorPort3 = 3;
int sensorPort4 = 4;
int sensorPort5 = 5;
//Analog sensorPort Values
int sensorPortValue0 = 0;
int sensorPortValue1 = 0;
int sensorPortValue2 = 0;
int sensorPortValue3 = 0;
int sensorPortValue4 = 0;
int sensorPortValue5 = 0;
//Max Total Value
int maxTotalValue = 1000;

//Loop Delay timer
int waitDelayTimeInMS = 500;

//Bluetooth stuff, this is where we start and send data over.
SoftwareSerial Bluetooth(3,2);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); // baud rate
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
  Serial.println((String)"Values: " +sensorPort0+", "+sensorPort1+", "+ sensorPort2+", "+sensorPort3+", "+sensorPort4+", "+sensorPort5+".\n"); 
  //Add up the values and see if they are above the threshhold
  int totalValue = sensorPortValue0 + sensorPortValue1 + sensorPortValue2 + sensorPortValue3 + sensorPortValue4 + sensorPortValue5;
  Serial.println((String) "Total: " + totalValue);

  double percent = 0.0;
  percent = totalValue / maxTotalValue;
  //send the value over bluetooth
  bluetooth.write(percent);

  delay(waitDelayTimerInMS);//delay in miliseconds
}
