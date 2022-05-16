# Ćwiczenie 5
> Autor: Tymoteusz Białkowski
 
## Zawartość folderu
Pliki z kodem:
 - 5A.c
 - producent.c
 - konsument.c

Pliki wejścia i wyjścia:
 - wejscie
 - wyjscie

Plik Makefile do kompilacji, linkowania, uruchamiania, czyszczenia i archiwizacji
 - Makefile

Plik README w formacie .md
 - README.md

## Podpunkt 5.A

Utworzyć potok FIFO z programu

## Podpunkt 5.B

Utworzyć potok FIFO z linii komend

## Jak uruchomic programy: 

Katalog zawiera program Makefile do kompilacji, linkowania
i uruchamiania powyzszych programow, a takze czyszczenia katalogu 
i jego archiwizacji.


### Uruchamianie
Aby uruchomic program, nalezy wykonac komende:
```make program PROG1= PROG2= FIFO= RFILE= WFILE=```

PROG1 - Nazwa programu producenta

PROG2 - Nazwa programu konsumenta

FIFO - Nazwa potoku

RFILE - Nazwa pliku do czytania

WFILE - Nazwa pliku do pisania

czyli przykładowo 

```make program PROG1=producent PROG2=konsument FIFO=fifo RFILE="wejscie" WFILE="wyjscie"```
### Czyszczenie
Aby wyczyscic zawartosc katalogu (usunac zbedne pliki), nalezy wykonac:
```make clean```

### Archiwizacja
W celu archiwizacji oraz kompresji katalogu nalezy wykonac:
```make tar```



> Zaktualizowano 16.05.2022