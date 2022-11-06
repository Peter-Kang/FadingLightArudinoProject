int led = 9;         // the PWM pin the LED is attached to
int brightness = 0;  // how bright the LED is
int maxBrightness = 255;

// the setup routine runs once when you press reset:
void setup() {
  // declare pin 9 to be an output:
  pinMode(led, OUTPUT);
  Serial.begin(38400); // baud rate
}

// the loop routine runs over and over again forever:
void loop() {
  double ratioMessage = 0.0;
  //Take a message from the bluetooth device
  if(Serial.available() > 0){ // Checks whether data is comming from the serial port
    ratioMessage = Serial.read(); // Reads the data from the serial port
    Serial.println((String)"Message Ratio: "+ratioMessage);
    brightness = maxBrightness * ratioMessage;
     Serial.println((String)"brightness : "+brightness);
  }

  // set the brightness of pin 9:
  analogWrite(led, brightness);
  // wait for 30 milliseconds to see the dimming effect
  delay(30);
}