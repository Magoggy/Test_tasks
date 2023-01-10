#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <unistd.h>

void Knight_Rider()
{
    initscr();
	start_color();

	init_pair(1, COLOR_WHITE, COLOR_BLACK);
	init_pair(2, COLOR_RED, COLOR_BLACK);
	for (int i = 1; i < 7; i++)
	{

	    mvchgat(i, 2, 4, A_NORMAL, 2, NULL);
	    sleep(1+i/3);
	    refresh();
	    mvchgat(i, 2, 4, A_NORMAL, 1, NULL);
	}
	for (int i = 5; i >= 1; i--)
	{
	    mvchgat(i, 2, 4, A_NORMAL, 2, NULL);
	    sleep(1+i/3);
	    refresh();
	    mvchgat(i, 2, 4, A_NORMAL, 1, NULL);
	}
	sleep(1);
	refresh();

    getch();
	endwin();
}

int main()
{
    initscr();
	start_color();
	printw("The diods:\n");
    for (int i = 0; i < 6; i++)
    {
        printw("<<Diod>>\n");    //Printing 6 diods
    }
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
	mvchgat(0, 0, -1, A_NORMAL, 1, NULL);
    refresh();

    Knight_Rider();
    getch();
	endwin();
	return 0;
}
