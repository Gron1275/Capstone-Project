void conveyorLeft(int speed){
	int negSpeed; //0Find negative of the given number because going to left needs negative values
	negSpeed = speed - speed - speed; //Find negative of number
	setMotorSpeed(seesaw, negSpeed);
	//int timeMS;
	//timeMS = timeSeconds * 1000;
	//delay(timeMS);
	//setMotorSpeed(seesaw, 0);
}

void conveyorRight(int speed){
	setMotorSpeed(seesaw, speed);
	//int timeMS;
	//timeMS = timeSeconds * 1000;
	//delay(timeMS); //This might not actually matter because the while looped task won't wait for the delay to finish before moving on
	//setMotorSpeed(seesaw, 0);
}

void conveyorOff(){
	setMotorSpeed(seesaw, 0);
}

task colorSort(){
	while(true){
		string z = getColorName(colorSense);

		if(z == "\x01"){
			setTouchLEDColor(feedbackLED, colorRedViolet);
			eraseUserScreenArea();
			displayCenteredTextLine(1, "Red Violet");
			displayCenteredTextLine(3, "bytecode [x01]");
			conveyorLeft(60);
			delay(750);
			conveyorOff();
			
		}
		if(z == "\x02"){
			setTouchLEDColor(feedbackLED, colorRed);
			eraseUserScreenArea();
			displayCenteredTextLine(1, "Red");
			displayCenteredTextLine(3, "bytecode [x02]");
			conveyorLeft(60); //I feel like the task should actually be put after this line so that the delay actually
			delay(750);
			conveyorOff();
		}
		if(z == "\x03"){
			setTouchLEDColor(feedbackLED, colorDarkOrange);
			eraseUserScreenArea();
			displayCenteredTextLine(1, "Dark Orange");
			displayCenteredTextLine(3, "bytecode [x03]");
			conveyorLeft(60); //Revised version of conveyorLeft void statement
			delay(750);
			conveyorOff();
		}
		if(z == "\x04"){
			setTouchLEDColor(feedbackLED, colorOrange);
			eraseUserScreenArea();
			displayCenteredTextLine(1, "Orange");
			displayCenteredTextLine(3, "bytecode [x04]");
		}
		if(z == "\x05"){
			setTouchLEDColor(feedbackLED, colorDarkYellow);
			eraseUserScreenArea();
			displayCenteredTextLine(1, "Dark Yellow");
			displayCenteredTextLine(3, "bytecode [x05]");
		}
		if(z == "\x06"){
			setTouchLEDColor(feedbackLED, colorYellow);
			eraseUserScreenArea();
			displayCenteredTextLine(1, "Yellow");
			displayCenteredTextLine(3, "bytecode [x06]");
		}
		if(z == "\x07"){
			setTouchLEDColor(feedbackLED, colorLimeGreen);
			eraseUserScreenArea();
			displayCenteredTextLine(1, "Lime Green");
			displayCenteredTextLine(3, "bytecode [x07]");
			conveyorRight(60);
			delay(750);
			conveyorOff();
			
		}
		if(z == "\x08"){
			setTouchLEDColor(feedbackLED, colorGreen);
			eraseUserScreenArea();
			displayCenteredTextLine(1, "Green");
			displayCenteredTextLine(3, "bytecode [x08]");
			conveyorRight(60);
			delay(750);
			conveyorOff();
		}
		if(z == "\x09"){
			setTouchLEDColor(feedbackLED, colorBlueGreen);
			eraseUserScreenArea();
			displayCenteredTextLine(1, "Blue Green");
			displayCenteredTextLine(3, "bytecode [x09]");
			conveyorRight(60);
			delay(750);
			conveyorOff();
		}
		if(z == "\x10"){
			setTouchLEDColor(feedbackLED, colorBlue);
			eraseUserScreenArea();
			displayCenteredTextLine(1, "Blue");
			displayCenteredTextLine(2, "bytecode [x10]");
		}
		if(z == "\x11"){
			setTouchLEDColor(feedbackLED, colorDarkBlue);
			eraseUserScreenArea();
			displayCenteredTextLine(1, "Dark Blue");
			displayCenteredTextLine(2, "bytecode [x11]");
		}
		if(z == "\x12"){
			setTouchLEDColor(feedbackLED, colorViolet);
			eraseUserScreenArea();
			displayCenteredTextLine(1, "Violet");
			displayCenteredTextLine(2, "bytecode [x12]");
		}
	}
}
