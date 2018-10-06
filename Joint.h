/*
 * Joint.h - Library for servo control with speed adjustment
 * Created by ZAIN (zainey4@gmail.com) 06/10/18
 * The code has been based on servo library 
    and examples on adafruit for timmer interupt 
 */


#ifndef _Joint_h_
#define _Joint_h_

#include <Servo.h>
#include "Arduino.h"


class Joint{

   
      Servo servo;              // the servo
      int  updateInterval;      // interval between updates  
      volatile int pos;                  // current servo position
      volatile unsigned long lastUpdate; // last update of position
      volatile int increment;            // increment to move for each interval
      volatile int oldPos;
     // volatile int newPos;
      volatile int target;
      volatile boolean allDone;

  public:
     Joint();   // interval will not be needed here.   
    void Attach(int pin); 
    void Detach(); 
    void setTarget(int newTarget, int deltaTime);    // newTarget in degrees; deltaTime in milliseconds    
    void reset();    
    void resetTo(int startPos);
    void Update(unsigned long currentMillis);    
};

#endif
//Joint.servo1(25);   // number is the update rate (every 25 milliseconds)

