#pragma config(Sensor, dgtl1,  limit,          sensorTouch)
#pragma config(Sensor, dgtl2,  startBump,      sensorTouch)
#pragma config(Sensor, dgtl3,  led,            sensorLEDtoVCC)
#pragma config(Motor,  port2,           wheel,         tmotorServoContinuousRotation, openLoop, reversed)
#pragma config(Motor,  port3,           conveyor,      tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port8,           mixer,         tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port1,           flashlight,    tmotorServoContinuousRotation, openLoop, reversed)

#include "jobs.h"

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

	while(true){ //always run
		motor[flashlight] = -127;
		beltRun(50); //void to run the conveyor belt at 1/4 full speed
		mix(30); //void to turn the stirring rod at a speed of 30
		delay(50); //scan for 50 ms
	}
}
