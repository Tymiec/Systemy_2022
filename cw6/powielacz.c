#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <semaphore.h>
#include <signal.h>
#include <fcntl.h>
#include <string.h>
#include <wait.h>
#include "sem.h"

// Tworzymy zmienną przechowującą nazwę semafora
const char name[15] = "/aaa";

// Tworzymy funkcję usuwającą semafor
void semdelete(void)
{
    semremove(name);
}

// Funkcja usuwająca semafor po otrzymaniu sygnału
void handler(int signum)
{
    semremove(name);
    _exit(EXIT_FAILURE);
}

int main(int argc, char * argv[])
{
    // Sprawdzamy czy zostały podanr trzy argumenty przy uruchamianiu programu.
    if (argc != 4)
    {
        printf("Uruchomiono program z nieprawidłową ilością argumentów\n");
        exit(-1);
    }

    // Tworzymy plik tekstowy, a jeżeli on istnieje przycinamy go 
    int desc = open("./numer.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if(desc == -1)
    {
        perror("numer.txt error!");
        exit(3);
    }
    // Inicjujemy buffer z wartością 0
    char buff[2] = "0";
    // Wpisujemy do pliku wartość z buffora
    write(desc, buff, 1);
    // Zwalniamy deskryptor
    close(desc);
    // Tworzymy semafor
    sem_t *semaphore = semcreate(name, O_CREAT | O_EXCL ,0644,1);
    // Ustawiamy żeby przy zakończeniu programu funkcja semdelete usuwała semafor
    atexit(semdelete);
    // Ustawiamy żeby po otrzymaniu sygnału sigint program usunął semafor
    if (signal(SIGINT, handler) == SIG_ERR)
    {
        perror("signal() error");
        _exit(EXIT_FAILURE);
    }
    // Inicjalizujemy zmienną do której będziemy pobierać wartość semafora;
    int value;
    // Pobieramy wartość semafora
    semgetvalue(semaphore, &value);
    // Zamykamy semafor
    semclose(semaphore);
    // Wypisujemy adress o wartość semafora
    printf("Semafor o adresie: %p, ma wartość: %i\n\n", (void *)semaphore, value);
    // Inicjujemy tablicę w której będziemy przechowywać ścieżkę do program dla procesów potomnych
    char path[30] = "./";
    // Inicjujemy tablicę przechowującą rozszerzenie programu dla procesów potomnych
    char end[3] = ".x";
    // Łączymy początek ścieżki z nazwą programu
    strncat(path, argv[1], 20);
    // Dodajemy rozszerzenie
    strncat(path,end, 3);

    // Rzutujemy na liczbę całkowitą, ilość procesów potomnych 
    int n = atoi(argv[2]);
    for(int i = 0; i < n; i++)
    {
        // Tworzymy procesy potomne
        switch(fork())
        {
            case -1:
            perror("Fork error");
            exit(1);

            case 0:
            // Uruchamiamy w nich program do wzajęmnego wykluczania
            execl(path, argv[1], argv[3], NULL);
            perror("execl error");
            _exit(2);

            default:
            // Oczekujemy na zamknięcie procesów potomnych
            wait(NULL);
            break;
        }
    }
    
    return 0;
}
