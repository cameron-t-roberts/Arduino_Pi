/* 
 *  Basic Stepper Motor Control Program. 
 *  
 *  Focus on moving distance. This assumes that the motor will be driving a pully or a wheel of some form. 
 *  
 *  Need to know circumference of wheel. Then divide 360 by circumference to get rotation factor. 
 *  
 *  Rotation factor is based on needs, if distance used in project is Inches and circumference is in inches then / by that number.  Circumference and Distance used need to be same unit. 
 *  
 *  Basic Logic:
 *  Define motor parameters
 *  
 *  Input distance to move
 *  Calculate distance to move with distance per revolution. 
 *  
 *  The loop uses set number ot steps per revolution * revolution factor to determine how many steps to take and rotate the motor. 
 *
 */



#include <Stepper.h> 

// Sets Motor Constraints
const int stepsPerRevolution = 2048;    // number of steps per full revolution
const int revolutionsPerMinute = 15; // adjustable range for 28BYJ-48 stepper motor is 0-17 rpm


/* Calculate Movement:

This example assumes a 2" diameter pulley is attached to motor. 2" diameter * 3.14 = 6.28 inch circumference
The wheel would travel 6.28  inch per 360 degree. 
*/

double distanceInch = 0.5; // EDIT THIS - inches for wheel to move - could be ultrasonic distance sensing or user input in future
double rotationFactor = (distanceInch / 6.28); // divides input by 6.28 wheel circumference = 1 full revolution. needs a cooler name for sure



Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11); // initialize the stepper library on pins 8 through 11. 8 & 10 one coil, 9 & 11 are other coil

// Program Setup
void setup() {
  myStepper.setSpeed(revolutionsPerMinute);
  // initialize the serial port:
  Serial.begin(9600);
}


// Main Program Loop
void loop() {

// Movement of motor - Clockwise
Serial.println("Clockwise");
myStepper.step(stepsPerRevolution * rotationFactor); // Steps for 1 full revolution * rotation variable. This allows full revolutions or partial revolutions. 
delay(1000);


}
