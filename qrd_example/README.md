#**The Basics - Qrds**
This project will go through the absolute basics of the Arduino language and how an Arduino program is structured. It will also show you how to read values from your Qrds.

###Code Preview
In order to start this project you will have to have created at least one working QRD circuit that you can connect to your Arduino Uno. When you are running this program, make sure that you adjust the `QrdPin` to which ever pin you have your QRD connected sensor to. Each QRD sensor should be calibrated to find where the `QrdThreshold` value is. The QRD sensors read a 10-bit value (0 to 1023), you'll need to find which is the best value to decide when it is detecting white, or black.

```
void setup() {
  pinMode(QrdPin, INPUT);

  Serial.begin(9600);

  Serial.println("+-------------------------------------------+");
  Serial.println("|            QRD Sensor Readings            |");
  Serial.println("+-------------------------------------------+");
}

void loop() {
  QrdValue = analogRead(QrdPin);

  Serial.println("Qrd is reading a value of : " + QrdValue);
  if (QrdValue < QrdThreshold) {
      Serial.println("Qrd is reading white!!!");
    } else {
      Serial.print("Qrd is reading black!!!");
      Serial.print("\n");
    }
  Serial.println("---------------------------------------------");

  delay(1000);
}
```

###Additional Resources
- [Arduino Docs](https://www.arduino.cc/en/Reference/HomePage)
- [Arduino Foundations](https://www.arduino.cc/en/Tutorial/Foundations)
- [QRD Datasheet](https://www.fairchildsemi.com/datasheets/QR/QRD1113.pdf)
