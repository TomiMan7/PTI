#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include <unistd.h>
#include <sys/ioctl.h>
int
main (void)
{
    int xj = 0, xk = 0, yj = 0, yk = 0;
    int mx = 80 * 2, my = 24 * 2;
    struct winsize size;

    WINDOW *ablak;
    ablak = initscr ();
    noecho ();
    cbreak ();
    nodelay (ablak, true);

    for (;;)
    {	
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &size);
	int mx = size.ws_col*2, my = size.ws_row*2;
        xj = (xj - 1) % mx;
        xk = (xk + 1) % mx;

        yj = (yj - 1) % my;
        yk = (yk + 1) % my;

        clear ();

        /*mvprintw (0, 0,
                  "--------------------------------------------------------------------------------");
        mvprintw (24, 0,
                  "--------------------------------------------------------------------------------");*/


 for(int i = 0; i < size.ws_col-1; i++)
  {
	mvprintw(0,i,"---");
	mvprintw(size.ws_row,i, "---");
  }
 for(int i = 0; i < size.ws_row; i++)
  {
	mvprintw(i,0,"|");
	mvprintw(i,size.ws_col,"|");
  }


        mvprintw (abs ((yj + (my - yk)) / 2),
                  abs ((xj + (mx - xk)) / 2), "X");

        refresh ();
        usleep (100000);

    }
    return 0;
}
