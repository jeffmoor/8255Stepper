/*
 Name:		_8255Stepper.ino
 Created:	8/27/2018 3:06:25 PM
 Author:	Jeff
*/

int steps = 2; //PIN3 is connected to STEP on DRV8825
int direccion = 3; //PIN4 is connected to DIR on DRV8825
int pasos = 200; //200 steps to make a 360 degrees turn

void setup() {
	pinMode(direccion, OUTPUT);
	pinMode(steps, OUTPUT);
}

void loop() {
	
	digitalWrite(13, HIGH);
	delay(1000);
	digitalWrite(13, LOW);
	delay(1000);

	digitalWrite(direccion, LOW);

	for (int i = 0; i<pasos; i++)
	{
		digitalWrite(steps, HIGH);
		delayMicroseconds(10);
		digitalWrite(steps, LOW);
		delayMicroseconds(500);
	}
	delay(5000);
}