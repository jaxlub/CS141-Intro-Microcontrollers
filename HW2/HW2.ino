
int Yled = 9; // pin ~9 for yellow light
int Gled = 10; // pin ~10 for green light
int j; // counter for loop 1
int i; // counter for loop 2
int r; // counter for loop 3

void setup() {
    pinMode(Yled, OUTPUT); // Declare yellow pin
    pinMode(Gled, OUTPUT); // Declare green pin
}

void loop() {
  // want to increase Green over 2 second period so delay at 
  // 2000 ms/255 = ~ 8 ms delay per loop
   for (int i = 0; i < 256; i = i + 1){
      analogWrite(Gled, i); // turn green up a little 
      delay(8);
   }
  // want to increase Yellow over 1 second period so delay at 
  // 1000 ms/255 = ~ 4 ms delay per loop
   for (int j = 0; j < 256; j = j + 1){
      analogWrite(Yled, j); // turn yellow up a little
      delay(4); 
   }
   // want to decrease both over 4 seconds so delay at
   // 4000ms/255 = ~16 ms delay per loop
   for (int r = 255; r > 0; r = r - 1){
      analogWrite(Yled, r); // turn yellow down a little 
      analogWrite(Gled, r); // turn green down a little 
      delay(16);
   }
}
