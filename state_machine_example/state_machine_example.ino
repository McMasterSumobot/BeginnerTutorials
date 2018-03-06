/**
 * Author: Braden Corbold - Level IV Mechatronics McMaster University
 * Date: 01/02/2017
 */

#include "StateController.h" // We only have to import the header file of the StateController class we
                             // created earlier, it will handle everything else that needs to be imported

// Declare all the pins you need here

StateController stateController = new StateController(); // Create an instance of a StateController which
                                                         // is going to be what drives our state machine

void setup() {
  // Usual set up process, pins, serial monitor etc
}

void loop() {
  switch (stateController.getState()) { // Change logic based on our current state
    case QRDS_TRIPPED:
      moveAwayFromTheEdge();
      stateController.setSate(READ_SENSORS);
      break;

    case MOVE:
      generalMove();
      stateController.setSate(READ_SENSORS);
      break;

    case READ_SENSORS: // This will run like a normal switch case,
      if (isQrdTripped()) {
        stateController.setSate(QRDS_TRIPPED);
      } else {
        stateController.setSate(MOVE);
      }
    case DUMMY_STATE:
    case ANOTHER_DUMMY_STATE:
      // Both DUMMAY_SATE and ANOTHER_DUMMY_STATE will execute this code!
      break;
    default:
      // Anything left over states will execute here
  }
}

void moveAwayFromTheEdge() {} // How are you going to move away?

void generalMove() {} // Qrds haven't tripped, where are you going to go now?

bool isQrdTripped() { // How are you going to know if the Qrds have tripped? This function is where you
  return true;        // want to be able to read values and return something meaningful to your loop()
}                     // In this example assume that we are using a similar logic to what was used in the
                      // qrd_example project that returns true or false based on the value read.
