#include <ezButton.h>

#define echoPin 52 
#define trigPin 53

#define VRX_PIN A0
#define VRY_PIN A1
#define SW_PIN 6

#define LEFT_THRESHOLD 107
#define RGHT_THRESHOLD 907
#define FRWD_THRESHOLD 107
#define RVRS_THRESHOLD 907

#define COMMAND_NO     0x00
#define COMMAND_LEFT   0x01
#define COMMAND_RIGHT  0x02
#define COMMAND_UP     0x04
#define COMMAND_DOWN   0x08

ezButton button(SW_PIN);

int xValue = 507;
int yValue = 507;
int bValue = 0;
int command = COMMAND_NO;

int acceler = 2;
int reverse = 3;

int rghtTurn = 4;
int leftTurn = 5;

long duration;
int distance;

void setup() {
  Serial.begin(9600);
  button.setDebounceTime(50); //set debounce time to 50 milliseconds

  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT

  Serial.println("Ultrasonic Sensor HC-SR04 Test"); // print some text in Serial Monitor
  Serial.println("with Arduino UNO R3");
  
  pinMode(LED_BUILTIN, OUTPUT); //built in LED
  
  pinMode(acceler, OUTPUT);
  pinMode(reverse, OUTPUT);
  pinMode(leftTurn, OUTPUT);
  pinMode(rghtTurn, OUTPUT);
}

void loop() {
  button.loop();
  
  xValue = analogRead(VRX_PIN);
  yValue = analogRead(VRY_PIN);

  if (xValue == 507) {
    Serial.println("CENTERED");
    digitalWrite(leftTurn, LOW);
    digitalWrite(rghtTurn, LOW);
    }
    
  if (xValue < LEFT_THRESHOLD) {
    Serial.println("TURN LEFT");
    digitalWrite(rghtTurn, LOW);
    digitalWrite(leftTurn, HIGH);
    }

  if (xValue > RGHT_THRESHOLD) {
    Serial.println("TURN RIGHT");
    digitalWrite(leftTurn, LOW);
    digitalWrite(rghtTurn, HIGH);
    }
  
  }

  if (yValue < FRWD_THRESHOLD) {
    Serial.println("GO FORWARD");
    digitalWrite(reverse, LOW); 
    digitalWrite(acceler, HIGH);
  }

  if (yValue > RVRS_THRESHOLD) {
    Serial.println("GO BACKWARDS");
    digitalWrite(acceler, LOW);
    digitalWrite(reverse, HIGH);
  }

  if (yValue == 507) {
    Serial.println("STOPPED");
    digitalWrite(acceler, LOW);
    digitalWrite(reverse, LOW);
  }

/////////////////////////////////////////////////////

  bValue = button.getState();
  
  if (button.isPressed()) {
    Serial.println("The button is pressed.");
    //TODO Add button logic (headlights)
  }

  if (button.isReleased()) {
    Serial.println("The button is released.");
    //TODO Add button logic (headlights)
  }
////////////////////////////////////////////////////
  Serial.print("x = ");
  Serial.print(xValue);
  
  Serial.print(", y = ");
  Serial.println(yValue);
  
  Serial.println(" : button =");
  Serial.println(bValue);
  
  delay(200);
   // put your main code here, to run repeatedly:   
 
  //digitalWrite(motor2pin1, HIGH);
  //digitalWrite(motor2pin2, LOW);
  //digitalWrite(motor2pin1, LOW);
  //digitalWrite(motor2pin2, HIGH);
  //digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  //delay(100);                       // wait for a second
  //digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  //delay(100);  // wait for a second

  // Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  
  // Displays the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
}
