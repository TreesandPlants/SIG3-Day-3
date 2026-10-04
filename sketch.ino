const int SENSOR_PIN = 34;
const int LED_PIN = 14;

unsigned long lastPrintTime = 0;
const unsigned long printInterval = 500;

void setup() {
  Serial.begin(115200);
  pinMode(SENSOR_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  int rawValue = analogRead(SENSOR_PIN); // 0 to 4095

  // Map 12-bit ADC (0-4095) to 8-bit PWM LED brightness (0-255)
  int pwmValue = map(rawValue, 0, 4095, 0, 255);
  analogWrite(LED_PIN, pwmValue);

  // Print reading every 500ms
  if (millis() - lastPrintTime >= printInterval) {
    lastPrintTime = millis();
    Serial.print("Raw: ");
    Serial.print(rawValue);
    Serial.print(" | LED PWM: ");
    Serial.println(pwmValue);
  }
}
