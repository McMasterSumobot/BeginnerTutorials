#**Arduino Functions - Motors**
This project will continue to introduce the basics of the Arduino language and focuses on writing functions for your motors. It also goes through the different pins, analog and digital write, and PWM. These are all important for your motor and sensor controls.

###Code Preview
In order for this project to be truly effective you will need to have at minimum half of your H-Brdige implemented with a motor hooked up to it. The input pins to your H-Bridge must be connected to two PWM pins on the Arduino. We use 3 & 5 in the program but if you would like to use different ones you'll just need to change the pin assignments in the program. If you aren't using the Arduino Uno make sure that you check the data sheet to check which pins on your controller have PWM.

```
void setup() {
  pinMode(MotorForwardPin,  OUTPUT);
  pinMode(MotorBackwardPin, OUTPUT);
}

void loop() {
  switchDirection();
  delay(1000);
}
```

###Additional Resources
- [What is PWM?](https://www.arduino.cc/en/Tutorial/PWM)
- [Writing Functions](https://www.arduino.cc/en/Reference/FunctionDeclaration)