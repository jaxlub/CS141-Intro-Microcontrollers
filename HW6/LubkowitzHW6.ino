int PRpin = A0; // Pin for PR
int buzz = 10; // Pin for buzzer
int PR; //PR values from photoresistor w/ 5000 ohm resistor
float freq_val; // mapping value
int periods; // number of loops needed for 100ms
int i; // loop counter
int delay_val; // Delay value for Freq

void setup() {
  pinMode(buzz, OUTPUT); // initialize buzzer
  pinMode(PRpin, INPUT); // initializse PR reader
  Serial.begin(9600); // initialize serial moniter
}

void loop() {
  PR = analogRead(PRpin);
  // values range from 155 to 660 so this is what I will map with 
  // Error catching in case value exceeds 155-660 range
  if (PR < 155) { // if light val is less then 155 set to 155 for mapping
    PR = 155;
  }
  if (PR > 660){ // if light val is greater then 660 set to 660 for mapping
    PR = 660;
  }
/*
 * High brightness = Higher Frequency 
 * High Freq = 2000 Hz
 * Low Freq = 100 Hz
*/
freq_val = map(PR, 155, 660, 100, 2000); // map PR to Frequency
// if PR is 155 it maps to 100 Hz and if 660 then map to 2000 Hz

// Tone should play for 100 ms
// F = P/S
// F = freq_val
// S = .1 so then the # of periods in 100 ms = freq_val/.1
periods = freq_val/.1; // F = P/S ... freq_val/.1 seconds = # of periods in 100 ms

// Calc Delay 
// .1 seconds / periods /2 (for delay on/off) * 1 million microseconds = x microseconds
// This is the same as 1 second/(freq_val*2) * 1 million microseconds = x microseconds for each delay
delay_val = .1 / freq_val/2 * 1000000; // calc delay value
for(i= 0; i < periods; i = i+1){ // loop periods times for total of 100 ms
    analogWrite(buzz,255); // buzzer on for delay_val microseconds
    delayMicroseconds(delay_val); // delay for desired freq
    analogWrite(buzz,0); // buzzer off for delay_val microseconds
    delayMicroseconds(delay_val); // delay for desired freq
  }
  

}
