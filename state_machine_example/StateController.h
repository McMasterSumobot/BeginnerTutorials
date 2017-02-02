/**
 * Author: Braden Corbold - Level IV Mechatronics McMaster University
 * Date: 01/02/2017
 */

#ifndef StateController_h // This is needed for some low level Arduino stuff. By having #ifndef, 
#define StateController_h // #define and #endif (at the bottom) it protects the class if a user
                          // accidentally imports it twice. More info can be found at the following
                          // link: https://www.arduino.cc/en/Hacking/LibraryTutorial

#include "Arduino.h" // This allows you to use standard types and constants of Arduino

// Declaring our State enum. We do this in the same way as we did for our Range enum for Ultrasonics
// but this time we are going to use it directly for this class.
enum State {READ_SENSORS, MOVE, QRDS_TRIPPED, DUMMY_STATE, ANOTHER_DUMMY_STATE, NEVER_CALLED}

class StateController { // This is where we define all of the methods and variables that are under this
                        // class' namesapce.
  public:
    StateController(); // Public constructor method

    void setState(State newState); // The two methods we will use to "run" our state machine. They need
    State getState();              // to be public so that we can use them once the object has been
                                   // created.
  private:
    State currentState; // Private state variable. We set this as a private variable since we don't want
                        // to expose it directly to the user. This is a standard practice to always be 
                        // strict on your permissions, unless needed otherwise. This is why we have the
                        // getter and setter methods.
}

#endif
