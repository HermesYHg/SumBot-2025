
#define motorLF 6 //Left motor definition
#define motorLB 9 //F/B for Forwards/Backwards

#define motorRF 10 //Right motor definition
#define motorRB 11
void setup() {

pinMode(motorLF, OUTPUT); //Left motor initialization
pinMode(motorLB, OUTPUT);

pinMode(motorRF, OUTPUT); //Right motor initialization
pinMode(motorRB, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

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

void stopMotor(){
  digitalWrite(motorLF, LOW) 
  digitalWrite(motorLB, LOW)

  digitalWrite(motorRF, LOW)
  digitalWrite(motorLB, LOW)
}

//Testing git changes