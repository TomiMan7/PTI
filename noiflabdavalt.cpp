#include <stdlib.h>
#include <curses.h>
#include <unistd.h>
#include <sys/ioctl.h>
//#include <stdio.h>

//#define SZEL 90
//#define MAG 30

void falrajz(int szel, int mag)
{
 for(int i = 0; i < szel-1; i++)
  {
	mvprintw(0,i,"---");
	mvprintw(mag,i, "---");
  }
 for(int i = 0; i < mag; i++)
  {
	mvprintw(i,0,"|");
	mvprintw(i,szel,"|");
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
    struct winsize size;
    //ioctl(STDOUT_FILENO, TIOCGWINSZ, &size);

    int xj = 0, xk = 0, yj = 0, yk = 0;
    int mx = size.ws_col * 2, my = size.ws_row * 2; 

    WINDOW *ablak;
    ablak = initscr ();

    noecho ();
    cbreak (); 

    nodelay (ablak, true);

 while(true)
  {    
	clear ();
    	ioctl(STDOUT_FILENO, TIOCGWINSZ, &size);
	mx = size.ws_col * 2;
	my = size.ws_row * 2;
	
	int szel = size.ws_col, mag = size.ws_row;

	falrajz(szel, mag);
	pattogas(xj,xk,yj,yk,mx,my);
	
        refresh ();
        usleep (100000);
 }
return 0;
}
