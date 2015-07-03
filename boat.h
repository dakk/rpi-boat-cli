#ifndef BOAT_H
#define BOAT_H

#include <wiringPi.h>

#define MOTOR_GPIO_RIGHT	17
#define MOTOR_GPIO_LEFT		22

void motor_disable (unsigned motor);
void motor_enable (unsigned motor);

void boat_init ();
void boat_turnleft ();
void boat_turnright ();
void boat_stop ();
void boat_gocenter ();

#endif
