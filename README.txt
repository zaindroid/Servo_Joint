 Joint library for Servo Speed Control

Joint library has been built upon Arduinos default “servo” library. It has been specially crafted to run several servo motors all at a time with additional feature of speed setting i.e. one can adjust the speed of each motor independently and simultaneously. 
Step #1: Including Joint library in your code
In order to use Joint library in arduino, it has to be included first in your sketch using the following command
       
	   #include "Joint.h"
	   
After including this library, now your sketch can access all its methods and attributes through its object instances.


Step #2: Object instantiation
An object of the class Joint can be declared with the following command.
Joint servo1; 
Where “servo1” is the instance of class Joint and all the attributes and methods can be utilized using this instance with dot operator.

Step #3: Pin declaration in hardware setup
In order to control servo in hardware you need to declare pin number on which servo is attached. This is done inside the setup () function of sketch in following way:
	
		servo1.Attach(2);

Where servo1 is the object instance of class Joint declared above and Attach (2); is the method of class Join which connects the motor attached on pin#2 on Arduino.


Step #4: Reset servo motor to default position to avoid jerks
The following routine reset the motor to position 0 angle of servo motor, it can be adjusted as per your requirement. Valid values (0 - 180).  
		
		servo1.resetTo(0);

Step #5: Declaring timer interrupt for motor angle increment
This is the main function that adjusts the speed of the servo motors. Timer 0 is being used for calling an intrupt every millisecond which is then used to update angle increment in servos.
Following routine is used for declaring interrupt for each motor separately.
	
		servo1.Update(currentMillis);

		By default the current Millis variable is set to update angle value in servo after one millisecond and it’s the least value that can achieved with this setup and motor cannot go any faster than this. 

Step #6: Main usage for motor speed control
After all the above setting the motor angle and speed can be finally controlled with the following routine.

servo1.setTarget( angle_value, time in miliseconds );


The above routine takes two argument, first is the desired angle value for servo motor rotation and second is the time in millisecond the motor takes to reach that angle. The valid value for time argument cannot be less than angle value because as shown in step#5 the interrupt can only increment as least as 1 millisecond only. So a valid example is following:

   servo1.setTarget( 90, 90 );

The above code line will rotate to the servo to 90 degrees at fastest rate i.e. in 90 milliseconds. In order to decrease the speed of servo rotation simply increase the value of time argument above as per your desired settings. For example:
Valid formats:
servo1.setTarget( 90, 150 );
servo1.setTarget( 90, 200 );
servo1.setTarget( 90, 300 );
servo1.setTarget( 90, 800 );



------------------------------------------------------------ Thanks--------------------------------------------------------------------

