#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

// Definiujemy rozmiar buffora a więc po ile bajtów będziemy pobierać
#define buffinSize 5

int main(int argc, char * argv[])
{
    // Sprawdzamy czy podano 2 argumenty przy wywołaniu programu
    if (argc != 3)
    {
        printf("Uruchomiono program z nieprawidłową ilością argumentów\n");
        exit(-1);
    }
    // Otwieramy potok z obsługą błędów
    int fifo = open(argv[1], O_WRONLY, 0644);
    if (fifo == -1)
    {
        perror("Nie można otworzyć potoku");
        exit(2);
    }
    // Otwieramy plik z którego będziemy czytać z obsługą błędów
    int rfile = open(argv[2], O_RDONLY, 0644);
    if (rfile == -1)
    {
        perror("Nie można otworzyć pliku do czytania");
        exit(2);
    }
    // Tworzymy buffor na dane
    char buffin[buffinSize+1];
    // Tworzymy zmienną w której będziemy przechowywać ilość pobranych danych
    int sizein;
    // Tworzymy zmienną do której będziemy konwertować ilość pobranych danych z int do char
    char bytes[10];
    // Tworzymy zmienną pomocniczą (będziemy łączyć różne stringi) żeby wypisywać wszystko za jednym razem
    char output[90];
    // Czyścimy zmienną pomocniczą
    memset(output,0,90);
    // Pętla czytająca, która zakończy się dopiero gdy funkcja read natrafi na znak EOF
    while((sizein = read(rfile, buffin, buffinSize)) > 0)
        {
            // Zamieniamy ilosć pobranych bajtów na char
            sprintf(bytes, "%i", sizein);
            // Tworzymy output który będziemy wypisywać
            strncat(output,"\nWczytano z pliku: ",20);
            strncat(output, buffin, sizein);
            strncat(output,", czyli: ",10);
            strncat(output,bytes,2);
            strncat(output,"bajtów",8 );
            // Wypisujemy output
            write(2, output, strlen(output));
            // Wpisujemy wartość z buffora do potoku
            write(fifo, buffin, sizein);
            // Czyścimy buffor oraz zmienną output
            memset(buffin, 0, sizein);
            memset(output,0,strlen(output));
        }
    // Zwalniamy deskryptor pliku do czytania
    close(rfile);
    // Zwalniamy deskryptor potoku
    close(fifo);
    // Wypisujemy koniec lini dla estetyki
    printf("\n");
    return 0;
}