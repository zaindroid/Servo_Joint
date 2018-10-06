
#include "Joint.h"


//--------------- Servo Declerations ---------------------------------
Joint servo1;

void setup()
{

//--------------- Servo Initialization --------------------

servo1.Attach(2);

//-------------------------------------------------------------------
//   // Timer0 is already used for millis() - we'll just interrupt somewhere
//  // in the middle and call the "Compare A" function below
  OCR0A = 0xAF;
  TIMSK0 |= _BV(OCIE0A);
//    attachInterrupt(digitalPinToInterrupt(buttonIntPin), Reset, FALLING);
 
  servo1.reset();
  //servo1.resetTo(0);
 
  
  }
//----------interupt for milisecond tracking--------------------
  ISR(TIMER0_COMPA_vect)
{
  unsigned long currentMillis = millis();
  
  servo1.Update(currentMillis);
 
}
//--------------------------------------------------------------------------

void loop()
{
  
////  in order to drive a servo use the following formatting
//      speed variable can be equal to angle_value for maximum speed at particular angle 
   servo1.setTarget(180, 200 );      
      delay(1000); 
  servo1.setTarget(0, 500 );
       delay(1000);
  }
