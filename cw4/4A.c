#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <errno.h>
#include <time.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
// Program implementuje problem producenta i konsumenta. Przy pomocy potoków nienazwanych.
// Przepisuje on tekst z jednego pliku do drugiego, przy okazji wypisując aktualnie wyczytane i wpisywane dane.



// Definiujemy rozmiary bufforów (po ile bitów będziemy czytać i zapisywać)
#define buffinSize 4
#define buffoutSize 4

int main(int argc, char * argv[])
{
    // Sprawdzamy czy podano 2 argumenty przy wywołaniu programu
    if (argc != 3)
    {
        printf("Uruchomiono program z nieprawidłową ilością argumentów\n");
        exit(-1);
    }
    // Inicjujemy tablice deskryptorów oraz sprawdzamy czy możemy utworzyć potok
    int desc[2];
    if (pipe(desc)==-1)
    {
        perror("Nie można utworzyć potoku");
        exit(1);
    }
    // Otwieramy plik do czytania z kontrolą błędów
    int rfile = open(argv[1], O_RDONLY, 0644);
    if (rfile == -1)
    {
        perror("Nie można otworzyć pliku do czytania");
        exit(2);
    }
    // Otwieramy plik do pisania z kontrolą błędów
    int wfile = open(argv[2], O_WRONLY, 0644);
    if (wfile == -1)
    {
        perror("Nie można otworzyć pliku do pisania");
        exit(3);
    }
    
    // Inicjujemy buffory na dane
    char buffout[buffoutSize+1];
    char buffin[buffinSize+1];

    // Inicjujemy zmienne które będą przechowywać ilość przeczytanych danych funkcją write
    int sizein;
    int sizeout;

    // Inicjujemy generator pseudolosowy
    srand(time(NULL));
    
    // Wywołujemy funkcje fork
    switch(fork())
    {
        // kontrola błędów
        case -1:
        perror("Fork error");
        exit(4);

        // Instrukcja dla procesu Potomnego
        case 0:
        // Zwalniamy nieużywany deskryptor
        close(desc[1]);
        // Inicjujemy zmienną do losowania czasu
        int time1;
        // Pętla która czyta dane z potoku i wrzuca je do bufforu, zatrzymuje się gdy druga strona potoku
        // zostanie zamknięta
        while((sizeout = read(desc[0], buffout, buffoutSize)) > 0)
        {
            write(2, "\nZapisano do pliku: ",20);
            // Wypisujemy co wyczytaliśmy z potoku
            write(2, buffout, sizeout);
            // Wypisujemy tą wartość do pliku do pisania
            write(wfile, buffout, sizeout);
            // Czyścimy buffor
            memset(buffout, 0, sizeout);
            // Losujemy długość opóźnienia
            time1 = rand()%10+1;
            // Usypiamy
            sleep(time1/4);
        }
        // Po zakończeniu zapisywania zwalniamy deskryptor
        close(desc[0]);
        break;

        // Instrukcja dla procesu macierzystego
        default:
        // Zamykamy nieużywamy deskryptor
        close(desc[0]);
        // Inicjujemy zmienną do losowania czasu
        int time2;
        // Pętla czytająca dane z pliku, zatrzymuje się gdy trafi na znak końca pliku
        while((sizein = read(rfile, buffin, buffinSize)) > 0)
        {
            write(2, "\nWczytano z pliku: ", 19);
            // Wypisujemy przeczytaną wartość
            write(2, buffin, sizein);
            // Wpisujemy wartość z buffora do potoku
            write(desc[1], buffin, sizein);
            // Czyścimy buffor
            memset(buffin, 0, sizein);
            // Losujemy długość opóźnienia
            time2 = rand()%10+1;
            // Usypiamy
            sleep(time2/4);
        }
        // Zwalniamy deskryptor co powoduje zakończenie pętli while w procesie potomnym
        close(desc[1]);
        // Oczekujemy na zakończenie procesu potomnego
        wait(NULL);
        // Wypisujemy znak końca lini dla estetyki
        printf("\n\n");
        break;

    }
    return 0;
}