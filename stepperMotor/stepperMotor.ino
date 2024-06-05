#include <Stepper.h>
int steps_per_rev = 2048;
int motorDir = 1;
int delay_time=500;
int m_speed = 10;
int switch_pin = 4;
int old_state = 0;
int new_state;

// Steps per rev, In1, In3, In2, In4
Stepper TinaTurner(steps_per_rev,8,10,9,11);

void setup() {
  Serial.begin(9600);
  pinMode(switch_pin, INPUT);
}

void loop() {
digitalWrite(switch_pin, HIGH);
new_state = digitalRead(switch_pin);

if(new_state == 1 & old_state == 0){
  motorDir = motorDir*-1;
}
old_state = new_state;
Serial.println(motorDir);
TinaTurner.setSpeed(m_speed);
TinaTurner.step(motorDir);


}
