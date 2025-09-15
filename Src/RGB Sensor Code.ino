/* Author: Salvatore F DeLuca 
 * Date of Creation: April 20, 2025
 * 
 * Wiring pinout:
 * Right servo : pin 12
 * Left Servo : pin 13
 */
 #include <Servo.h> //import servo library for control of motors

//initialize and decalre variables for servo pins ultrasonic sensor & more
int right = 13;
int left = 12;
int rightValue = 0;
int leftValue = 0;
int trigPin = 3; 
int echoPin = 4;

//objects for left and right servos
Servo rServo;
Servo lServo;

//defining power constants to variables
int hault = 1500;
int go = 1400;
int reverse = 1600;
int rotateRight = 1600;
int rotateLeft = 1400;

//pins for RGB led and photoresistor
int RGB_pins [] = {5,2,7};
int photoResistor = A3;

//empty arrays to store RGB led
int Data [] = {0,0,0}; //index 0 is red, 1 is green, and 2 is blue
int rawData = 0;

//default values
int saturationTime = 150;
int CoolDownTime = 100;
int i = 0;


void setup() {
  // Open up the serial port
  Serial.begin(9600);

  //determining pin modes
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  //tell the arduino what pins are what
  pinMode(RGB_pins[0], OUTPUT);
  pinMode(RGB_pins[1], OUTPUT);
  pinMode(RGB_pins[2], OUTPUT);
  pinMode(photoResistor, INPUT); 

  nowStart(); //Call function to attatch servos to pins
}

void loop() {
  //turn everything off
  for(i = 0; i<3; i++){
    digitalWrite(RGB_pins[i], LOW);
  }
  
  //determine if the bot is too close to a wall
  int value = DistanceREAD();
  if (value < 6){
    pause();
  }
  //Interval of time (loop) for the sensor to read a new color
  rawData = analogRead(photoResistor);
  Serial.println("-----------");
  Serial.println("Measuring the Environment :");
  Serial.println("You have two second to place \n an a target in front of the sensor");
  Serial.println("-----------");
  delay(1300); //wait for material to be presented
  
  for(i = 0; i<3; i++){
    digitalWrite(RGB_pins[i], HIGH);
    delay(saturationTime); //time to saturation the target material
    Data[i] = analogRead(photoResistor);
    digitalWrite(RGB_pins[i], LOW);
    delay(CoolDownTime); //Cool down time
  }

  //print out the data
  Serial.println("-----------");
  Serial.print("R : ");
  Serial.println(Data[0]);
  Serial.print("G : ");
  Serial.println(Data[1]);
  Serial.print("B : ");
  Serial.println(Data[2]);
  Serial.print("Raw data : ");
  Serial.println(rawData);
  Serial.println("-----------");

//Only read colors if the bot reads a raw data value high enough (detects an object near the sensor)
if (rawData > 950){
  Serial.print("What color : ");
  //conditional states  for determining what the color is
  if(Data[0] < Data[1] && Data[0] < Data[2] && Data[2] > Data[1]){ //red
    backward();
    Serial.println("could be red"); }
  else if(Data[1] < Data[0] && Data[1] < Data[2] && Data[0] > Data[2]){ //green
    forward();
    Serial.println("could be green"); }
  else if(Data[2] < Data[1] && Data[2] < Data[0] && Data[0] > Data[1]){ //blue
    turnRight();
    Serial.println("could be blue");  }
  else if (Data[0] < Data[2] && Data[1] < Data[2]) { //yellow
    // If yellow is detected (Red + Green = Yellow)
    Serial.println("could be yellow");  
    turnLeft();  }
  else {
    // If the color is mixed or unclear
    Serial.println("STOP detected");
    nowStop();  // Stop the robot for unclear color
  }
}
else {
  nowStop(); //Stop the bot for when the sensor does not detect something infront of it
}
 
 delay(250);//just a delay 
 
}

//FUNCTIONS//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//function to attatch servos to pins
void nowStart(){
  rServo.attach(right);
  lServo.attach(left); 
}
//function to stop the servos then detach servos to stop the bot
void nowStop(){
  rServo.writeMicroseconds(hault);
  lServo.writeMicroseconds(hault);
}

//function to turn the bot right
void turnRight(){
  rServo.writeMicroseconds(rotateRight);
  lServo.writeMicroseconds(rotateRight);
}

//function to turn the bot left
void turnLeft(){
  rServo.writeMicroseconds(rotateLeft);
  lServo.writeMicroseconds(rotateLeft);
}

//function to move the bot forward
void forward(){
  rServo.writeMicroseconds(reverse);
  lServo.writeMicroseconds(go);
}

//function to move the bot backwards
void backward(){
  rServo.writeMicroseconds(go);
  lServo.writeMicroseconds(reverse);
}

//function to pause the bot
void pause(){
  rServo.writeMicroseconds(2000);
  lServo.writeMicroseconds(hault);
}

//function to determine distance from sensor
long DistanceREAD() {
  long duration;
  
  //trig the pulse required. 
  digitalWrite(trigPin, LOW);  
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW);
  
  //record the pulse in
  duration = pulseIn(echoPin, HIGH);
  long distance = (duration / 2) / 29.1;

  // Print to Serial Monitor
  Serial.print("Ultrasonic Sensor Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  return distance;
}

