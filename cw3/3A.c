#define _XOPEN_SOURCE 500
#define _POSIX_C_SOURCE 200112L
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>

/*
    wykonywanie operacji:
    - domyślnej
    - ignorowania
    - przechwycenia
    - własna obsługa sygnału
*/

int main()
{
    void my_sighandler(int);
    {
        if (signal(SIGQUIT,SIG_IGN) == SIG_ERR)
        {
            perror("Funkcja signal ma problem z SIGQUIT");
            exit(EXIT_FAILURE);
        }
        if (signal(SIGINT,my_sighandler) == SIG_ERR)
        {
            perror("Funkcja signal ma problem z SIGINT");
            exit(EXIT_FAILURE);
        }
    }
}