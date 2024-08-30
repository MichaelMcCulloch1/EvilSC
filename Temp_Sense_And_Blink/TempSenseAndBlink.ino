/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. 35 is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/Blink
*/

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 35 as an output.
  pinMode(35, OUTPUT);
  pinMode(15, INPUT);
  pinMode(16, INPUT);
  pinMode(17, INPUT);
  Serial.begin(115200);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(35, HIGH);   // turn the LED on (HIGH is the voltage level)
  //Serial.println("on");
  delay(1000);                       // wait for a second
  digitalWrite(35, LOW);    // turn the LED off by making the voltage LOW
  Serial.print("Temp Sensor 1: ");
  double temp1 = analogRead(15);
  Serial.print(temp1);
  Serial.print(", ");
  Serial.print(((temp1/1000)-0.5)*100);
  Serial.print(" degrees C, ");
  Serial.print(((((temp1/1000)-0.5)*100)*(9.0/5.0))+32);
  Serial.println(" degrees F.");

  Serial.print("Temp Sensor 2: ");
  double temp2 = analogRead(16);
  Serial.print(temp2);
  Serial.print(", ");
  Serial.print(((temp2/1000)-0.5)*100);
  Serial.print(" degrees C, ");
  Serial.print(((((temp2/1000)-0.5)*100)*(9.0/5.0))+32);
  Serial.println(" degrees F.");

  Serial.print("Temp Sensor 3: ");
  double temp3 = analogRead(17);
  Serial.print(temp3);
  Serial.print(", ");
  Serial.print(((temp3/1000)-0.5)*100);
  Serial.print(" degrees C, ");
  Serial.print(((((temp3/1000)-0.5)*100)*(9.0/5.0))+32);
  Serial.println(" degrees F.");

  Serial.println();
  //Serial.println("off");
  delay(1000);                       // wait for a second
  
}