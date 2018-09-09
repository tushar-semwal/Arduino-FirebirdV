/*
  Firebird.h - Library for Firebird V robot by Nex-Robotics.
  Created by Tushar Semwal, September 2, 2018. Adapted from Nex-Robotics. Due credits to them.
  Released into the public domain.
*/

#ifndef Firebird_h
#define Firebird_h

#if ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
  #include "pins_arduino.h"
  #include "WConstants.h"
#endif

class Firebird
{
	public:
		Firebird();
		
		unsigned int readBattery(void);
		float readBatteryVolt(void);
		
		unsigned int readLine1(void);
		unsigned int readLine2(void);
		unsigned int readLine3(void);
		
		
		unsigned int readIR1(void);
		unsigned int readIR2(void);
		unsigned int readIR3(void);
		unsigned int readIR4(void);
		unsigned int readIR5(void);
		
		
		unsigned int readSharpIR1(void);
		unsigned int readSharpIR2(void);
		unsigned int readSharpIR3(void);
		unsigned int readSharpIR4(void);
		unsigned int readSharpIR5(void);
		//int *readSharpIRAll(void);
		unsigned int sharpDistance(unsigned int);
		
		void buzzerOn(void);
		void buzzerOff(void);
		
		void initBargraph(void);
		void showBargraph(int level); //value between 0 to 255
		
		void configMotors(void);
		void stopMotors(void);
		void moveForward(int leftSpeed, int rightSpeed); //speed ranges from 0 to 255
		void moveBackward(int leftSpeed, int rightSpeed);
		void moveForwardL(int leftSpeed);
		void moveForwardR(int rightSpeed);
		void moveBackwardL(int leftSpeed);
		void moveBackwardR(int rightSpeed);
		
		
		
		
		
};



#endif
