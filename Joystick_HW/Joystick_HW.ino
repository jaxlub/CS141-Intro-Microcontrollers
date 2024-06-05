// Joy stick initialization
int VRx = A0; // initialize var for joystick VRx
int VRy = A1; // initialize var for joystick VRy
int swtch = 9; // initialize var for joystick switch
int readX; // initialize read in variables
int readY; // initialize read in variables
int readS; // initialize read in variables

// RGB set up
int red = 3; // pin for red write values
int green = 6; // pin for green write values
int blue = 10; // pin for blue write values
int ledbright; // var for led bright mapping

void setup() {
  Serial.begin(9600); // initialze serial monitor
  pinMode(VRx, INPUT); // initialize input for x joystick 
  pinMode(VRy, INPUT); // initialize input for y joystick
  pinMode(swtch, INPUT); // initialze switch input for switch (not used in this hw)

  pinMode(red, OUTPUT); // RGB light red output
  pinMode(green, OUTPUT); // RGB light green output
  pinMode(blue, OUTPUT); // RGB light blue output
}

void loop() {
  readX = analogRead(VRx); // read in x cord
  readY = analogRead(VRy); // read in y cord
  Serial.println(readY);
  if(readX > 500 & readX < 530 & readY > 500 & readY < 530){
    // if joystick is in the middle then all leds should be off
    // middle is 500-530 x and y vals for a little wiggle room for readin/manufacture error of joystick 
    ledbright = 0; // leds to 0
    // set all leds to 0 brightness
    analogWrite(red,ledbright);
    analogWrite(green,ledbright);
    analogWrite(blue,ledbright); 
  }
  if(readX < 500){
    // if joystick goes left turn all on
    // Map 0 to 500 of joystick X to 255 to 0 so it gradually turns on as u go more left
    ledbright = map(readX,0,500,255,0);
    // turn all lights on to map value (makes white light)
    analogWrite(red,ledbright);
    analogWrite(green,ledbright);
    analogWrite(blue,ledbright); 
  } else {
    // going right with joystick
    if (readX > 530){ //530 to allow for a little wiggle room in middle
      // Map 0 to 530 of joystick X to 0 to 255 so it gradually turns on as u go more left
      ledbright = map(readX,0,530,0,255);
      analogWrite(blue,ledbright); // set blue light
    }
    if (readY > 530){
      // down with joystick
      ledbright = map(readY,530,1023,0,255); // map joystick down values 530-1023 to 0 to 255 for led
      analogWrite(red,ledbright); // set led red to right value
    }
    if (readY < 500){ // if joystick up
      ledbright = map(readY,0,500,255,0); // map joystick up values 0 530 to 255 to 0 for led
      analogWrite(green,ledbright); // set led green to the right color
    }
  }
}
