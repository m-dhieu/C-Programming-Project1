// define pins
const int sensorPin = A0; 
const int ledPin = 13; 

void setup() {
  // initialize LED pin as output
  pinMode(ledPin, OUTPUT);
  
    Serial.begin(9600);
}

void loop() {
  // read & convert value from sensor
  int rawReading = analogRead(sensorPin);
  
  float voltage = rawReading * (5.0 / 1023.0);
  
  float temperatureC = (voltage - 0.5) * 100.0;
  
  Serial.print("Temperature: ");
  Serial.print(temperatureC);
  Serial.println(" C");
  
  // check temp condition
  if (temperatureC > 28.0) {
    digitalWrite(ledPin, HIGH); 
  } else {
    digitalWrite(ledPin, LOW);  
  }
  
  delay(500);
}

