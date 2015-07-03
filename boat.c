#include <wiringPi.h>
#include <wpiExtensions.h>
#include <gertboard.h>
#include <piFace.h>

#include "boat.h"

int wpMode = WPI_MODE_GPIO;

void motor_init ()
{
	wiringPiSetupGpio ();
	pinMode (MOTOR_GPIO_LEFT, OUTPUT);
	wiringPiSetupGpio ();
	pinMode (MOTOR_GPIO_RIGHT, OUTPUT);

	wiringPiSetupGpio ();
	motor_disable (MOTOR_GPIO_LEFT);
	wiringPiSetupGpio ();
	motor_disable (MOTOR_GPIO_RIGHT);
}

void motor_enable (unsigned motor)
{
	wiringPiSetupGpio ();
	digitalWrite (motor, HIGH);
}


void motor_disable (unsigned motor)
{
	wiringPiSetupGpio ();
	digitalWrite (motor, LOW);
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
