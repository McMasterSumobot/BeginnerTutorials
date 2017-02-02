/**
 * Author: Braden Corbold - Level IV Mechatronics McMaster University
 * Date: 01/02/2017
 */

#include "Arduino.h" // This allows you to use standard types and constants of Arduino
#include "StateController.h" // Import the associate header file

// A constructor method that we will call to create an object in our Arduino program
StateController::StateController() {
  currentState = READ_SENSORS; // Since we've already defined the enum in the header file we can just
}                              // use the value in the .cpp file

void StateController::setState(State newState) { // Setter method to change the state to whatever the
  currentState = newState;                       // next state is. This allows the StateController to 
}                                                // be not be coupled with our Arduino implementation

State StateController::getState() { // Getter method to check what state we are at.
  return currentState;
}
