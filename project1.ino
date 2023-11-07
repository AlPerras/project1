// Good overall, seems to be missing the "knownDistance". Also the unit choice inch / cm

#include "rgb_lcd.h"
rgb_lcd lcd;

uint8_t sensorPin = 4;
uint16_t totalEvaluated = 1000;
double average(uint16_t, uint8_t);
double calibration();
uint64_t distance(double);
uint64_t constant;

void setup() {
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.cursor();
}

void loop() {
  double sensorValue = average(totalEvaluated, sensorPin);
  if (buttonState == HIGH) {
    double calibrationValue = calibration(knownDistance, sensorValue);
  }
  uint64_t value = distance(sensorValue);
  Serial.println(value);
  lcd.print(value);
  delay(500);
  lcd.clear();
}

double average (uint16_t n, uint8_t z) {
  float total = 0;
  float value;
  double x;
  for (uint16_t i = 0; i < n; i++) {
    pinMode(sensorPin,OUTPUT);
    digitalWrite(sensorPin,LOW);
    digitalWrite(sensorPin,HIGH);
    delayMicroseconds(2);
    digitalWrite(sensorPin,LOW);
    pinMode(sensorPin,INPUT);
    value = pulseIn(z,HIGH);
    total += value;
  }
  return x = total / n;  // If you are doing the calculation in the return statement you don't need the 'x='

  /* Use either:
  x = total / n;
  return x;
  
  Or:

  return total / n;
  
  */
}

// In these functions it would be better to use meaningful names rather 'a' and 'b'

double calibration(uint8_t a, double b) {
  return a / b;
}


uint64_t distance (double a, double b) {
  return a * b;
}












