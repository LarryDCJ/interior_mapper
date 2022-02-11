#include <ezButton.h>

int reverse = 3;
int acceler = 2;
  
int leftTurn = 5;
int rigtTurn = 4;

#define VRX_PIN A0
#define VRY_PIN A1
#define SW_PIN 6

#define LEFT_THRESHOLD 107
#define RIGT_THRESHOLD 907
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

void setup() {
  Serial.begin(9600);
  button.setDebounceTime(50); //set debounce time to 50 milliseconds

  pinMode(LED_BUILTIN, OUTPUT); //built in LED
  pinMode(acceler, OUTPUT);
  pinMode(reverse, OUTPUT);
  pinMode(leftTurn, OUTPUT);
  pinMode(rigtTurn, OUTPUT);
}

void loop() {
  button.loop();
  
  xValue = analogRead(VRX_PIN);
  yValue = analogRead(VRY_PIN);

///////////////////////////////////////////////////
  if (xValue < LEFT_THRESHOLD) {
    Serial.println("TURN LEFT");
    digitalWrite(rigtTurn, LOW);
    digitalWrite(leftTurn, HIGH);
  }

  if (xValue > RIGT_THRESHOLD) {
    Serial.println("TURN RIGHT");
    digitalWrite(leftTurn, LOW);
    digitalWrite(rigtTurn, HIGH);
  }

  if (xValue == 507) {
    Serial.println("CENTERED");
    digitalWrite(leftTurn, LOW);
    digitalWrite(rigtTurn, LOW);
  }
  
///////////////////////////////////////////////////
  if1 (yValue < FRWD_THRESHOLD) {
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
}
