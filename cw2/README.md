# Ćwiczenie 2
> Autor: Tymoteusz Białkowski
 
## Zawartość folderu
Pliki z kodem:
 - 1B.c
 - wypisywanie.c


Plik Makefile do kompilacji, linkowania, uruchamiania, czyszczenia i archiwizacji
 - Makefile

Plik README w formacie .md
 - README.md

## Ćwiczenie A

Zmodyfikować program z ćwiczenia 1b, tak aby komunikaty procesów potomnych by były
wypisywane przez program uruchamiany przez funkcję execlp. Nazwę programu do 
uruchomienia przekazywać przez argumenty programu procesu macierzystego.

## Jak uruchomic programy: 

Katalog zawiera program Makefile do kompilacji, linkowania
i uruchamiania powyzszych programow, a takze czyszczenia katalogu 
i jego archiwizacji.


### Uruchamianie
Aby uruchomic program, nalezy wykonac komende:
```make run```

### Czyszczenie
Aby wyczyscic zawartosc katalogu (usunac zbedne pliki), nalezy wykonac:
```make clean```

### Archiwizacja
W celu archiwizacji oraz kompresji katalogu nalezy wykonac:
```make tar```



> Zaktualizowano 21.03.2022