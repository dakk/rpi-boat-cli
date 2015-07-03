#include <wiringPi.h>

#include "boat.h"

void motor_init ()
{
	wiringPiSetup ();
	wiringPiSetupGpio ();

	pinMode (MOTOR_GPIO_LEFT, OUTPUT) ;
	pinMode (MOTOR_GPIO_RIGHT, OUTPUT) ;
	motor_disable (MOTOR_GPIO_LEFT);
	motor_disable (MOTOR_GPIO_RIGHT);
}

void motor_enable (unsigned motor)
{
	digitalWrite (motor, 0) ;
}


void motor_disable (unsigned motor)
{
	digitalWrite (motor, 1) ;
}


void boat_turnleft ()
{
	motor_enable (MOTOR_GPIO_LEFT);
}

void boat_gocenter ()
{
	motor_enable (MOTOR_GPIO_RIGHT);
	motor_enable (MOTOR_GPIO_LEFT);
}

void boat_turnright ()
{
	motor_enable (MOTOR_GPIO_RIGHT);
}

void boat_stop ()
{
	motor_disable (MOTOR_GPIO_RIGHT);
	motor_disable (MOTOR_GPIO_LEFT);
}

void boat_init ()
{
	motor_init ();
}
