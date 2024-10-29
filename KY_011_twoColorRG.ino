const int redPin = 10;    // Connect to R pin
//const int greenPin = 9;   // Connect to G pin
const int yellowPin = 11; // Connect to Y pin
int val;

void setup() {
  pinMode(redPin, OUTPUT);
  //pinMode(greenPin, OUTPUT);
  pinMode(yellowPin, OUTPUT); // If controlling
}

void loop() {
  digitalWrite(redPin, HIGH);   // Turn Red on
  delay(500);                  // Wait for 1 second
  digitalWrite(redPin, LOW);    // Turn Red off
  delay(500);                  // Wait for 1 secon                 // Wait for 1 second

  // If you want to use Yellow:
  digitalWrite(yellowPin, HIGH); // Turn Yellow on
  delay(500);                   // Wait for 1 second
  digitalWrite(yellowPin, LOW);  // Turn Yellow off
  delay(500);
  
  //digitalWrite(yellowPin, HIGH);
  //digitalWrite(redPin, HIGH);
  //delay(500);
  //digitalWrite(yellowPin, LOW);
  //digitalWrite(redPin, LOW);
  //delay(500);

  for(val = 255; val > 0; val--) { 
		analogWrite(redPin, val); //dim red
		analogWrite(yellowPin, 255 - val); // brighten green
		delay(15);
	}
  for(val = 0; val < 255; val++) { 
		analogWrite(redPin, val); //brighten red
		analogWrite(yellowPin, 255 - val); //dim green
		delay(15);
	}
  digitalWrite(yellowPin, LOW);
  digitalWrite(redPin, LOW);
  delay(1000);
}
