#include <Servo.h>
#include "Winch.h"


Winch drawbridge(5, 4, 96); // 10
int servoCenter = 96;

void setup() {
  Serial.begin(9600);
  pinMode(6, INPUT_PULLUP);
  drawbridge.attachServo(10);
  
}

void loop() {
  if(digitalRead(6) == LOW){
    Serial.println("Button press");
    drawbridge.toggle();
  }
  delay(100);
}
