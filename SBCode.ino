// IR Sensor
#define IRSensor 2;
int IRVal = 0;

//Ultrasonic Sensor
#define echo 3
#define trig 4
float duration = 0.0; //Not sure what dis for
float time = 0.0; //In seconds

#define motorLF 6 //Left motor definition
#define motorLB 9 //F/B for Forwards/Backwards

#define motorRF 10 //Right motor definition
#define motorRB 11

void setup() {
pinMode(motorLF, OUTPUT); //Left motor initialization
pinMode(motorLB, OUTPUT);

pinMode(motorRF, OUTPUT); //Right motor initialization
pinMode(motorRB, OUTPUT);

pinMode(IRSensor, INPUT);

pinMode(echo, INPUT); //Echo receives reflected wave
pinMode(trig, OUTPUT); //Trigger outputs sound wave signal to hit objects

Serial.begin(9600);
}

void loop() {
  //IR Sensor Stuff
  IRVal = digitalRead(IRSensor); //read IR sensor 
  Serial.println(IRVal); //For test checks

  if (IRVal == HIGH){ //If IR light reflected (white surface)

  }
  else if (IRVal == LOW){ //If IR light absorbed (black surface)

  }

  //Ultrasonic Sensor Stuff
  digitalWrite(trig, LOW); //Clear trig pin
  delay(2); //wait 2ms
  digitalWrite(trig, HIGH) //Send out signal
  delay(10);
  digitalWrite(trig, LOW);

  time = pulseIN(echo, HIGH); //Read echo pin
  dist = time * 0.0343 / 2; //Distance calculation

  Serial.println("Distance: ");
  Serial.println(dist);

  delay(1000); //Wait for 1s
}

void moveForward() {
  digitalWrite(motorLF, HIGH) //Current flows one way to turn wheels forward
  digitalWrite(motorLB, LOW)

  digitalWrite(motorRF, HIGH)
  digitalWrite(motorLB, LOW)
}
void moveBackward(){
  digitalWrite(motorLF, LOW) //Reverse current direction to turn wheels backward
  digitalWrite(motorLB, HIGH)

  digitalWrite(motorRF, LOW)
  digitalWrite(motorLB, HIGH)
}

void forwardSpd(int spd){ //Signal from 0-255, 255 = 100% speed
  analogWrite(motorLF, spd);
  analogWrite(motorLB, 0);

  analogWrite(motorRF, spd);
  analogWrite(motorRB, 0);
}
void backwardSpd(int spd){ 
  analogWrite(motorLF, 0);
  analogWrite(motorLB, spd);

  analogWrite(motorRF, 0);
  analogWrite(motorRB, spd);
}

void turnL(int spd){ //Left wheel moves back, right wheel moves forward to turn left
  analogWrite(motorLF, 0);
  analogWrite(motorLB, spd);

  analogWrite(motorRF, spd);
  analogWrite(motorRB, 0);
}
void turnR(int spd){
  analogWrite(motorLF, spd);
  analogWrite(motorLB, 0);

  analogWrite(motorRF, 0);
  analogWrite(motorRB, spd);
}

void stop(){
  digitalWrite(motorLF, LOW) 
  digitalWrite(motorLB, LOW)

  digitalWrite(motorRF, LOW)
  digitalWrite(motorLB, LOW)
}

void movement(){ //Ultrasonic range 2cm~4m
  if (dist < 15 && dist > 2){ //If opps in view, atk them or sum

  }
  else { //Dick around

  }
}