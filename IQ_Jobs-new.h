void sensorInit()
{
	string x = getColorValue(colorSense);
	setTouchLEDBlinkTime(feedbackLED, 5, 2.5);
	setTouchLEDColor(feedbackLED, colorOrange);
	if(getColorProximity(colorSense) <= 150){
		//displayCenteredBigTextLine(2, y);
		//displayCenteredBigTextLine(2, x);
		displayBigTextLine(2, "%s", z);

	}
}
void tilt(int side) //tilts the seesaw attatchment to either the left or the right depending on the m&m colo
{
	// 0 is equal to left
	// 1 is equal to right
	if(side == 0){ //if the side is equal to 0 (left), then tilt the seesaw to that side so m&m is sorted
		//motor[seesaw] = -63; //the speed that the seesaw is tilted at is 63
		setTouchLEDColor(feedbackLED, colorRed); //change LED to red
		displayCenteredBigTextLine(2, "RED");
		setMotorSpeed(seesaw, -60);
		delay(1000);
		//motor[seesaw] = 0;
	}
	if(side == 1){ //if the side is equal to 1 (right), then tilt the seesaw to that side so m&m is sorted
		//motor[seesaw] = 63; //the speed that the seesaw is tilted at
		setTouchLEDColor(feedbackLED, colorGreen); //change led to green
		displayCenteredBigTextLine(2, "GREEN");
		setMotorSpeed(seesaw, 60);
		delay(1000);
		//motor[seesaw] = 0;
	} //void is pseudo-ish rn
}
task sortSide()
{
	//char colorVal = getColorName(colorSense);
	while(true){
		// 0 is equal to left
		// 1 is equal to right
		if(getColorName(colorSense) == colorGreen){ //if the color is sensed as say, red, then tilt to the left and deposit the m&m
			tilt(1); //void tilt to tilt seesaw left at a speed of 63
		}
		if(getColorName(colorSense) == colorRed){ //if the color is sensed as say, green, then tilt to the right and deposit the m&m
			tilt(0); //void tilt to tilt seesaw right speed of 63
		}
		else{
			displayCenteredBigTextLine(2, z);
			//setTouchLEDColor(feedbackLED, x);


		}
		y = getColorMode(colorSense);
		g = getColorMode(colorSense);
		z = getColorName(colorSense);
	}
}
