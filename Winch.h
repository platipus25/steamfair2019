#ifndef Winch_h
#define Winch_h

#include "Arduino.h"
#include <Servo.h>

class Winch {
  public:
    Winch(int upPin, int downPin, int centerValue);
    void attachServo(int servoPin);
    void up();
    void down();
    void toggle();
    bool isDown();
  private:
    int _upPin;
    int _downPin;
    int _centerValue;
    void _stop();
    Servo _servo;
};

#endif
