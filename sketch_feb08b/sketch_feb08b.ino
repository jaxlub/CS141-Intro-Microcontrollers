int i;
void setup() {
  pinMode(11, OUTPUT);
}

void loop() {
 for( i= 0; i < 50000; i = i+1){
  delayMicroseconds(10);
  analogWrite(11,255);
  delayMicroseconds(10);
  analogWrite(11,0);
  }
 for( i= 0; i < 5000; i = i+1){
  delayMicroseconds(100);
  analogWrite(11,255);
  delayMicroseconds(100);
  analogWrite(11,0);
  }

 for( i= 0; i < 500; i = i+1){
  delayMicroseconds(1000);
  analogWrite(11,255);
  delayMicroseconds(1000);
  analogWrite(11,0);
  }
}
