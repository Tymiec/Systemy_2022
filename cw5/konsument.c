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
#define buffoutSize 4

int main(int argc, char * argv[])
{
    // Sprawdzamy czy podano 2 argumenty przy wywołaniu programu
    if (argc != 3)
    {
        printf("Uruchomiono program z nieprawidłową ilością argumentów\n");
        exit(-1);
    }
    // Otwieramy potok z obsługą błędów
    int fifo = open(argv[1], O_RDONLY, 0644);
    if (fifo == -1)
    {
        perror("Nie można otworzyć potoku");
        exit(2);
    }
    // Otwieramy plik do którego będziemy zapisywać z obsługą błędów
    int wfile = open(argv[2], O_WRONLY, 0644);
    if (wfile == -1)
    {
        perror("Nie można otworzyć pliku do pisania");
        exit(2);
    }

    // Tworzymy buffor na dane
    char buffout[buffoutSize+1];
    // Tworzymy zmienną w której będziemy przechowywać ilość pobranych danych
    int sizeout;
    // Tworzymy zmienną do której będziemy konwertować ilość pobranych danych z int do char
    char bytes[10];
    // Tworzymy zmienną pomocniczą (będziemy łączyć różne stringi) żeby wypisywać wszystko za jednym razem
    char output[90];
    // Czyścimy zmienną pomocniczą
    memset(output,0,90);
    
    // Pętla czytająca, która zakończy się dopiero gdy proces producenta zwolni deskryptor do potoku
    while((sizeout = read(fifo, buffout, buffoutSize)) > 0)
        {
            // Zamieniamy ilosć pobranych bajtów na char
            sprintf(bytes, "%i", sizeout);
            // Tworzymy output który będziemy wypisywać
            strncat(output,"\nZapisano do pliku: ",21);
            strncat(output, buffout, sizeout);
            strncat(output,", czyli: ",10);
            strncat(output,bytes,2);
            strncat(output,"bajtów",8 );
            // Wypisujemy output
            write(2, output, strlen(output));
            // Wpisujemy wartość z buffora do potoku
            write(wfile, buffout, sizeout);
            // Czyścimy buffor oraz zmienną output
            memset(buffout, 0, sizeout);
            memset(output,0,strlen(output));
        }
    // Zwalniamy deskryptor pliku do pisania
    close(wfile);
    // Zwalniamy deskryptor potoku
    close(fifo);
    // Wypisujemy koniec lini dla estetyki
    printf("\n");
    return 0;
}