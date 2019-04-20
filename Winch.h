#ifndef Winch_h
#define Winch_h

#include "Arduino.h"
#include <Servo.h>

class Winch {
  public:
    Winch(int upPin, int downPin, int centerValue);
    void up();
    void down();
    bool isDown();
    void attachServo(int servoPin);
  private:
    Servo _servo;
    int _upPin;
    int _downPin;
    void _stop();
    int _centerValue;
};

#endif
