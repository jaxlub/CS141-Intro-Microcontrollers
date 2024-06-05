unsigned long ping_time; // value to read in pulse
int trigpin = 10;
int echopin = 11;
float dist;
float velocity;

void setup() {
  pinMode(trigpin, OUTPUT);
  pinMode(echopin, INPUT);
  Serial.begin(9600);
}

void loop() {
  Serial.println("How far are we measuring in M?");
  while (Serial.available() == 0){} // Wait for user to enter something
  dist = Serial.parseFloat(); // read int into L 
  digitalWrite(trigpin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin,LOW);
  ping_time = pulseIn(echopin, HIGH);
  Serial.println(dist);
  Serial.println(ping_time); 
  Serial.read();
  velocity = (dist*2.) / (ping_time/1000000.);
  Serial.println("Velocity " + String(velocity) + " M/S");
}
