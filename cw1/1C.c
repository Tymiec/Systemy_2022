#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
 

int main() 
{
    int i;
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
                UID = getuid();
                GID = getgid();
                PID = getpid();
                PPID = getppid();
                PGID = getpgid(PID);
                
                sleep(10);
                printf("| %d|", i);
                printf("| %d|", UID);
                printf(" %d|", GID);
                printf(" %d|", PID);
                printf(" %d|", PPID);
                printf(" %d|\n", PGID);
                break;
            default:
                break;
        }
    }
    return 0;
}