/*
 Name:		_8255Stepper.ino
 Created:	8/27/2018 3:06:25 PM
 Author:	Jeff
*/

static int iDirection;

#define	PIN_DIRECTION	2		// PIN2 is connected to DIR on DRV8825
#define	PIN_STEP		3		// PIN3 is connected to STEP on DRV8825
#define	PIN_LED			13

#define	STEPS		40
#define	BOUNCES		5
#define	CYCLES		1



void setup() {
	pinMode(PIN_DIRECTION, OUTPUT);
	pinMode(PIN_STEP, OUTPUT);

	iDirection = LOW;
}


void loop() {

	// Flash the LED
	digitalWrite(PIN_LED, HIGH);
	delay(500);
	digitalWrite(PIN_LED, LOW);

	digitalWrite(PIN_DIRECTION, iDirection);

	for (int i = 0; i < CYCLES; i++)
	{
		for (int j = 0; j < BOUNCES; j++)
		{
			for (int k = 0; k < 2; k++)
			{
				for (int l = 0; l < (STEPS * (j + 1)); l++)
				{
					digitalWrite(PIN_STEP, HIGH);
					delayMicroseconds(4);
					digitalWrite(PIN_STEP, LOW);
					delayMicroseconds(1000);

					
				}
				
				digitalWrite(PIN_DIRECTION, iDirection ^= 0x1);
				delay(200);
			}
			
			delay(200);
		}
		delay(200);
	}

	
	// delay(5000);
}