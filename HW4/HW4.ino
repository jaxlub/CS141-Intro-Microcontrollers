int Bpin = 6; // Pin for Blue LED
int Rpin = 4; // Pin for Red LED
int Gpin = 2; // Pin for Green LED
int L; // LED variable  
int B; // Number of blinks variable
int i; // counter for for-loop

void setup() {
  pinMode(Bpin,OUTPUT); // Initializing Blue LED
  pinMode(Rpin,OUTPUT); // Initializing Red LED
  pinMode(Gpin,OUTPUT); // Initializing Green LED
  Serial.begin(9600); // Initializing Serial Monitor
}

void loop() {
  // Print LED color options
  Serial.println("Choose LED Color:");
  Serial.println("1: Blue");
  Serial.println("2: Red");
  Serial.println("3: Green");
  while (Serial.available() == 0){} // Wait for user to enter something
  L = Serial.parseInt(); // read int into L 
  if (L == 1 | L == 2 | L == 3){ 
    // if its a valid number ask # of blinks
    Serial.println("Blink Count?");
    while (Serial.available() == 1){} // Wait for user to enter something
    B = Serial.parseInt(); // read int into B
    for(i = 0; i < B; i = i+1){ 
      // Loop B times blinking the L light
      // all delays are so on/off is clear to user
      if(L == 1){ // 1 = Blue LED
        digitalWrite(Bpin, HIGH); // Turn on Blue
        delay(200);
        digitalWrite(Bpin, LOW); // Turn off Blue
        delay(200);
      }
      if(L == 2){ // 2 = Red LED
        digitalWrite(Rpin, HIGH); // Turn on Red LED
        delay(200);
        digitalWrite(Rpin, LOW); // Turn off Red LED
        delay(200);
      }
      if(L == 3){ // 3 = Green LED
        digitalWrite(Gpin, HIGH); // Turn on Green LED
        delay(200);
        digitalWrite(Gpin, LOW); // Turn off Green LED
        delay(200);
      }
    }
   } else {
    Serial.println("Error: Invalid Input"); 
    // If user entered something other then 1,2,3 then Error
   }
}
