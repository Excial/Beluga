const int sw1 = 6; //Pin for switch 1 (Right side), Receive input from switch 1.
const int sw2 = 9; //Pin for switch 2 (Left side), Receive input from switch 2
const int m1 = 2; //Pin for Motor driver, Give output to motor driver 
const int m2 = 3; //Pin for Motor driver, Give output to motor driver 
const int m3 = 4; //Pin for Pump, Give output to Pump
const int m4 = 5; //Pin for Pump, Give output to Pump 
bool count = true; 
int times = 1;

void setup() { 
  
  Serial.begin(9600);
  pinMode(sw1,INPUT); // Default logic is 0
  pinMode(sw2,INPUT); // Default logic is 0
  pinMode(m1,OUTPUT); 
  pinMode(m2,OUTPUT);
  pinMode(m3,OUTPUT); // Naturally low (ie HIGH = COM and NC)
  pinMode(m4,OUTPUT); // Naturally low (ie HIGH = COM and NC)
  //digitalWrite(m3, LOW); // Put it to HIGH to off first (ie be in NO mode), m3 = LOW and m4 = HIGH pumps clockwise 
  //digitalWrite(m4, HIGH); // Run once to have reagent reach the tip
  //delay(2250); // 5ml in 25 seconds; 1ml in 5 seconds; 50ul = 0.05ml required; max of 100ul = 0.1ml; Height should be 5.5cm
  //digitalWrite(m3, HIGH); // Either both HIGH or both LOW to ensure no motion
  delay(2000);
}

void moveLeft() {

  digitalWrite(m1,HIGH); // Move left and sensor is aligned
  digitalWrite(m2,LOW); 
  
}

void moveRight() {

  digitalWrite(m1,LOW); // Move right and pump is aligned
  digitalWrite(m2,HIGH); 
  
}

void stopMoving() {
  
  digitalWrite(m1,HIGH); // Pause motion
  digitalWrite(m2,HIGH);
  Serial.println("I have stopped");
  
}

void loop(){
  
  int out1 = digitalRead(sw1); // Print output of sw1 logic
  Serial.print("OUT1: ");
  Serial.println(out1);
  
  int out2 = digitalRead(sw2); // Print output of sw2 logic
  Serial.print("OUT2: ");
  Serial.println(out2);

  if(out1 == 1 && count == true && times == 1) {
      moveLeft();
      Serial.println("Start, I am moving left 1st time");
      Serial.println(times);
  }
  
  else if(out2 == 1 && count == true && times == 1) { // At left side 1st time (Sensor takes reading 1st time)
      stopMoving();
      count = false;
      Serial.println("I have reached far left 1st time");
      Serial.println(times);
      delay(60000);  
  }

  else if(out2 == 1 && count == false && times == 1) { // Move right 1st time 
      moveRight();
      Serial.println("I am moving right 1st time");
      Serial.println(times);
  }

  else if(out1 == 1 && count == false && times == 1){ // At right side 1st time (Pump takes reading)
      stopMoving();
      count = true;
      times += 1;
      Serial.println("I have reached far right 1st time");
      Serial.println(times);
      delay(2000);
      digitalWrite(m3, LOW);
      digitalWrite(m4, HIGH); 
      delay(500); // 5ml in 25 seconds; 1ml in 5 seconds; 50ul = 0.05ml required; max of 100ul = 0.1ml; Height should be 5.5cm
      digitalWrite(m3, HIGH);
      Serial.println("I have finished dispensing");
      delay(2000);
  }

  else if(out1 == 1 && count == true && times == 2){ // Move left 2nd time
      moveLeft();
      Serial.println("I am moving left 2nd time");
      Serial.println(times);
      
  }

  else if(out2 == 1 && count == true && times == 2){ // At left side 2nd time (Sensor takes reading 2nd time)
      stopMoving();
      count = false;
      Serial.println("I have reached far left 2nd time");
      Serial.println(times);
      delay(60000);
  }

  else if(out2 == 1 && count == false && times == 2) { // Move right 2nd time 
      moveRight();
      Serial.println("I am moving right 2nd time");
      Serial.println(times);
  }

  else if(out1 == 1 && count == false && times == 2){ // At right side 2nd time (End position)
      stopMoving();
      count = true;
      // times -= 1; // Uncomment this if want to loop
      times += 1; // To make sure system stop for good
      Serial.println("I have reached far right 2nd time, Finished");
      Serial.println(times);
      delay(2000);
      Serial.println("System will stop");
  }
  
}
