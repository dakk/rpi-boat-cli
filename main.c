#include <stdio.h>
#include <curses.h>
#include "boat.h"

int main ()
{
	char ch = 's';
	boat_init ();
	boat_stop ();

	while (ch = getch ())
	{
		printf ("%c\n", ch);
		if (ch == 'a')
			boat_turnleft ();
		else if (ch == 'd')
			boat_turnright ();
		else if (ch == 'q')
			return 0;
		else if (ch == 's')
			boat_stop ();
		else if (ch == 'w')
			boat_gocenter ();
	}

	return 0;
}
