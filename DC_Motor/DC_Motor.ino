int motorspeed = 11; // controls the speed of the motor
int dir1 = 2; // with pin 7 controls motor direction
int dir2 = 7; // with pin 2 controls motor direction
int fast; // int to write speeds to motor 0-255
int IR_read = A0;
int i; // loop value
unsigned long time_micro;
int in_val;

void setup() {
  pinMode(motorspeed, OUTPUT);
  pinMode(dir1, OUTPUT);
  pinMode(dir2, OUTPUT);
  Serial.begin(230400);
}

void loop() {
  fast = 150;
  digitalWrite(dir1, HIGH);
  digitalWrite(dir2, LOW);
  analogWrite(motorspeed, fast);
  for(i = 0; i <1000; i = i+1){
     in_val = analogRead(IR_read);
     time_micro = micros();
     Serial.print(time_micro);
     Serial.print("\t");
     Serial.print(in_val);
     Serial.println();
  }

  delay(20000);
}
