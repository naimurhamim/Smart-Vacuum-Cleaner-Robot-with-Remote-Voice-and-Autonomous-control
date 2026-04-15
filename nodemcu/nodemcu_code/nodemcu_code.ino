// === Pins ===
#define irSensor A0   // IR flame sensor
#define pumpPin  A5   // Relay module control pin
#define servoPin 9    // Servo motor signal pin (same as in your working relay code)

int sensorValue;

void setup() {
  Serial.begin(9600);

  pinMode(irSensor, INPUT);
  pinMode(pumpPin, OUTPUT);
  pinMode(servoPin, OUTPUT);

  digitalWrite(pumpPin, LOW); // Pump OFF at start

  // Initial servo sweep
  for (int angle = 90; angle <= 140; angle += 5) servoPulse(servoPin, angle);
  for (int angle = 140; angle >= 40; angle -= 5) servoPulse(servoPin, angle);
  for (int angle = 40; angle <= 95; angle += 5) servoPulse(servoPin, angle);
}

void loop() {
  sensorValue = analogRead(irSensor);
  Serial.print("IR Sensor Value: ");
  Serial.println(sensorValue);

  if (sensorValue < 350) {  
    // Fire detected
    digitalWrite(pumpPin, HIGH); // Pump ON
    sprayWater();
  } else {
    // No fire
    digitalWrite(pumpPin, LOW);  // Pump OFF
    servoPulse(servoPin, 90);    // Neutral servo position
  }

  delay(50);
}

// ===== Functions =====
void sprayWater() {
  // Sweep servo left-right to spray
  for (int angle = 90; angle <= 140; angle += 3) servoPulse(servoPin, angle);
  for (int angle = 140; angle >= 40; angle -= 3) servoPulse(servoPin, angle);
  for (int angle = 40; angle <= 90; angle += 3) servoPulse(servoPin, angle);
}

void servoPulse(int pin, int angle) {
  int pwm = (angle * 11) + 500; // Convert angle to pulse width
  digitalWrite(pin, HIGH);
  delayMicroseconds(pwm);
  digitalWrite(pin, LOW);
  delay(20); // Servo refresh
}
