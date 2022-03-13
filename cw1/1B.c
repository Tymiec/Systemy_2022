#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
 

int main() 
{
    int UID = getuid();
    int GID = getgid();
    int PID = getpid();
    int PPID = getppid();
    int PGID = getpgid(PID);

    printf("\nIdentyfikatory procesu macierzystego:\n");
    printf("|ID|  UID|  GID|   PID|  PPID|  PGID|\n");
    printf("| 0");
    printf("| %d|", getuid());
    printf(" %d|", getgid());
    printf(" %d|", getpid());
    printf(" %d|", getppid());
    printf(" %d|\n", getpgid(PID));
    printf("=====================================\n");

    for (int i = 1; i < 4; i++)
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
                
                printf("| %d|", i);
                printf(" %d|", getuid());
                printf(" %d|", getgid());
                printf(" %d|", getpid());
                printf(" %d|", getppid());
                printf(" %d|\n", getpgid(PID));
                break;
            default:
                wait(NULL);
                break;
            
        }

    }
    
    
    return 0;
}