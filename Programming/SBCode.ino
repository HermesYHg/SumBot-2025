// https://www.sumobot.ca/competition?rules=Beginner
// IR Sensor Definition
#define IRSensor 2;
int IRVal = 0;

//Ultrasonic Sensor Def
#define echo 3
#define trig 4
float dist = 0.0; //In cm
float time = 0.0; //In micro seconds?

//Motors Def
#define motorLF 6 //Left/Right, Forwards/Backwards
#define motorLB 9 
#define motorRF 10 
#define motorRB 11

void setup() {
//Initialization
pinMode(IRSensor, INPUT);

pinMode(echo, INPUT); //Echo receives reflected wave
pinMode(trig, OUTPUT); //Trigger outputs sound wave signal to hit objects

pinMode(motorLF, OUTPUT); 
pinMode(motorLB, OUTPUT);
pinMode(motorRF, OUTPUT); 
pinMode(motorRB, OUTPUT);

Serial.begin(9600);
delay(5000); //5s delay at start
}

void loop() {
  ultraInstinct(); //Calc distance from opps
  movement(); //Decide what to do based on calculated dist

  //IR Sensor Stuff
  IRVal = digitalRead(IRSensor); //read IR sensor 
  Serial.println(IRVal); //For test checks

  if (IRVal == HIGH){ //IR light reflected (white surface aka border)

  }
  else if (IRVal == LOW){ //IR light absorbed (black surface)

  }
}

void forward() {
  digitalWrite(motorLF, HIGH) //Current flows one way to turn wheels forward
  digitalWrite(motorLB, LOW)
  digitalWrite(motorRF, HIGH)
  digitalWrite(motorRB, LOW)
}

void backward(){
  digitalWrite(motorLF, LOW) //Reverse current direction to turn wheels backward
  digitalWrite(motorLB, HIGH)
  digitalWrite(motorRF, LOW)
  digitalWrite(motorRB, HIGH)
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
  digitalWrite(motorRB, LOW)
}

void movement(){ //Ultrasonic range 2cm~4m
  if (dist < 15 && dist > 2){ //If opps in view, atk them or sum

  }
  else { //Dick around

  }
} 

void ultraInstinct(){ //Calc distance w/ ultrasonic sensor (calc is short for calculator)
  digitalWrite(trig, LOW); //Clear trig pin
  delay(2);
  digitalWrite(trig, HIGH) //Send out signal
  delay(10);
  digitalWrite(trig, LOW);

  time = pulseIN(echo, HIGH); //Read echo pin
  dist = time * 0.0343 / 2; //Distance calculation (c = 0,0343 cm/us, div by 2 for time spent sending and returning)

  Serial.println("Distance: ");
  Serial.println(dist);

}
