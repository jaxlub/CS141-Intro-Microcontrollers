int IR_read = A1;
int in_val;
unsigned long run_time;

void setup() {
  //Serial.begin(230400);
  pinMode(IR_read, INPUT);
  Serial.begin(9600);
}

void loop() {
  Serial.println("Ready?");
  while (Serial.available() < 1){} // Wait for user to enter something
  for(int i = 0; i <1000; i = i+1){
    in_val = analogRead(IR_read);
    run_time = millis();
    Serial.print("\t");
    Serial.print(run_time);
    Serial.print("\t");
    Serial.println(in_val);
  }
  delay(30000)
}
