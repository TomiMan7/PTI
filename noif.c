#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include <unistd.h>

int
main (void)
{
    int xj = 0, xk = 0, yj = 0, yk = 0;
    int mx = 90 * 2, my = 30 * 2;//mx terminal x tengely szelesseg my terminal y tengely magassag

    WINDOW *ablak;
    ablak = initscr ();//ablak inicializalas
    noecho ();
    cbreak (); //enter nelkuli bill.re reagalas
    nodelay (ablak, true);

    while(1)
    {
        xj = (xj - 1) % mx;
        xk = (xk + 1) % mx;

        yj = (yj - 1) % my;
        yk = (yk + 1) % my;

        clear (); //letorlni a terminalt igy csak egy X marad a kepernyon

        mvprintw (0, 0,
                  "------------------------------------------------------------------------------------------"); //0sor 0oszlopban irja ki
        mvprintw (29, 0,
                  "-------------------------------------------------------------------------------------------------"); //29sor 0 oszlopban irja ki
        mvprintw (abs ((yj + (my - yk)) / 2),
                  abs ((xj + (mx - xk)) / 2), "X");

        refresh (); //ujra rajozolja az ablakot
        usleep (150000); //altatja a for ciklust is szemmel jobban kovetheto a mozgas

    }
    return 0;
}
