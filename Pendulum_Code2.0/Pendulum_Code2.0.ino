int IR_read = A1; // pin for reading IR via reciever
int in_val; // variable to store read in values
unsigned long run_time; // variable to keep track of time
int count = 0; // counter variable

void setup() {
  pinMode(IR_read, INPUT); // initialize reciever pin
  Serial.begin(9600); // initialze serial monitor
}


void loop() {
  for(int i=1; i <2000; i++){ // loop a bunch
    in_val = analogRead(IR_read); // read in IR signal
    if(in_val < 10){ // if signal is blocked
      run_time = millis(); // collect the time programs been running
      Serial.print("\t"); // print tab and runtime to monitor (tab is for ease of moving to excel)
      Serial.println(run_time);
      delay(100); // delay to prevent extra reads of the same time while still blocked
      count++; // increase counter of number of passes measured
    }
    if (count>=10){ // Once we get 10 data points
      delay(30000); // delay a lot to copy data over to excel
    }
  }
}
