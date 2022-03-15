#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
 

int main() 
{
    int i = 0;
    int generation = 0;

    int UID = getuid();
    int GID = getgid();
    int PID = getpid();
    int PPID = getppid();
    int PGID = getpgid(PID);

    printf("\nIdentyfikatory procesu macierzystego:\n");
    printf("|ID|  UID|  GID|   PID|  PPID|  PGID|\n");
    printf("| 0");
    printf("| %d|", UID);
    printf(" %d|", GID);
    printf(" %d|", PID);
    printf(" %d|", PPID);
    printf(" %d|\n", PGID);
    printf("=====================================\n");

    for (i = 1; i < 4; i++)
    {
        switch(fork())
        {            
            case -1:
                perror("Fork error detected");
                exit(1);
            case 0:
                generation++;

                UID = getuid();
                GID = getgid();
                PID = getpid();
                PPID = getppid();
                PGID = getpgid(PID);
                
                printf("| %d|", generation);    /* zaznaczamy generację */
                printf(" %d|", UID);
                printf(" %d|", GID);
                printf(" %d|", PID);
                printf(" %d|", PPID);
                printf(" %d|\n", PGID);
                sleep(1);
                break;
            default:
                break;
        }
    }
    sleep(4);
}