int out = 9; // Outpin to Potentiometer
int LED = 3; // Outpin to LED light
double V; // Double value to read in Potentiometer
double LED_V; // Double value to write to LED
void setup() {
  Serial.begin(9600); // initialize serial monitor
  pinMode(out, OUTPUT); // initialize output for potentiometer
  pinMode(A0, INPUT); // initialize input for potentiometer
  pinMode(LED, OUTPUT); // initalize output to LED
}

void loop() {
  analogWrite(out, 255); // send 255 (max) AKA 5V to potentiometer
  V = analogRead(A0); // reads value 0 to 1023 not an actual 
  // voltage passing through potentiometer based off knob position 
  LED_V = (V/1023)*255; // calculate led write value on 0-255 based off knob
  Serial.println(LED_V); // print for testing purposes
  analogWrite(LED, LED_V); // Write to LED the proper brightness in relation to potentiometer
}
