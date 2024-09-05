/* 
 *  Basic Stepper Motor Control Program. 
 *  
 *  Focus on degrees of movement and steps. 
 *  
 *  This probram is for movements less than 360 degrees. Stepper3 program is a better solution for more situations most likely. 
 *  
 *  This program would be really useful if you need to precicly move the angle of something. Resolution to 0.175 of a degree. Possibly star tracking program?
 * 
STEP to Degree Rotation Breakdown:
2048 Steps per revolution == 5.68 steps per 1 degree
Degree:: Steps
360 :: 2048
270 :: 1536
180 :: 1024
90  :: 512
45  :: 256
22.5 :: 128
11.25 :: 64
5.625 :: 32
2.812 :: 16
1.406 :: 8
0.703 :: 4
0.351 :: 2
0.175 :: 1

 */



#include <Stepper.h> 


const int stepsPerRevolution = 2048;    // number of steps per full revolution
const int revolutionsPerMinute = 15; // adjustable range for 28BYJ-48 stepper motor is 0-17 rpm

// calculate steps to move

double changeDegree = 360; // EDIT THIS - Change how much you want to move per loop. Must be <= 360 or motor locks

double stepChange = (changeDegree * 5.6888); // each degree = 5.6 steps

Stepper myStepper(stepChange, 8, 10, 9, 11); // initialize the stepper library on pins 8 through 11. 8 & 10 one coil, 9 & 11 are other coil

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
myStepper.step(stepChange);
delay(500);

// Movement of motor - Counter-Clockwise
Serial.println("Counter-Clockwise");
myStepper.step(-stepChange);
delay(500);

}
