int out = 9;
int j;
double V; // voltage variable could be a float...

void setup() {
  Serial.begin(9600); // initialize serial monitor
  pinMode(out, OUTPUT);
  pinMode(A0, INPUT); // initialize input for voltage
}

void loop() {
  analogWrite(out, 250);
  //for(j=1;j<=100;j=j+1){ //loop 100 times
    //Serial.println(j);
  //}
  V = analogRead(A0); // reads value 0 to 1023 not an actual voltage
  Serial.println(V *  5 / 1023); // calculate voltage of 5V * 
  delay(1000);
  
}
