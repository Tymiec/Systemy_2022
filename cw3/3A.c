#define _POSIX_C_SOURCE 200112L
#define _XOPEN_SOURCE 500

#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>

void my_sighandler(int signal_1) 
{
    extern const char * const sys_siglist[];

    printf("Obsługa sygnału \n");
    printf("Obsługiwany sygnał: %s, %d\n", sys_siglist[signal_1], signal_1);
}

int main (int argc, char *argv[]) 
{
    // printf("argc = %d \n", argc); debugger
    if (argc < 3) { printf("Błąd: Zbyt mała ilość argumentów \n"); exit(EXIT_FAILURE); }
    if (argc > 3) { printf("Błąd: Zbyt duża ilość argumentów \n"); exit(EXIT_FAILURE); }

    printf("PID procesu: %d\n", getpid());

    if (strcmp(argv[2], "default") == 0) 
    {
        if (signal(atoi(argv[1]),SIG_DFL) == SIG_ERR) { perror("Funkcja signal ma problem z SIGINT"); exit(EXIT_FAILURE); }
    }

    else if (strcmp(argv[2], "ignore") == 0) 
    {
        if (signal(atoi(argv[1]),SIG_IGN) == SIG_ERR) { perror("Funkcja signal ma problem z SIGINT"); exit(EXIT_FAILURE); }
    } 
    
    else if (strcmp(argv[2], "custom") == 0) 
    {
        if (signal(atoi(argv[1]),my_sighandler) == SIG_ERR) { perror("Funkcja signal ma problem z SIGINT"); exit(EXIT_FAILURE); }
    } 
    
    else { printf("Błąd: Niepoprawna opcja %s\n", argv[2]); }

    pause();
}