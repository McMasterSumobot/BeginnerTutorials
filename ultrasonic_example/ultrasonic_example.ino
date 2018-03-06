/**
 * Author: Braden Corbold - Level IV Mechatronics McMaster University
 * Date: 05/03/2018
 */

#include <NewPing.h> // This type of import is used for using libraries that have been imported to the
                        // arduino library. This is the recomended way since you don't have to have the
                        // source files in your project.
#include "ultrasonic_example.h" // This is another way to import files however the file MUST exist in the
                                // project folder in order for it to be loaded. This is great for header
                                // files like this since we can define things like enums ahead of time to
                                // keep our code nice and clean. If you have written a c++ class that 
                                // like to use for only this project. 

const unsigned int TRIGGER_PIN = 12; // transmition pin (it will output a pulse to the sensor)
const unsigned int ECHO_PIN = 13; // receiving pin (it will read the output from the sensor)
const unsigned int MAX_DISTANCE = 100; // maximum distance that the sensor will look for in cm

// Creates an NewPing object. This uses the imported library to
// handle everything needed in order to read a distance. When you
// call ping_cm() on it, it will send a pulse through TRIGGER_PIN
// and wait for readings on the ECHO_PIN. Once it has the values it will
// return an integer of the CMs to the detected object.
// If you'd like to look more into how it works check out the source
// code in the library, it's pretty straight forward.
NewPing leftSonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

void setup() {
  pinMode(TRIGGER_PIN, OUTPUT); // needs to be an output in order to send a pulse to the sensor
  pinMode(ECHO_PIN, INPUT); // needs to be an input in order to receive values from the sensor

  Serial.begin(9600);
}

void loop() { // Using local methods to keep our loop() easy to read
  printUltrasonicDistance();
  delay(1000);
}

void printUltrasonicDistance() {
  int distance = leftSonar.ping_cm();  // The NewPing library takes care of all of the timing needed
  Range range = cmToEnum(distance);    // to read the distance. You can always look into the source code to see 
                                       // how it is implemented. With enough time and calibration you may
                                       // be able to get more acurate readings using your own
                                       // implementation.

  // You can use switch statements in your code just like in c++ Hint: Maybe this could be useful
  // for designing your logic?
  switch (range) {
    case LESS_THAN_5:
      Serial.println("Distance is less than 5cm");
      break;
    case LESS_THAN_10:
      Serial.println("Distance is between 5cm and 10cm");
      break;
    case LESS_THAN_15:
      Serial.println("Distance is between 10cm and 15cm");
      break;
    default:
      Serial.println("Distance is too far to care about");
  }
}

Range cmToEnum(int distance) { // Just a conversion method to make the distances nice to work with when
  if (distance < 5) {          // in the switch-case
    return LESS_THAN_5;
  } else if (distance < 10) {
    return LESS_THAN_10;
  } else if (distance < 15) {
    return LESS_THAN_15;
  } else {
    return TOO_FAR;
  }
}