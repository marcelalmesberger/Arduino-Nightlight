// defining sensor
int sensor = A0;

// defining sensor value
int sensorValue = 0;

//defining external LED on PIN
int ledPin = 5;

// defining voltage value
float voltage = 0;

// defining thresholds
float thresholdBright = 2.00;
float thresholdDark = 3.00;

// defining default state for isDark variable
bool isDark = false;

// defining time meassurement settings
unsigned long previousMillis = 0.00;
unsigned long currentMillis = 0.00;
float stateTime = 0.00;

// defining function for time meassurement switching between dark and bright
void switchState() {
    
    // measure time
    stateTime = (currentMillis - previousMillis) / 1000.00;

    // set timer back
    previousMillis = currentMillis;
    
}

void setup() {
  
  // starting Serial Port
  Serial.begin(9600);

  // initializing built-in LED
  pinMode(LED_BUILTIN, OUTPUT);

  // initializing LED on Pin 5
  pinMode(ledPin, OUTPUT);
  
}

void loop() {
  
  // setting timer
  currentMillis = millis();
  
  // reading sensor
  sensorValue = analogRead(sensor);
  
  /*print sensor value on Serial Port:
     Serial.print("Sensor Value: ");
     Serial.println(sensorValue);*/

  // converting to voltage
  voltage = (5.00 / 1023.00) * (float) sensorValue;
  
  /* print voltage value on Serial Port:
     Serial.print("Voltage: ");
     Serial.print(voltage);
     Serial.println("V"); */

  // comparing voltage to threshold
  if (voltage > thresholdDark && isDark == false) {

    // change status of isDark variable
    isDark = true;
    
    // Switch ON buildin LED
    digitalWrite(LED_BUILTIN, HIGH);

    // adapt brightness of external LED with PWM
    int val = analogRead(0);
    val = map(val, 0, 1023, 0, 255);
    analogWrite(ledPin, val);

    /* measure time
    stateTime = (currentMillis - previousMillis) / 1000.00; */

    /* set timer back
    previousMillis = currentMillis; */

    // call function switchState
    switchState();

    // print state and time on Serial Port
    Serial.print("Dark! Number of seconds it was bright: ");
    Serial.println(stateTime);
    
  }
  else if (voltage < thresholdBright && isDark == true) {

    // Change status of isDark variable
    isDark = false;
    
    // Switch OFF buildin LED
    digitalWrite(LED_BUILTIN, LOW);

    // adapt brightness of external LED with PWM
    int val = analogRead(0);
    val = map(val, 0, 1023, 0, 255);
    analogWrite(ledPin, val);

    /* measure time
    stateTime = (currentMillis - previousMillis) / 1000.00; */

    /* set timer back
    previousMillis = currentMillis; */

    // call function switchState
    switchState();

    // print state and previous time on Serial Port
    Serial.print("Bright! Number of seconds it was dark: ");
    Serial.println(stateTime);
    
  }
}
