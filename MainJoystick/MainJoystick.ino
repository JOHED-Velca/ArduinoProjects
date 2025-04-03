#include <Servo.h>
#define sw 6
#define screenWidth 240
#define screenHeight 320
Servo servo1;
int val = 0;
int joystickValue = 0;
int servoPos = 0;

int motor1pin1 = 2;
int motor1pin2 = 3;

int motor2pin1 = 4;
int motor2pin2 = 5;

void setup() {
  Serial.begin(9600);
  pinMode(sw, INPUT_PULLUP); //setting pinsw as input 
  pinMode(LED_BUILTIN, OUTPUT);
  servo1.attach(7);

  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(motor2pin1, OUTPUT);
  pinMode(motor2pin2, OUTPUT);

  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
}

void loop() {
  val = analogRead(joystickValue);
  int x = analogRead(A0);
  int y = analogRead(A1);

  analogWrite(9, 150); //motor 1 speed right
  analogWrite(10, 150); //motor 2 speed left

  if(x > 515) {
    Serial.println("Moving in -X axis Backwards.");

    // digitalWrite(motor1pin1, LOW);
    // digitalWrite(motor1pin2, HIGH);

    // digitalWrite(motor2pin1, LOW);
    // digitalWrite(motor2pin2, HIGH);
  }
  else if(x < 505){
    Serial.println("Moving in +X axis Forward.");

    // digitalWrite(motor1pin1, HIGH);
    // digitalWrite(motor1pin2, LOW);

    // digitalWrite(motor2pin1, HIGH);
    // digitalWrite(motor2pin2, LOW);
  }
  else if(y > 515){
    Serial.println("Moving in +Y axis Turn Right.");
    servo1.write(-100);
  }
  else if(y < 505){
    Serial.println("Moving in -Y axis Turn Left.");
    servo1.write(+180);
  }
}
