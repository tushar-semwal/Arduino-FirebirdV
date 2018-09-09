/*
  A sample code to control the motors.
  Created by Tushar Semwal, September 2, 2018.
  Released into the public domain.
*/

#include <Firebird.h>

Firebird fb;
void setup() {
  // put your setup code here, to run once:
  fb.configMotors();
 }

void loop() {
  // put your main code here, to run repeatedly:
  fb.moveForward(100,100);
  delay(3000);
  fb.moveBackward(100,100);
  delay(3000);
  fb.stopMotors();
  delay(1000);
  fb.moveForwardL(100);
  fb.moveBackwardR(100);
  delay(2000);
  fb.stopMotors();
  delay(1000);
  fb.moveForwardR(100);
  fb.moveBackwardL(100);
  delay(2000);
   
  
}
