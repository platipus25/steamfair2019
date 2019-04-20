#include <Servo.h>
#include "Winch.h"


Winch drawbridge(5, 4, 96); // 10
int servoCenter = 96;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(6, INPUT_PULLUP);
  drawbridge.attachServo(10);
  //drawbridge.up();
  //drawbridge.down();
  
}

void loop() {
  // put your main code here, to run repeatedly:
  //Serial.println("Whoop!");
  if(digitalRead(6) == LOW){
    Serial.println("Button press");
    toggle();
  }
  delay(100);
}

void toggle(){
  if(drawbridge.isDown()){
    drawbridge.up();
  }else{
    drawbridge.down();
  }
}
