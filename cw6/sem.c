#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <semaphore.h>
#include <fcntl.h>
#include "sem.h"

// Funkcja do tworzenia semafora
sem_t *semcreate(const char *name, int oflag, mode_t mode, unsigned int value)
{
    // Tworzymy semafor z obsługą błędów
    sem_t *semaphore = sem_open(name, oflag, mode, value);
    if (semaphore == SEM_FAILED)
    {
        perror("sem_open error1!");
        _exit(1);
    }
    // Zwracamy adres semafora
    return semaphore;
}

// Funkcja do otwierania semafora
sem_t *semopen(const char* name, int oflag)
{
    // Otwieramy semafor z obsługą błędów
    sem_t *semaphore = sem_open(name, oflag);
    if (semaphore == SEM_FAILED)
    {
        perror("sem_open error2!");
        _exit(2);
    }
    // Zwracamy adres semafora
    return semaphore;
}

// Funkcja do zamykania semafora
void semclose(sem_t *sem)
{
    // Zamykamy semafor z obsługą błędów
    if (sem_close(sem)==-1)
    {
        perror("sem_close error!");
        _exit(3);
    }
}

// Funkcja do usuwania semafora
void semremove(const char *name)
{
    // Usuwamy semafor z obsługą błędów
    if(sem_unlink(name)==-1)
    {
        perror("sem_unlink error!");
        _exit(4);
    }
}

// Funkcja do zajmowania semafora
void semwait(sem_t *sem)
{
    // Zajmujemy semafor z obsługą błędów
    if(sem_wait(sem)==-1)
    {
        perror("sem_wait error!");
        _exit(5);
    }
}

// Funkcja do opuszczania semafora
void sempost(sem_t *sem)
{
    // Zwalniamy semafor z obsługą błędów
    if(sem_post(sem)==-1)
    {
        perror("sem_post error!");
        _exit(6);
    }
}

// Funkcja do pobierania wartości semafora
void semgetvalue(sem_t *sem, int *value)
{
    // Pobieramy wartość semafora z obsługą błędów
    if(sem_getvalue(sem, value)==-1)
    {
        perror("sem_getvalue error!");
        _exit(7);
    }
}

