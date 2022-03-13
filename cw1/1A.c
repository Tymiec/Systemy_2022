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

    printf("\nIdentyfikatory procesu:\n");
    printf("| UID | GID | PID | PPID| PGID|\n");
    printf("| %d|", getuid());
    printf(" %d|", getgid());
    printf(" %d|", getpid());
    printf(" %d|", getppid());
    printf(" %d|\n", getpgid(PID));
    printf("===============================\n");
    
    return 0;
}