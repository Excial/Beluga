void initSerial() {
  
  Serial.begin(9600);
  Serial.println("SERIAL OK");
  
}

void initSensor() {
  
  pinMode(sw1, INPUT); // Default logic is 0
  pinMode(sw2, INPUT); // Default logic is 0
  pinMode(m1, OUTPUT);
  pinMode(m2, OUTPUT);
  pinMode(m3, OUTPUT); // Naturally low (ie HIGH = COM and NC)
  pinMode(m4, OUTPUT); // Naturally low (ie HIGH = COM and NC)
  
}
