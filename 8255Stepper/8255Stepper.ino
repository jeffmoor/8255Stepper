/*
 Name:		_8255Stepper.ino
 Created:	8/27/2018 3:06:25 PM
 Author:	Jeff
*/

static int iDirection;

#define	PIN_DIRECTION	2		// PIN2 is connected to DIR on DRV8825
#define	PIN_STEP		3		// PIN3 is connected to STEP on DRV8825
#define	PIN_LED			13

#define	PASOS		2000		// Intend 200 steps to make a 360 degrees turn


void setup() {
	pinMode(PIN_DIRECTION, OUTPUT);
	pinMode(PIN_STEP, OUTPUT);

	iDirection = LOW;

	digitalWrite(PIN_DIRECTION, iDirection);
}


void loop() {
	
	// Flash the LED
	digitalWrite(PIN_LED, HIGH);
	delay(500);
	digitalWrite(PIN_LED, LOW);
	
	for (int i = 0; i<PASOS; i++)
	{
		digitalWrite(PIN_STEP, HIGH);
		delayMicroseconds(4);
		digitalWrite(PIN_STEP, LOW);
		delayMicroseconds(1000);
	}

	digitalWrite(PIN_DIRECTION, iDirection ^= 0x1);
	
	// delay(5000);
}