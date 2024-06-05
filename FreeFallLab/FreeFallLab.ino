unsigned long ping_time; // value to read in pulse
int trigpin = 10; // trig pin to arduino
int echopin = 11; // echo pin to arduino
unsigned long falltime; // unsigned long to get precise microseconds

void setup() {
  pinMode(trigpin, OUTPUT); // initialize trig pin
  pinMode(echopin, INPUT); // initialize echo pin
  Serial.begin(500000); // set high baud rate for increased accuracy
}

void loop() {
  Serial.println("Ready?"); // Prompt user
  while (Serial.available() < 1){} // Wait for user to enter something
  
  for(int i =0; i<100 ; i++){ // capture 100 data points of object falling
    digitalWrite(trigpin, HIGH); // send out ultrasonic sensor
    delayMicroseconds(10); // delay for 10 
    digitalWrite(trigpin,LOW); // turn off out signal
    ping_time = pulseIn(echopin, HIGH); // read in how long it takes for signal to return
    falltime = micros(); // get time measurement
    // print tab seperated results to output
    Serial.print("\t");
    Serial.print(falltime);
    Serial.print("\t");
    Serial.println(ping_time); 
    Serial.read();
  }
}
