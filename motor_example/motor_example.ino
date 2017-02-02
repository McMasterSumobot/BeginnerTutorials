/**
 * Author: Braden Corbold - Level IV Mechatronics McMaster University
 * Date: 01/02/2017
 */

// Assigning out pins as constants. On the Arduino Uno, pins 3 and 5 are Pwm so that we can specify a
// range of values to control the speed of the motor. If you do not want to have control over motor
// speed you can always choose another digital pin and write HIGH or LOW.
const unsigned int MotorForwardPin  = 3; // Note: You will have to check which pin is forward and 
const unsigned int MotorBackwardPin = 5; //       which is backward based on how you wired your
                                         //       H-Bridge. There is no correct way since motors
                                         //       are not polarized. todo: correct wording? polarized?

enum Direction {FORWARD, BACKWARD}; // We can create enums in Arduino just like in c++

Direction currentDirection = FORWARD;

void setup() {
  pinMode(MotorForwardPin,  OUTPUT); // Setting our motor pins as outputs since we are writing values
  pinMode(MotorBackwardPin, OUTPUT); // to them to contorl the H-Bridge

  Serial.begin(9600);
}

// By writing functions that are used often, we can modularize our code and make it much easier to read
// and more importantly, debug
void loop() {
  switchDirection();
  delay(1000); // Although delay() blocks any new code from running it will keep any output values
               // to pins constant! So when we write to our motors, they will keep on going even if 
               // a delay has not finished yet. Hint: Could this cause any problems?
}

// This function changes the direction, and speed of the motor
void switchDirection() {
  if (currentDirection == FORWARD) {
    currentDirection = BACKWARD;
    String msg = setSpeed(127);
    Serial.println(msg);
  } else {
    currentDirection = FORWARD
        Serial.println(setSpeed(HIGH)); // Arduino has built in constants for digital outputs HIGH and 
                                        // LOW however these also work for analog by writing either 255
                                        // or 0
  }
}

String setSpeed(unsigned int speed) {
  if (currentDirection == FORWARD) {
    analogWrite(MotorForwardPin , speed); // Writing to pins works the same way as reading, specify the
    analogWrite(MotorBackwardPin, 0);     // and the value you would like to write
    return "Forward speed set at: " + speed
  } else {
    analogWrite(MotorForwardPin , LOW);   // Another example of using Arduino constants and how they can
    analogWrite(MotorBackwardPin, speed); // be used interchangeably
    return "Backward speed set at: " + speed
  }
  
}