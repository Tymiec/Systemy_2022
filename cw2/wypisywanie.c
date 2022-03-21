#include <stdio.h>
#include <unistd.h>

int main () 
{
    /* program z 1B */
    int UID = getuid();
    int GID = getgid();
    int PID = getpid();
    int PPID = getppid();
    int PGID = getpgid(PID);

    printf("|  UID|  GID|  PID| PPID| PGID|\n");
    printf("| %d|", UID);
    printf(" %d|", GID);
    printf(" %d|", PID);
    printf(" %d|", PPID);
    printf(" %d|\n", PGID);
    printf("=====================================\n");
}