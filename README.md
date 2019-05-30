# ardiuno-with-interrups
open the file in your ardiuno daspboard
About the interrups in ardiuno
Consider a fast moving car, if it suddenly gets hit by an another car in opposite direction, the first thing happens is the accelerometer sensor present in the car senses a sudden de-acceleration and triggers an external interrupt to the microcontroller present in the car. Then MCU produces an electric signal to deploy the air bags immediately. Microcontroller present in the car monitor many things simultaneously like sensing speed of the car, checking other sensors, controlling air conditioner temperature etc. So what makes a sudden opening of air bag in seconds? An interrupt signal is used here which has the highest priority of all.
Arduino Board

External Interrupt pins:

UNO , NANO

2,3

Mega

2,3,18,19,20,21
Using Interrupts in Arduino
In order to use interrupts in Arduino the following concepts are need to be understood.

 

Interrupt Service Routine (ISR)


 
Interrupt Service Routine or an Interrupt handler is an event that has small set of instructions in it. When an external interrupt occurs, the processor first executes these code that is present in ISR and returns back to state where it left the normal execution.

ISR has following syntax in Arduino:

attachInterrupt(digitalPinToInterrupt(pin), ISR, mode);
 

digitalPinToInterrupt(pin): In Arduino Uno, NANO the pins used for interrupt are 2,3 & in mega 2,3,18,19,20,21. Specify the input pin that is used for external interrupt here.

 

ISR: It is a function that is called when an external interrupt is done.

 

Mode: Type of transition to trigger on, e.g. falling, rising, etc.

RISING:  To trigger an interrupt when the pin transits from LOW to HIGH.
FALLING: To trigger an interrupt when the pin transits from HIGH to LOW.
CHANGE: To trigger an interrupt when the pin transits from LOW to HIGH or HIGH to LOW (i.e., when the pin state changes ).

 
 

Some Conditions while using Interrupt

Interrupt Service Routine function (ISR) must be as short as possible.
Delay () function doesn’t work inside ISR and should be avoided.
