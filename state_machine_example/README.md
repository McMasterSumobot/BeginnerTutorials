#**Custom Classes - State Logic**
This final project will show you how to write your own libraries in C++ and how to use them in your Arduino projects. We will create a ```StateController``` that we will use to implement a sate machine for the main logic of a Sumobot.

###Code Preview
It reccomended to have some knowledge about C++ before starting to write your own libraries. More information can be found at the links provided below. It would also be good to read up on the idea of State Machines and State Diagrams before starting to write your code. This will keep your code organized and reduce headaches during testing. Put a lots of time into your design, but remember to always try to keep your code modular so that when you envitably have to change something it is much easier to do so.

```
class StateController {
  public:
    StateController();

    void setState(State newState);
    State getState();
  private:
    State currentState;
}
```

###Additional Resources
- [C++ Docs and Tutorials](http://www.cplusplus.com/doc/tutorial/)
- [Header Files in C++](https://www.arduino.cc/en/Guide/Libraries)
- [Finite State Machines](https://en.wikipedia.org/wiki/Finite-state_machine)
- [State Diagrams](https://en.wikipedia.org/wiki/State_diagram)
