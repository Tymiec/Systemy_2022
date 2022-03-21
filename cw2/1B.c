#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) /* przekazanie argumentów */
{

    if (argc != 2) /* kontrola błędu */
    {
        printf("Nie podano argumentów");
        exit(1);
    }

    int UID = getuid();
    int GID = getgid();
    int PID = getpid();
    int PPID = getppid();
    int PGID = getpgid(PID);

    printf("\nIdentyfikatory procesu macierzystego:\n");
    printf("|  UID|  GID|  PID| PPID| PGID|\n");
    printf("| %d|", UID);
    printf(" %d|", GID);
    printf(" %d|", PID);
    printf(" %d|", PPID);
    printf(" %d|\n", PGID);
    printf("=====================================\n");
    printf("\nIdentyfikatory procesów potomnych:\n");
    printf("=====================================\n");

    for (int i = 1; i < 4; i++)
    {
        switch(fork())
        {            
            case -1:
                perror("Fork error detected");
                exit(1);
            case 0:
                execl(argv[1], argv[1], NULL); /* wywołujemy program wypisywanie */
                perror("Execl error detected"); /* kontrola błędu*/
               _exit(2); 
                break;
            default:
                wait(NULL);
                break;
        }
    }
    return 0;
}