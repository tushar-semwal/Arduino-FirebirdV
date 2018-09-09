/*
  Firebird.cpp - Library for Firebird V robot by Nex-Robotics.
  Created by Tushar Semwal, September 2, 2018. Adapted from Nex-Robotics. Due credits to them.
  Released into the public domain.
*/

#if ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
  #include "pins_arduino.h"
  #include "WConstants.h"
#endif

#include "Firebird.h"


Firebird::Firebird(void)
{
	configMotors();
	initBargraph();
}

unsigned int Firebird::readBattery(void)
{
	unsigned int batteryValue = 0;
	batteryValue = analogRead(A0);
  	return batteryValue;
}

float Firebird::readBatteryVolt(void) //some issue todo 
{
	float BATT_Voltage;
	BATT_Voltage = ((analogRead(A0)*100)*0.07902) + 0.7;
	return BATT_Voltage;
}

unsigned int Firebird::readLine1(void)
{
	unsigned int val;
	val = analogRead(A3);
	return val;
}

unsigned int Firebird::readLine2(void)
{
	unsigned int val;
	val = analogRead(A2);
	return val;
}

unsigned int Firebird::readLine3(void)
{
	unsigned int val;
	val = analogRead(A1);
	return val;
}

unsigned int Firebird::readIR1(void)
{
	unsigned int val;
	val = analogRead(A4);
	return val;
}

unsigned int Firebird::readIR2(void)
{
	unsigned int val;
	val = analogRead(A5);
	return val;
}

unsigned int Firebird::readIR3(void)
{
	unsigned int val;
	val = analogRead(A6);
	return val;
}

unsigned int Firebird::readIR4(void)
{
	unsigned int val;
	val = analogRead(A7);
	return val;
}

unsigned int Firebird::readIR5(void)
{
	unsigned int val;
	val = analogRead(A8);
	return val;
}



unsigned int Firebird::readSharpIR1(void)
{
	unsigned int val;
	val = analogRead(A9);
	return val;
}


unsigned int Firebird::readSharpIR2(void)
{
	unsigned int val;
	val = analogRead(A10);
	return val;
}


unsigned int Firebird::readSharpIR3(void)
{
	unsigned int val;
	val = analogRead(A11);
	return val;
}


unsigned int Firebird::readSharpIR4(void)
{
	unsigned int val;
	val = analogRead(A12);
	return val;
}


unsigned int Firebird::readSharpIR5(void)
{
	unsigned int val;
	val = analogRead(A13);
	return val;
}

/*
int* Firebird::readSharpALL(void)
{
	static int sharpIRValues[5];
	sharpIRValues[0] = analogRead(A9);
	sharpIRValues[1] = analogRead(A10);
	sharpIRValues[2] = analogRead(A11);
	sharpIRValues[3] = analogRead(A12);
	sharpIRValues[4] = analogRead(A13);
	return sharpIRValues;
}
*/

unsigned int Firebird::sharpDistance(unsigned int rawValue)
{
	float distance;
	unsigned int distanceInt;
	distance = (int)(10.00*(2799.6*(1.00/(pow(rawValue,1.1546)))));
	distanceInt = (int)distance;
	if(distanceInt>800)
	{
		distanceInt=800;
	}
	return distanceInt;
}

void Firebird::buzzerOn(void)
{
	pinMode(34,OUTPUT);
	digitalWrite(34,HIGH);
}


void Firebird::buzzerOff(void)
{
	pinMode(34,OUTPUT);
	digitalWrite(34,LOW);
}

void Firebird::initBargraph(void)
{
	DDRJ = 0xFF;
}


void Firebird::showBargraph(int level)
{
	PORTJ = level;
}

void Firebird::configMotors(void)
{
	pinMode(22,OUTPUT);
	pinMode(23,OUTPUT);
	pinMode(24,OUTPUT);
	pinMode(25,OUTPUT);
  
}

void Firebird::moveForward(int leftSpeed, int rightSpeed)
{
	analogWrite(46,leftSpeed); //left motor PWM -- this is must otherwise motors will be set to 0 speed
	analogWrite(45,rightSpeed); //right motor PWM -- this is must otherwise motors will be set to 0 speed
	digitalWrite(22,LOW);
	digitalWrite(23,HIGH);
	digitalWrite(24,HIGH);
	digitalWrite(25,LOW);
}

void Firebird::moveBackward(int leftSpeed, int rightSpeed)
{
	analogWrite(46,leftSpeed); //left motor PWM -- this is must otherwise motors will be set to 0 speed
	analogWrite(45,rightSpeed); //right motor PWM -- this is must otherwise motors will be set to 0 speed
	digitalWrite(22,HIGH);
	digitalWrite(23,LOW);
	digitalWrite(24,LOW);
	digitalWrite(25,HIGH);
}

void Firebird::moveForwardL(int leftSpeed)
{
	analogWrite(46,leftSpeed); //left motor PWM -- this is must otherwise motors will be set to 0 speed
	digitalWrite(22,LOW);
	digitalWrite(23,HIGH);
	
}

void Firebird::moveForwardR(int rightSpeed)
{
	analogWrite(45,rightSpeed); //left motor PWM -- this is must otherwise motors will be set to 0 speed
	digitalWrite(25,LOW);
	digitalWrite(24,HIGH);
	
}

void Firebird::moveBackwardL(int leftSpeed)
{
	analogWrite(46,leftSpeed); //left motor PWM -- this is must otherwise motors will be set to 0 speed
	digitalWrite(22,HIGH);
	digitalWrite(23,LOW);
	
}

void Firebird::moveBackwardR(int rightSpeed)
{
	analogWrite(45,rightSpeed); //right motor PWM -- this is must otherwise motors will be set to 0 speed
	digitalWrite(24,LOW);
	digitalWrite(25,HIGH);
}

void Firebird::stopMotors(void)
{
	analogWrite(46,0); //left motor PWM -- this is must otherwise motors will be set to 0 speed
	analogWrite(45,0); //right motor PWM -- this is must otherwise motors will be set to 0 speed
}
