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
    printf("| %d|", UID);
    printf(" %d|", GID);
    printf(" %d|", PID);
    printf(" %d|", PPID);
    printf(" %d|\n", PGID);
    printf("===============================\n");
    
    return 0;
}