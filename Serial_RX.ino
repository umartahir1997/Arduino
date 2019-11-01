/*Prompts user for number of times to blink red led and yellow led. After process cycles, user prompted again. Could have written prompt logic in void setupt() to only prompt user once( At time of power up 
  or some other event. user also prompted ONCE on blink on/off time parameters.*/

int redLEDPin = 9; //Declaring redLEDPin as an int, and setting it to 9.
int yellowLEDPin = 10; //Declaring yellowLEDPin as int and set it to 10.
int redOnTime;// This is the red LED on-time.
int redOffTime;// This is the red off-time. 
int yellowOnTime;// This is the yellow on time.
int yellowOffTime;// This is the yellow off time. 
int numREDblinks; //counter for red led blinks.
int numYellowblinks; //counter for yellow led blinks.
String redMessage = "The RED LED is Blinking";
String yellowMessage = "The Yellow LED is Blinking";


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);// Setup serial communication over COM port.
  pinMode(redLEDPin, OUTPUT); //configures GPIOs as input or outputs(D/A)
  pinMode(yellowLEDPin, OUTPUT);

  Serial.println("How long do you want the red LED to be on for? ");// prompt user.
  while(Serial.available() == 0){ }// stuck here as long as serial buffer is empty. could also do if(Serial.available()>0){ do someting }
  redOnTime = Serial.parseInt();
  Serial.println("You entered "+ String(redOnTime)+" ms");

  serialFlush();

  Serial.println("How long do you want the red LED to be off for? ");// prompt user.
  while(Serial.available() == 0){ }// stuck here as long as serial buffer is empty.
  redOffTime = Serial.parseInt();
  Serial.println("You entered "+ String(redOffTime)+" ms");

  serialFlush();

  Serial.println("How long do you want the yellow LED to be on for? ");// prompt user.
  while(Serial.available() == 0){ }// stuck here as long as serial buffer is empty.
  yellowOnTime = Serial.parseInt();
  Serial.println("You entered "+ String(yellowOnTime)+" ms");

  serialFlush();

  Serial.println("How long do you want the yellow LED to be off for? ");// prompt user.
  while(Serial.available() == 0){ }// stuck here as long as serial buffer is empty.
  yellowOffTime = Serial.parseInt();
  Serial.println("You entered "+ String(yellowOffTime)+" ms");

  serialFlush();
  
}

void serialFlush(){
  while(Serial.available() > 0) {
    char t = Serial.read();  // apparently parsInt does not clear the buffer, ensure buffer is cleared before reading next parameter. 
  }
}   

void loop() {
  // put your main code here, to run repeatedly:
Serial.println("How many times do you want the red LED to blink? ");// prompt user.
while(Serial.available() == 0){ // stuck here as long as serial buffer is empty.
  /* do not do anything(could also have used while loop.
   if(Serial.available() >0){
   blinks = Serial.read();
   }
  */
}
numREDblinks = Serial.parseInt();// could pass a character to ignore as parameter to function call.
Serial.println("You entered "+ String(numREDblinks)+" blinks");
serialFlush();

Serial.println("How many times do you want the Yellow LED to blink? ");// prompt user.
while(Serial.available() == 0){ // stuck here as long as serial buffer is empty.
  /* do not do anything(could also have used while loop.
   if(Serial.available() >0){
   blinks = Serial.read();
   }
  */
}
numYellowblinks = Serial.parseInt();// could pass a character to ignore as parameter to function call.
Serial.println("You entered "+ String(numYellowblinks)+" blinks");
serialFlush();

Serial.println(redMessage);
  for(int i=1;i<numREDblinks+1;i++) {
    Serial.print("   You are on blink#: ");//NOTE:Can concatenate in arduino env. as well.
    Serial.println(i);//print iteration number
    digitalWrite(redLEDPin, HIGH);//Turn on red led
    delay(redOnTime); //Wait
    digitalWrite(redLEDPin, LOW); //turn the red led off
    delay(redOffTime); //Wait
  }
 Serial.println(" ");//blank line for distinguishing red blink prints from yellow.

Serial.println(yellowMessage);
   for(int j=1;j<numYellowblinks+1;j++) {
    Serial.print("   You are on blink#: ");
    Serial.println(j);//print iteration number
    digitalWrite(yellowLEDPin, HIGH);//Turn on red led
    delay(yellowOnTime); //Wait
    digitalWrite(yellowLEDPin, LOW); //turn the red led off
    delay(yellowOffTime); //Wait
  }
 Serial.println(" ");//blank line for cleaner output. 
}
