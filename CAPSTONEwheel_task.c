#pragma config(Sensor, in1,    colorSense,     sensorReflection)
#pragma config(Sensor, dgtl1,  limit,          sensorTouch)
#pragma config(Sensor, dgtl2,  startBump,      sensorTouch)
#pragma config(Sensor, dgtl3,  led,            sensorLEDtoVCC)
#pragma config(Sensor, dgtl4,  tiltLeft,     sensorTouch)
#pragma config(Sensor, dgtl5,  tiltRight,      sensorTouch)
#pragma config(Motor,  port2,           wheel,         tmotorServoContinuousRotation, openLoop, reversed)
#pragma config(Motor,  port3,           conveyor,      tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port4,           mixer,         tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port5,           seesaw,        tmotorServoContinuousRotation, openLoop)

#include "jobs.h"
//#include "tasks.c"

int pauseLen = 0;



task tickControl() //tickControl is made to regulate the frequency of m&ms being deposited onto the conveyor belt
{
	while(true){ //always run

		motor[wheel] = 40; //have the wheel turn until the limit is hit (which happens to happen almost every second)

		untilTouch(limit); //when the limit is hit, do the code listed below

		motor[wheel] = 0; //stop the wheel from turning
		wait(pauseLen); //wait n seconds before starting wheel motor again0
	}
}

task main()
{
	pauseLen = 3; //starting length of pause which can be changed using the two bump switches

	startTask(tickControl); //Run tickControl
	startTask(sortSide); //this turns the seesaw to either the left or right depending on if the m&m is green or red

	while(true){ //always be runnin'
		beltRun(63); //void to run the conveyor belt at a speed of 63
		mix(20); //void to turn the stirring rod at a speed of 20
		if(SensorValue[tiltLeft] == 1){ //this is an incremental regulator for the pauseLen variable
			tilt(0); //tilt it left cup
		}
		if(SensorValue[tiltRight] == 1){ //this is an incremental regulator for the pauseLen variable
			tilt(1); //tilt to right cup
		}

		delay(5); //scan for 5 ms cause idk why
	}
}
