
#include <string.h>
#include <signal.h>
#include <sys/ioctl.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "term.h"
/*ANSI/VT100 Terminal using example */
#define home() 			printf(ESC "[H") //Move cursor to the indicated row, column (origin at 1,1)
#define clrscr()		printf(ESC "[2J") //lear the screen, move to (1,1)
#define gotoxy(x,y)		printf(ESC "[%d;%dH", y, x);
#define visible_cursor() printf(ESC "[?251");
/* Set Display Attribute Mode	<ESC>[{attr1};...;{attrn}m */
#define resetcolor() printf(ESC "[0m")
#define set_display_atrib(color) 	printf(ESC "[%dm",color)


void npaint() {
	char buffer[22];
        strncpy( buffer, "Hello World" , 22 );
	set_display_atrib(B_BLUE);
	while (1) 
        {
		gotoxy(5,3);
	        puts(buffer);
		fflush(stdout);
		sleep(100000);
	}
}



int main (void) 
{
	home();
	clrscr();
	npaint();
	return 0;
}



