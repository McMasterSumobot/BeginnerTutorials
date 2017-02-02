#**Libraries and External Files - Ultrasonic Range Sensors**
This project will continue to explore the Arduino language and show you how to import external libraries and give an overview on how to write your own libraries for Arduino. It also goes through how to set up and use the Ultrasonic library that is written for the sensors provided. 

###Code Preview
In order for this project to work you will need to have the [Ultrasonic Library](http://tutorial.cytron.com.my/2012/10/11/testing-ultrasonic-ranging-module-sn-hc-sr04/) downloaded and imported to your Arduino libraries. Instructions on installing libraries in Arduino can be found at the links provided below. You will need 2 digital pins for an Ultrasonic sensor, they do NOT have to be PWM.

```
setup() {
  pinMode(TxPin, OUTPUT);
  pinMode(RxPin, INPUT);

  Serial.begin(9600);
}

loop() {
  printUltrasonicDistance();
  delay(1000);
}

void printUltrasonicDistance() {
  int leftVal = leftSonar.Ranging(CM);
  Range range = cmToEnum(distance);

  switch (range) {...}
}

Range cmToEnum(int distance) {
  if (distance < 5) {...}
}
```

###Additional Resources
- [Ultrasonic Library](http://tutorial.cytron.com.my/wp-content/uploads/2012/10/HC_SR4_Demo_Arduino.zip)
- [Ultrasonic Tutorial](http://tutorial.cytron.com.my/2012/10/11/testing-ultrasonic-ranging-module-sn-hc-sr04/)
- [Installing Libraries in Arduino](https://www.arduino.cc/en/Guide/Libraries)
- [Why use header files?](http://www.cplusplus.com/forum/articles/10627/)