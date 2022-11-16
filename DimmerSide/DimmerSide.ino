//#include <RBDdimmer.h>
//LED locations
int led = 10;         // the PWM pin the LED is attached to
int inverseled = 9;
//Constants
int maxValue = 6;
  //Dimmer values
int minPWM = 0;
int maxPWN = 255;

int Message = 0;
int inverseMessage =0;

//dimmerLamp dimmer(led);
//dimmerLamp inverseDimmer(inverseled);

// the setup routine runs once when you press reset:
void setup() {
  // declare pin 9 to be an output:
  pinMode(led, OUTPUT);
  pinMode(inverseled, OUTPUT);
  //inverseDimmer.begin(NORMAL_MODE, ON);
  //dimmer.begin(NORMAL_MODE, ON);
  Serial.begin(38400); // baud rate
}

// the loop routine runs over and over again forever:
void loop() {
 
  //Take a message from the bluetooth device
  Serial.flush();
  if(Serial.available() > 0){ // Checks whether data is comming from the serial port
    Message = Serial.read(); // Reads the data from the serial port
    inverseMessage = maxValue-Message;
    Serial.println(Message);
  }
  //Convert Message value to Dimmer Value
      //Ratio
  //double ratio = (double)Message/(double)maxValue;
  //double inverseRatio = 1-ratio;
    //Dimmer value results
  //int DimmerValue = (ratio*maxPWN);
  //int inverseDimmerValue = (inverseRatio*maxPWN);
  //Serial.println( (String) "Dimmer: " + DimmerValue+  " InverseDimmer: "+ inverseDimmerValue );

  //inverseDimmer.setPower(inverseDimmerValue);
  //dimmer.setPower(DimmerValue);
  //analogWrite(led, DimmerValue);
  //analogWrite(inverseled, inverseDimmerValue);
if(Message >= 4) 
{
 digitalWrite(led,  HIGH);
 digitalWrite( inverseled, LOW);
}
else
{
digitalWrite(led,  LOW);
 digitalWrite( inverseled, HIGH);  
}
 //digitalWrite(led, DimmerValue );
 //digitalWrite( inverseled, inverseDimmerValue);

  // wait for 30 milliseconds to see the dimming effect
  delay(500);
}

/*
//#include <RBDdimmer.h>
//LED locations
int led = 10;         // the PWM pin the LED is attached to
int normallyOn = 9;
//Constants
int maxValue = 6;
  //Dimmer values
int minPWM = 0;
int maxPWN = 250;


int Message = 0;
int lastMessage =-1;

//dimmerLamp dimmer(led);
//dimmerLamp inverseDimmer(inverseled);

// the setup routine runs once when you press reset:
void setup() {
  // declare pin 9 to be an output:
  pinMode(led, OUTPUT);
  pinMode(normallyOn, OUTPUT);
  //inverseDimmer.begin(NORMAL_MODE, ON);
  //dimmer.begin(NORMAL_MODE, ON);
  Serial.begin(38400); // baud rate
}

// the loop routine runs over and over again forever:
void loop() {
 
  //Take a message from the bluetooth device
  //Serial.flush();
  if(Serial.available() > 0){ // Checks whether data is comming from the serial port
    Message = Serial.read(); // Reads the data from the serial port
    Serial.println(Message);
  }
  
    //Dimmer value results
  if( (lastMessage == -1 && Message != 0 )|| lastMessage != Message )
  {
    //Convert Message value to Dimmer Value
      //Ratio
    double ratio = (double)Message/(double)maxValue;
    double inverseRatio = 1-ratio;
    int DimmerValue = (int)(maxPWN * ratio);//map(Message, 0, maxValue, 0, maxPWN); ;
    int inverseDimmerValue = (int)(maxPWN * inverseRatio);//map(maxValue-Message, 0, maxValue, 0, maxPWN); ;;
    Serial.println( (String) "Dimmer: " + DimmerValue+  " Normally on: "+ inverseDimmerValue );
    //inverseDimmer.setPower(inverseDimmerValue);
    //dimmer.setPower(DimmerValue);
    analogWrite(led, DimmerValue);
    analogWrite(normallyOn, inverseDimmerValue);
    lastMessage = Message;
//digitalWrite(led, DimmerValue );
//digitalWrite( inverseled, inverseDimmerValue);
  }
  // wait for 30 milliseconds to see the dimming effect
  delay(1000);
}*/