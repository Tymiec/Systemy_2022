#ifndef HEADER_FILE
#define HEADER_FILE

// Funkcja do tworzenia semafora
sem_t *semcreate(const char*, int, mode_t, unsigned int);

// Funkcja do otwierania semafora
sem_t *semopen(const char*, int);

// Funkcja do zamykania semafora
void semclose(sem_t*);

// Funkcja do usuwania semafora
void semremove(const char*);

// Funkcja do zajmowania semafora
void semwait(sem_t*);

// Funkcja do opuszczania semafora
void sempost(sem_t*);

// Funkcja do pobierania wartości semafora
void semgetvalue(sem_t*, int*);

#endif