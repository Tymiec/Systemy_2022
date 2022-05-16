# Ćwiczenie 6
> Autor: Tymoteusz Białkowski
 
## Zawartość folderu
Pliki z kodem:
 - program.c
 - powielacz.c
 - sem.c
 - sem.h

Plik z numerem:
 - numer.txt

Plik Makefile do kompilacji, linkowania, uruchamiania, czyszczenia i archiwizacji
 - Makefile

Plik README w formacie .md
 - README.md

## Podpunkt 6.A

Implementacja wzajemnego wykluczania procesów poprzez semafory

## Podpunkt 6.B

Tworzenia procesów potomnych oraz uruchamiania w nich programu pierwszego

## Jak uruchomic programy: 

Katalog zawiera program Makefile do kompilacji, linkowania
i uruchamiania powyzszych programow, a takze czyszczenia katalogu 
i jego archiwizacji.


### Uruchamianie
Aby uruchomic program, nalezy wykonac komende:
```make program PROG1= NPROCES= NCSESION=```

PROG1 - Nazwa programu do wzajemnego wykluczania
(standardowo: program)

NPROCES - Liczbę procesów potomnych

NCSESION - Liczbę sekcji krytycznych

czyli
```make program PROG1=program NPROCES=2 NCSESION=2```

### Czyszczenie
Aby wyczyscic zawartosc katalogu (usunac zbedne pliki), nalezy wykonac:
```make clean```

### Archiwizacja
W celu archiwizacji oraz kompresji katalogu nalezy wykonac:
```make tar```



> Zaktualizowano 17.05.2022