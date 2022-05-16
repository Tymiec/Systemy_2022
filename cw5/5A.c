#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

// Zmienna w której będziemy przechowywać nazwę potoku ponieważ do funkcji rmfifo nie można przekazać argumentu
char namefifo[10];

// Funkcja usuwająca potok
void rmfifo(void)
{
    unlink(namefifo);
}

int main (int argc, char * argv[]) 
{
    // Czyścimy zmienną w której będziemy przechowywać nazwę potoku
    memset(namefifo, 0, 10);
    // Kopiujemy nazwę potoku do zmiennej
    strncat(namefifo, argv[3],strlen(argv[3]));
    // Tworzymy potok z kontrolą błędów
    int fifo = mkfifo(argv[3], 0644);
    if (fifo == -1)
    {
        perror("Nie udało się utworzyć potoku");
        exit(1);
    }
    // Dodajemy regułę żeby przy zamykaniu programu usuwać potok
    atexit(rmfifo);
    // Tworzymy zmienne w których będziemy przechowywać ścieżki potrzebne funkcji execl
    char path1[30] = "./";
    char path2[30] = "./";
    char end[30] = ".x";
    // Łączymy scieżki z nazwami plików
    strncat(path1, argv[1], 20);
    strncat(path2, argv[2], 20);
    // Dodajemy rozszerzenia
    strncat(path1, end, 5);
    strncat(path2, end, 5);
    strncat(argv[1], end, 20);
    strncat(argv[2], end, 20);

    // Tworzymy proces potomny w którym uruchomimy program Producenta
    switch(fork())
    {
        case -1:
        perror("Fork error!");
        exit(2);
            
        case 0:
        execl(path1,argv[1],argv[3], argv[4]);
        perror("execl error");
        exit(2);

    }
    // Tworzymy proces potomny w którym uruchomimy program Konsumenta
    switch(fork())
    {
        case -1:
        perror("Fork error!");
        exit(2);
            
        case 0:
        execl(path2,argv[2],argv[3], argv[5]);
        perror("execl error");
        exit(2);

    }
    // Oczekiwanie na zakończenie obydwu procesów potomnych
    wait(NULL);
    wait(NULL);
    return 0;
}
