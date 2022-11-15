//#include <RBDdimmer.h>
//LED locations
int led = 10;         // the PWM pin the LED is attached to
int inverseled = 9;
//Constants
int maxValue = 6;
  //Dimmer values
int minPWM = 0;
int maxPWN = 100;

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
  double ratio = (double)Message/(double)maxValue;
  double inverseRatio = 1-ratio;
    //Dimmer value results
  int DimmerValue = (ratio*maxPWN);
  int inverseDimmerValue = (inverseRatio*maxPWN);
  Serial.println( (String) "Dimmer: " + DimmerValue+  " InverseDimmer: "+ inverseDimmerValue );

  //inverseDimmer.setPower(inverseDimmerValue);
  //dimmer.setPower(DimmerValue);
  analogWrite(led, DimmerValue);
  analogWrite(inverseled, inverseDimmerValue);
//digitalWrite(led, DimmerValue );
//digitalWrite( inverseled, inverseDimmerValue);

  // wait for 30 milliseconds to see the dimming effect
  delay(500);
}