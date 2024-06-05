// include servo library
#include <Servo.h>

Servo spinner; //name motor

void setup() {
  spinner.attach(10); // pin initialize for motor
}

void loop() {  
  delay(1000);
  spinner.write(180);
  delay(1000);
  spinner.write(0);
  delay(1000);  
  for (int angle = 0; angle <= 180; angle += 1) {
    spinner.write(angle);
    delay(15);
  }



}
