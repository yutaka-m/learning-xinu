#include <xinu.h>

shellcmd xsh_ex1(int nargs, char *args[])
{
    putc(CONSOLE, 'h');
    putc(CONSOLE, 'i');
    putc(CONSOLE, '\n');
}