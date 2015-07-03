#include <wiringPi.h>
#include <wpiExtensions.h>
#include <gertboard.h>
#include <piFace.h>

#include "boat.h"

int wpMode = WPI_MODE_GPIO;

void motor_init ()
{
	wiringPiSetup ();
	wiringPiSetupGpio ();

	pinMode (MOTOR_GPIO_LEFT, OUTPUT);
	pinMode (MOTOR_GPIO_RIGHT, OUTPUT);

	motor_disable (MOTOR_GPIO_LEFT);
	motor_disable (MOTOR_GPIO_RIGHT);
}

void motor_enable (unsigned motor)
{
	digitalWrite (motor, LOW);
}


void motor_disable (unsigned motor)
{
	digitalWrite (motor, HIGH);
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
