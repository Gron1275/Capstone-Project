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
