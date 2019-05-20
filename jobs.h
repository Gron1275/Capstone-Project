void mix(int speed){
	while(true){								//runs stirring rod at a parameter defined speed
		motor[mixer] = speed;
	}
}
void beltRun(int speed){
	while(true){							  //runs conveyor belt at a parameter defined speed
		motor[conveyor] = speed;
	}
}
void tilt(int side){ //tilts the seesaw attatchment to either the left or the right depending on the m&m color
	// 0 is equal to left
	// 1 is equal to right
	if(side == 0){ //if the side is equal to 0 (left), then tilt the seesaw to that side so m&m is sorted
		motor[seesaw] = -63; //the speed that the seesaw is tilted at is 63
		turnLEDOn(led); //led is only for testing to show that the void works as it should
		motor[seesaw] = 0;
	}
	if(side == 1){ //if the side is equal to 1 (right), then tilt the seesaw to that side so m&m is sorted
		motor[seesaw] = 63; //the speed that the seesaw is tilted at
		delay(50);
		motor[seesaw] = 0;
	}
}

task sortSide()
{
	// 0 is equal to left
	// 1 is equal to right
	if(colorSense >= 100){ //if the color is sensed as say, red, then tilt to the left and deposit the m&m
		tilt(0); //void tilt to tilt seesaw left at a speed of 63
	}
	if(colorSense <= 100){ //if the color is sensed as say, green, then tilt to the right and deposit the m&m
		tilt(1); //void tilt to tilt seesaw right speed of 63
	}
}
