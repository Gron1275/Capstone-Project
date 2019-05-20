void tilt(char side) //tilts the seesaw attatchment to either the left or the right depending on the m&m colo
{
	// 0 is equal to left
	// 1 is equal to right
	if(side == "left"){ //if the side is equal to 0 (left), then tilt the seesaw to that side so m&m is sorted
		motor[seesaw] = -63; //the speed that the seesaw is tilted at is 63
		//setTouchLEDColor(ledRG, colorRed); //change LED to red
		delay(50);
		motor[seesaw] = 0;
	}
	if(side == "right"){ //if the side is equal to 1 (right), then tilt the seesaw to that side so m&m is sorted
		motor[seesaw] = 63; //the speed that the seesaw is tilted at
		//setTouchLEDColor(ledRG, colorGreen); //change led to green
		delay(50);
		motor[seesaw] = 0;
	} //void is pseudo-ish rn
}
task sortSide()
{
	char colorVal = getColorName(colorSense);
	while(true){
		// 0 is equal to left
		// 1 is equal to right
		if(getColorName(colorSense) == colorGreen){ //if the color is sensed as say, red, then tilt to the left and deposit the m&m
			tilt('left'); //void tilt to tilt seesaw left at a speed of 63
			displayCenteredBigTextLine(2, "GREEN");
		}
		if(getColorName(colorSense) == colorRed){ //if the color is sensed as say, green, then tilt to the right and deposit the m&m
			tilt('right'); //void tilt to tilt seesaw right speed of 63
			displayCenteredBigTextLine(2, "RED");
		}
		else{
			//setTouchLEDColor(ledRG, colorBlue);
			//changeColor(colorOrange);
			displayCenteredBigTextLine(2, colorVal);
		}
	}
}
