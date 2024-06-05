#include <Servo.h> // include servo library
Servo spinner; //name motor
int r_button = A0; // pin to read button press for spin right
int button_r; // variable to read in r_button click
int l_button = A1; // pin to read button press for spin left
int button_l; // variable to read in l_button click
int motor_pos = 0; // initialize motor to 0 position and used to keep track of angle
int redLed = 12; // pin for red led
void setup() {
  spinner.attach(10); // pin initialize for motor
  pinMode(r_button, INPUT); // pin initialize for reading button press
  pinMode(l_button, INPUT); // pin initialize for reading button press
  pinMode(redLed, OUTPUT); // pin initialize for warning light
}

void loop() {
  button_r = digitalRead(r_button); // check if right spin pressed
  button_l = digitalRead(l_button); // check if left spin pressed
  if (button_r == 1){ // if button pressed spin motor angle by 5 degrees right
    motor_pos = motor_pos + 5;
  }
  if(button_l == 1){ // if button pressed spin motor angle by 5 degrees left
    motor_pos = motor_pos -5;
  }
  if (motor_pos > 180){ 
    // if motor angle is above 180 reset to 180
    motor_pos = 180;
    digitalWrite(redLed, HIGH); // Turn on warning light
  }
  if (motor_pos < 0){
    // if motor angle is below 0 reset to 0
    motor_pos = 0;
    digitalWrite(redLed, HIGH); // Turn on warning light
  }
  delay(100); 
  digitalWrite(redLed, LOW); // turn off LED as value is no longer in violation of exceeding range
  
  spinner.write(motor_pos); // spin motor to new calculated position.

}
