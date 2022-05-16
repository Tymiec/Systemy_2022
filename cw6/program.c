#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <semaphore.h>
#include <fcntl.h>
#include <time.h>
#include "sem.h"

// Tworzymy zmienną przechowującą nazwę semafora
const char name[15] = "/aaa";

int main (int argc, char * argv[])
{
    // Sprawdzamy czy został podany jeden argument przy uruchamianiu programu.
    if (argc != 2)
    {
        printf("Uruchomiono program z nieprawidłową ilością argumentów\n");
        exit(-1);
    }

    // Otwieramy semafor
    sem_t *sem = semopen(name, 0644);

    // Pobieramy pid procesu
    pid_t pid = getpid();

    // Inicjujemy zmienną do której będziemy pobierać wartość semafora
    int value;

    // Inicjujemy zmienną w której będziemy przechowywać deskryptor pliku tekstowego
    int desc;

    // Inicjujemy buffor w którym będziemy przechowywać liczbę pobraną z pliku tekstowego
    char buff[2];

    // Inicjujemy pomocniczą zmienną do zrzutowania bufforu ze znaku na liczbę
    int buffer;

    // Rzutujemy argument na zmienną int (ilość sekcji krytycznych)
    int n = atoi(argv[1]);

    // Inicjujemy zmienną do której będziemy "losować" czas opóznienia
    int time;
    for(int i = 0; i < n; i++)
    {
        // Pobieramy początkową wartość semafora
        semgetvalue(sem, &value);
        // Wypisujemy pid i wartość początkową
        printf("Proces: %i, Wartość semafora przed sekcją krytyczną %i\n", pid, value);
        // Losujemy "opóźnienie"
        time = rand()%10+1;
        // "Opóźniamy"
        sleep(time/4);

        // Zajmujemy semafor
        semwait(sem);
        // Pobieramy wartość w sekcji krytycznej
        semgetvalue(sem, &value);
        // Wypisujemy pid oraz wartość w sekcji krytycznej
        printf("    Proces: %i, Wartość semafora w trakcie sekcji krytycznej: %i, sekcja nr. %i\n", pid, value, i+1);
        // Otwieramy plik tekstowy
        desc = open("./numer.txt", O_RDONLY, 0644);
        // Odczytujemy z niego wartość
        read(desc, buff, 2);
        // Wypisujemy pobraną wartość
        printf("    Proces: %i, odczytał z pliku: %s\n", pid, buff);
        // Zwalniamy deskryptor pliku
        close(desc);

        // Rzutujemy znak na liczbę całkowitą
        buffer = atoi(buff);
        // Zwiększamy liczbę o 1
        buffer++;
        // Zmieniamy liczbę na znak
        *buff = buffer + '0';
        // Losujemy opóźnienie
        time = rand()%10+1;
        // "Opózniamy"
        sleep(time/6);

        // Otwieramy plik tekstowy
        desc = open("./numer.txt", O_WRONLY, 0644);
        // Zapisujemy znak do pliku
        write(desc, buff, 2);
        // Wypisujemy co zapisaliśmy
        printf("    Proces: %i, zapisał do pliku: %s\n", pid, buff);
        // Zwalniamy deskryptor
        close(desc);

        // Opuszczamy semafor
        sempost(sem);
        // Pobieramy wartosć po sekcji krytycznej
        semgetvalue(sem, &value);
        // Wypisujemy pid i wartość semafora po sekcji krytycznej
        printf("Proces: %i, Wartość semafora po sekcji krytycznej: %i\n\n", pid, value);
    }
    // Zamykamy semafor
    semclose(sem);
    
    return 0;
}