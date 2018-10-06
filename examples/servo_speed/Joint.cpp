/*
 * Joint.cpp - Library for servo control with speed adjustment
 * Created by ZAIN (zainey4@gmail.com) 06/10/18
 * The code has been based on servo library 
    and examples on adafruit for timmer interupt 
 */



#include "Joint.h"

   Joint::Joint()   // interval will not be needed here.
    {
      //updateInterval = interval;
      increment = 1;
      allDone = true;
    }

    void Joint::Attach(int pin)
    {
      servo.attach(pin);
    }

    void Joint::Detach()
    {
      servo.detach();
    }

    void Joint::setTarget(int newTarget, int deltaTime)    // newTarget in degrees; deltaTime in milliseconds
    {
      target = newTarget;   // Need limits checking!!
      // May need to check if done first?
      if (target < oldPos) {
        updateInterval = deltaTime / (oldPos - target);   // need to make sure this is > 1!!!
        increment = -1;
        allDone = false;
      } else if (target > oldPos) {
        updateInterval = deltaTime / (target - oldPos);
        increment = 1;
        allDone = false;
      }
    }

    void Joint::reset()
    {
      pos = 0;
      servo.write(pos);
      oldPos = 0;
      allDone = true;
      increment = abs(increment);
    }

    void Joint::resetTo(int startPos)
    {
      pos = startPos;
      servo.write(pos);
      oldPos = pos;
      allDone = true;
      increment = abs(increment);
    }

    void Joint::Update(unsigned long currentMillis) {
      if (!allDone) {
        if ((currentMillis - lastUpdate) > updateInterval){      // time to update
          lastUpdate = currentMillis;
         // digitalWrite(6,HIGH);
        pos += increment;
        servo.write(pos);
        if (increment > 0) {    // means we're increasing
          if (pos >= target) {
            allDone = true;
            oldPos = pos;
          }
        }
        else {     // decreasing
          if (pos <= target) {
            allDone = true;
            oldPos = pos;
          }
        }
      }
    }
    }

