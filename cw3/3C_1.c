#define _XOPEN_SOURCE 500
#define _POSIX_C_SOURCE 200112L

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

int main (int argc, char *argv[]) 
{

    int ChildPID = 0;
    int ChildGroupPID = 0;

    // printf("argc = %d \n", argc); debugger
    if (argc < 5) { printf("Błąd: Zbyt mała ilość argumentów\n"); exit(EXIT_FAILURE); } 
    if (argc > 5) { printf("Błąd: Zbyt duża ilość argumentów\n"); exit(EXIT_FAILURE); }

    printf("PID procesu: %d\n", getpid());

    switch (ChildPID = fork ()) {
        case -1:
            perror("fork error");
            exit(EXIT_FAILURE);
        case 0:
            // akcja dla procesu potomnego 

            // przełączanie na 3C_2
            if (execl(argv[3], argv[3], argv[1], argv[2], argv[4], NULL) == -1) { perror("execl error"); exit(EXIT_FAILURE); }

            break;

        default:
            // akcja dla procesu macierzystego

            sleep(1);

            ChildGroupPID = getpgid (ChildPID);

            // printf("%d != %d\n", ChildGroupPID, getpgid(0));

            if (kill (-1 * ChildGroupPID, 0) == -1) { perror("child not found"); exit(EXIT_FAILURE); }

            if (kill (-1 * ChildGroupPID, atoi(argv[1]))) { perror ("kill error"); exit(EXIT_FAILURE); }
    };

    sleep(1);

    if (strcmp(argv[2], "ignore") == 0) 
    {
        printf ("Program zakończył się a nadal istnieją procesy zombie\n");
        printf ("Wysyłanie sygnału SIGKILL do grupy procesów zombie\n");
        kill (-1 * ChildGroupPID, SIGKILL);
    }
}