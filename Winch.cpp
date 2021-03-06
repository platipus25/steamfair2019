#include "Arduino.h"
#include "Winch.h"
#include "Servo.h"

Winch::Winch(int upPin, int downPin, int centerValue){
  _upPin = upPin;
  pinMode(upPin, INPUT_PULLUP);
  _downPin = downPin;
  pinMode(downPin, INPUT_PULLUP);
  _centerValue = centerValue;
}

bool Winch::isDown(){
  if(digitalRead(_upPin) == LOW){
    return false;
  }else if(digitalRead(_downPin) == LOW){
     return true;
  }
}

void Winch::attachServo(int servoPin){
  _servo.attach(servoPin);
  _stop();
  return _servo;
}

void Winch::_stop() {
  _servo.write(_centerValue);
}

void Winch::up(){
  _servo.write(180);
  while(true){
    if(digitalRead(_upPin) == LOW){
      break;
    }
    delay(200);
  }
  _stop();
}

void Winch::down(){
  bool upDidDeactivate = false;
  _servo.write(0);
  while(true){ 

    // error correction:
    upDidDeactivate = upDidDeactivate || digitalRead(_upPin) != LOW; // if truthy stay truthy
    if(upDidDeactivate && digitalRead(_upPin) == LOW){
      if(Serial){
        Serial.println("Abort!");
      }
      upDidDeactivate = false;
      _servo.write(180 - _servo.read());
    }
    
    if(digitalRead(_downPin) == LOW){
      break;
    }
    delay(200);
  }
  _stop();
}

void Winch::toggle(){
  if(isDown() == true){
    up();
  }else if(isDown() == false){
    down();
  }
}
