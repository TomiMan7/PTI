#include <stdio.h>

#define FL_BUFFER_MERET 1024

char fl_buffer[FL_BUFFER_MERET];

// a veremmutato
int sp = -1;

// verembe be
void
push(char c)
{
    fl_buffer[++sp] = c;
}

// verembol ki
char
pop()
{
    return fl_buffer[sp--];
}

void
kiir(char op)
{
    if (op >= '0' && op <= '9') {
        printf("%c", op);
        return;
    } else if (op == 'x') {
        printf("%c", 'x');
        return;
    } else if (op == '+' || op == '*' || op == 'p') {
        char op1 = pop();
        char op2 = pop();
        kiir(op2);
        kiir(op1);
        printf("%c", op);
        return;
    } else if (op == 's' || op == 'e') {
        char op1 = pop();
        kiir(op1);
        printf("%c", op);
        return;
    }
}

// derival (rekurziv)
void
d(char op)
{
// A derivalas szabalyai
    // ha szamot kell
    if (op >= '0' && op <= '9') {
        // konstans derivaltja nulla
        printf("%c", '0');
        return;
    } else if (op == 'x') {
        // az x derivaltja 1
        printf("%c", '1');
        return;
    } else if (op == '+') {
        // osszeg derivaltja a tagok derivaltjanak osszege
        char op1 = pop();
        d(op1);
        char op2 = pop();
        d(op2);
        printf("%c", '+');
        return;
    } else if (op == '*') {
        // pg szorzat derivaltja pg'+p'g
        char op1 = pop();
        int mentsp = sp;
        kiir(op1);
        char op2 = pop();
        int mentsp2 = sp;
        d(op2);
        printf("%c", '*');
        sp = mentsp;
        d(op1);
        sp = mentsp2;
        kiir(op2);
        printf("%c", '*');
        printf("%c", '+');
        return;
    } else if (op == 's' || op == 'e') {
        // osszetett /egy operandusu/ fgv. derivaltja: a kulso fgv.
        // deriváltja * a belsoe / meg a sima fuggvenyeket
        // is ezzel oldom meg, pl.: sin(x)' = cos(x)*x' = cos(x) /
        char op1 = pop();
        int mentsp = sp;
        kiir(op1);
        switch (op) {
        case 's':
            printf("%c", 'c');
            break;
        case 'e':
            printf("%c", 'e');
            break;
        }
        sp = mentsp;
        d(op1);
        printf("%c", '*');
        return;
    } else if (op == 'p') {
        // osszetett /ket operandusu/ fgv. derivaltja: a kulso fgv.
        // deriváltja * a belsoe / meg a sima fuggvenyeket
        // is ezzel oldom meg, pl.: pow(x,2)' = 2*pow(x,1)*x' = 2*pow(x,1) /
        char op1 = pop();	// kitevo
        int mentsp = sp;
        kiir(op1);
        char op2 = pop();
        int mentsp2 = sp;
        kiir(op2);
        sp = mentsp;
        kiir(op1);
        printf("%c", '1');
        printf("%c", '-');
        printf("%c", 'p');
        printf("%c", '*');
        // szor a belso fgv. derivaltja
        sp = mentsp2;
        d(op2);
        printf("%c", '*');
        return;
    }
}

void
derival(char *mit)
{
    int c;
    sp = -1;

    while (c = *mit++)
        switch (c) {
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
        case 'x':
        case '+':
        case '*':
        case 's':
        case 'e':
        case 'p':
            push(c);
            break;
        default:
            printf("%c-t nem ismeri ez az implementacio...", c);
            break;
        }

    d(pop());
}

int
main(int argc, char *argv[])
{
    while (--argc)
        derival(*++argv);

    return 0;
}
