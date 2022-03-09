# Systemy Operacyjne 2022
> Autor: Tymoteusz Białkowski

## Zawartość folderu
Pliki z kodem:
 - 1A.c 
 - 1B.c
 - 1C.c
 - 1D.c
 - 1E.c

Plik Makefile do kompilacji, linkowania, uruchamiania, czyszczenia i archiwizacji
 - Makefile
 
Plik README w formacie .md
 - README.md

## Ćwiczenie 1.A [X]
Napisać program wypisujący identyfikatory UID, GID, PID, PPID i PGID dla danego procesu

## Ćwiczenie 1.B []
Wywołać funkcję ```c fork``` trzy razy (najlepiej w pętli ```c for```) i wypisać powyższe 
identyfikatory dla procesu macierzystego oraz wszystkich procesów potomnych. 
Przy pomocy funkcji ```c wait``` sprawić, aby proces macierzysty zaczekał na zakończenie
wszystkich procesów potomnych.
## Ćwiczenie 1.C []
Jak w (b), tylko przy użyciu funkcji ```c sleep``` (! nie używać funkcji ```c wait```) sprawiać
by procesy potomne były adoptowane przez proces ```bash init``` lub ```bash systemd;``` poleceniem
```bash pstree -p``` z poziomu powłoki wyświetlić drzewo procesów w danym systemie i
zidentyfikować proces adoptujący osierocone procesy.
## Ćwiczenie 1.D []
Jak w (b), tylko wstawić funkcję ```c sleep``` w takich miejscach programu, aby
procesy pojawiały się na ekranie grupowane pokoleniami od najstarszego do
najmłodszego, a proces macierzysty kończył się dopiero po procesach potomnych
(! nie używać funkcji ```c wait```). Na podstawie wyników programu sporządzić 
(w pliku tekstowym), drzewo genealogiczne tworzonych procesów z zaznaczonymi
identyfikatorami PID, PPID i PGID.

## Ćwiczenie 1.E []
Jak w (b), tylko przy u ̇zyciu fukcji setpgid sprawić by każdy proces potomny
stawał się liderem swojej własnej grupy procesów.

## Jak uruchomic programy: 

Katalog zawiera program Makefile do kompilacji, linkowania
i uruchamiania powyzszych programow, a takze czyszczenia katalogu 
i jego archiwizacji.


### Uruchamianie
Aby uruchomic 1-szy program, nalezy wykonac komende:
```bash make runA```
Aby uruchomic 2-gi program, nalezy wykonac komende:
```bash make runB```
Aby uruchomic 3-ci program, nalezy wykonac komende:
```bash make runC```
Aby uruchomic 4-ty program, nalezy wykonac komende:
```bash make runD```
Aby uruchomic 5-ty program, nalezy wykonac komende:
```bash make runE```


### Czyszczenie
Aby wyczyscic zawartosc katalogu (usunac zbedne pliki), nalezy wykonac:
```bash make clean```

### Archiwizacja
W celu archiwizacji oraz kompresji katalogu nalezy wykonac:
```bash make tar```

> Zaktualizowano 09.03.2022