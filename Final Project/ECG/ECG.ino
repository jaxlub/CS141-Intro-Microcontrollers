void setup() {
  pinMode(10,INPUT);
  pinMode(11,INPUT);

}

void loop() {
  Serial.begin(9600);
  if((digitalRead(10)==1)||(digitalRead(11)==1)){
      Serial.println("!");
  }
  else{
      Serial.println(analogRead(A1));
  }
  delay(10);
//  Serial.end();
//  delay(25);
}
