#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include <unistd.h>

void falprint()
{

for(int i = 0; i < 89; i++)
  {
        mvprintw (0, i,"__");
        mvprintw (29, i,"__"); 
  }

for(int i = 1; i < 30; i++)
  {
        mvprintw (i, 0,"|");
        mvprintw (i, 90,"|");
  }
}

int main()
{
    int xj = 0, xk = 0, yj = 0, yk = 0;
    int mx = 89 * 2, my = 29 * 2;

    WINDOW *ablak;
    ablak = initscr ();

    noecho ();
    cbreak (); 
    nodelay (ablak, true);

for(;;)
  {
    
	xj = (xj - 1) % mx;
        xk = (xk + 1) % mx;

        yj = (yj - 1) % my;
        yk = (yk + 1) % my;

        clear ();
	falprint();

        mvprintw (abs ((yj + (my - yk)) / 2),
                  abs ((xj + (mx - xk)) / 2), "X");

        refresh ();
        usleep (100000);      
  }
}
