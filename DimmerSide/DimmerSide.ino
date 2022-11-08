int led = 9;         // the PWM pin the LED is attached to
int inverseled = 10;
int brightness = 0;  // how bright the LED is
int maxBrightness = 255;
int minPWM = 25;
int maxPWN = 95;

// the setup routine runs once when you press reset:
void setup() {
  // declare pin 9 to be an output:
  pinMode(led, OUTPUT);
  pinMode(inverseled, OUTPUT);
  Serial.begin(38400); // baud rate
}

// the loop routine runs over and over again forever:
void loop() {
  int Message = 0;
  int inverseMessage =0;
  //Take a message from the bluetooth device
  Serial.flush();
  if(Serial.available() > 0){ // Checks whether data is comming from the serial port
    Message = Serial.read(); // Reads the data from the serial port
    inverseMessage = 255-Message;
    Serial.println(Message);
    
    //Convert Message value to Dimmer Value
    double ratio = Message/255.0;
    double inverseRatio = 1-ratio;
    int DimmerValue = (ratio*95);
    int inverseDimmerValue = (inverseRatio*95);

    analogWrite(led, DimmerValue);
    analogWrite(inverseled, inverseDimmerValue);
  }
  
  // wait for 30 milliseconds to see the dimming effect
  delay(500);
}