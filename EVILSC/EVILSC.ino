#define BRAKE_PIN 3
#define SPEED_PIN 1
#define ESTOP_PIN 4
#define DIRECTION_PIN 5
#define FAULT_PIN 6
#define FG_PIN 7
#define CURRENT_SENSE_PIN 2

#define USER_LED_PIN 35

#define TEMP1_PIN 15
#define TEMP2_PIN 16
#define TEMP3_PIN 17

const int i2cADDR = 0x01;

void setup() {
  // put your setup code here, to run once:
  pinMode(BRAKE_PIN, OUTPUT);
  pinMode(SPEED_PIN, OUTPUT);
  pinMode(ESTOP_PIN, OUTPUT);
  pinMode(DIRECTION_PIN, OUTPUT);
  
  pinMode(FG_PIN, INPUT);
  pinMode(FAULT_PIN, INPUT);
  pinMode(CURRENT_SENSE_PIN, INPUT);

  pinMode(TEMP1_PIN, INPUT);
  pinMode(TEMP2_PIN, INPUT);
  pinMode(TEMP3_PIN, INPUT);

  pinMode(USER_LED_PIN, OUTPUT);

  Serial.begin(115200);
  Wire.begin(13, 14);  // sda= IO13 /scl= IO14
  Wire.setClock(50000);      // 50kHz, half the normal speed

}

void loop() {
  //Just gonna send it and see if we get any output
  digitalWrite(BRAKE_PIN, HIGH); //TURN OFF BRAKES
  digitalWrite(ESTOP_PIN, LOW); //TURN OFF ESTOP
  //analogWrite(SPEED_PIN, 127); //Attempt at 50% power???

  
  /*Serial.println("--Status Update--");
  Serial.print("nFAULT: ");
  Serial.println(digitalRead(FAULT_PIN));*/
  delay(1000);
  

}
