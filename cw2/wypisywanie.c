#include <stdio.h>
#include <unistd.h>

int main () 
{
    //program z 1B
    int UID = getuid();
    int GID = getgid();
    int PID = getpid();
    int PPID = getppid();
    int PGID = getpgid(PID);

    printf("\nIdentyfikatory procesu potomnego\n");
    printf("|ID|  UID|  GID|   PID|  PPID|  PGID|\n");
    printf("| 0");
    printf("| %d|", UID);
    printf(" %d|", GID);
    printf(" %d|", PID);
    printf(" %d|", PPID);
    printf(" %d|\n", PGID);
    printf("=====================================\n");
}