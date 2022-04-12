#define _XOPEN_SOURCE 500
#define _POSIX_C_SOURCE 200112L

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/wait.h>

int main (int argc, char *argv[]) 
{

    // printf("argc = %d \n", argc); debugger
    if (argc < 4) { printf("Błąd: Zbyt mała ilość argumentów\n"); exit(EXIT_FAILURE); }
    if (argc > 4) { printf("Błąd: Zbyt duża ilość argumentów\n"); exit(EXIT_FAILURE); }

    int stat_lock = 0;

    setpgid (0,0); //ustawiamy lidera
    printf("PID podprocesu: %d\n", getpgrp());

    for (int i = 0; i < 3; i++) 
    {
        switch (fork ()) 
        {
            case -1:
                perror("fork error");
                exit(EXIT_FAILURE);
            case 0:
                // akcja dla procesu dziecka procesu dziecka (wnuka) 

                // przełączanie na 3A
                if (execl(argv[3], argv[3], argv[1], argv[2], NULL) == -1) { perror("execl error"); exit(EXIT_FAILURE); }
                perror("execl error");
                exit(EXIT_FAILURE);

                break;

            default:
                // akcja dla procesu dziecka

                break;
        };
    }

    if (signal(atoi(argv[1]),SIG_IGN) == SIG_ERR) { perror("Funkcja signal ma problem z SIGINT"); exit(EXIT_FAILURE); }

    int ProcessPID;

    for (int i = 0; i < 3; i++) 
    {
        if ((ProcessPID = wait(&stat_lock)) == -1) { perror ("wait error"); exit(EXIT_FAILURE); }
        printf("Status zakończenia procesu o PID: %d to: %d\n", ProcessPID, stat_lock);
    }
}