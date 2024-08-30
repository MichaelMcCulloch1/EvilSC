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

#define TARGET_ID 0x60
#define CRC_ENABLED true

void writeMessage(uint8_t)Address) {

  Wire.beginTransmission(TARGET_ID);  // Start I2C transmission

  Wire.write((uint32_t)(TARGET_ID << 1)); // Target ID + Write bit (0)

  OP_RW = 0x0 // Writing Message
  CRC_EN = 0x1 // Currently enabled?
  DLEN = 0x1 // Data Length, currently just 4 bytes?
  MEM_SEC = 0x0 // Unsure what this is

  CONTROL_WORD_0 = OP_RW << 3 + CRC_EN << 2 + DLEN << 1 + MEM_SEC

  Wire.write((uint8_t)(CONTROL_WORD_0)); // Writing First Control Word

  MEM_PAGE = 
  MEM_ADDR = 

  CONTROL_WORD_1 = 

  Wire.write((uint8_t)(CONTROL_WORD_1)); // Writing Second Control Word
  
  Wire.write((uint8_t)(CONTROL_WORD_2)); // Writing Third Control Word

  // Writing Data Bytes to Gate Driver
  for (uint8_t i = 0; i < dataLength; i++) {
    Wire.write(data[i]);
  }

  // Ending Message with Calculated CRC Byte
  if (CRC_ENABLED) {
    // Calculating CRC:
    uint8_t crc = 0;
    Wire.write(crc);
  }

  error = Wire.endTransmission();   // no parameter, the I2C bus is releases after this.
  if(error == 0) {
    Serial.println("Data Delivered Successfully");
  } else {
    Serial.println("Error, data not delivered successfully");
  }

}
