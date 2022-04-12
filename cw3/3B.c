#define _XOPEN_SOURCE 500
#define _POSIX_C_SOURCE 200112L

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <signal.h>

int main (int argc, char *argv[]) 
{
    int ChildPID = 0;
    
    // printf("argc = %d \n", argc); debugger
    if (argc < 4) { printf("Błąd: Zbyt mała ilość argumentów\n"); exit(EXIT_FAILURE); }
    if (argc > 4) { printf("Błąd: Zbyt duża ilość argumentów\n"); exit(EXIT_FAILURE); }

    printf("PID procesu: %d\n", getpid());

    switch (ChildPID = fork ()) 
    {
        case -1:
            perror("fork error");
            exit(EXIT_FAILURE);
        case 0:
            // akcja dla procesu potomnego

            // przełączanie na 3A
            if (execl(argv[3], argv[3], argv[1], argv[2], NULL) == -1) { perror("execl error"); exit(EXIT_FAILURE); }
            break;

        default:
            // akcja dla procesu macierzystego

            sleep(1);

            if (kill(ChildPID, 0) == -1) { perror("child not found"); exit(EXIT_FAILURE); }

            if (kill(ChildPID, atoi(argv[1])) == -1) { perror ("kill error"); exit(EXIT_FAILURE); }
    }

    if (strcmp(argv[2], "ignore") == 0) 
    {
        sleep (1);

        printf ("Mimo zakończenia programu istnieją procesy zombie \n");
        printf ("Wysyłanie sygnału SIGKILL do procesu zombie \n");
        kill (ChildPID, SIGKILL);
        printf("Wysłano sygnał SIGKILL do procesu zombie \n");
    }

}