#pragma config(Sensor, port6,  colorSense,     sensorVexIQ_Color12Color)
#pragma config(Motor,  motor1,          seesaw,        tmotorVexIQ, PIDControl, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "jobsIQ.h"

task main()
{
	startTask(sortSide);

}
