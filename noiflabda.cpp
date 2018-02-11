#include <stdlib.h>
#include <curses.h>
#include <unistd.h>

#define SZEL 90
#define MAG 30

void falrajz()
{
 for(int i = 0; i < SZEL-1; i++)
  {
	mvprintw(0,i,"---");
	mvprintw(MAG,i, "---");
  }
 for(int i = 0; i < MAG; i++)
  {
	mvprintw(i,0,"|");
	mvprintw(i,SZEL,"|");
  }
}


void pattogas(int& xj,int& xk, int& yj, int& yk, int& mx, int& my)
{
        xj = (xj - 1) % mx;
        xk = (xk + 1) % mx;

        yj = (yj - 1) % my;
        yk = (yk + 1) % my;

        mvprintw (abs ((yj + (my - yk)) / 2), abs ((xj + (mx - xk)) / 2), "@");
}


int main()
{
    int xj = 0, xk = 0, yj = 0, yk = 0;
    int mx = SZEL * 2, my = MAG * 2;

    WINDOW *ablak;
    ablak = initscr ();

    noecho ();
    cbreak (); 

    nodelay (ablak, true);

 while(true)
  {
	clear ();

	falrajz();
	
	pattogas(xj,xk,yj,yk,mx,my);
	
        refresh ();

        usleep (100000);
 }
return 0;
}
