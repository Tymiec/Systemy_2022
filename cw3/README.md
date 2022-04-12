# Ćwiczenie 3
> Autor: Tymoteusz Białkowski
 
## Zawartość folderu
Pliki z kodem:
 - 3A.c
 - 3B.c
 - 3C.c


Plik Makefile do kompilacji, linkowania, uruchamiania, czyszczenia i archiwizacji
 - Makefile

Plik README w formacie .md
 - README.md

## Podpunkt 3.A

Jeden program który ustawia obsługę sygnału na 3 sposoby zgodnie z opcją podaną jako argument wywołania programu, a następnie czeka na sygnał 
(funkcja ```pause()```). Numer sygnału przekazywać jako argument wywołania programu, niech proces wypisze na ekranie swój ```PID```, a funkcja do własnej obsługi sygnału wypisze jego numer i nazwę (można wstawić krótki ```sleep```).

## Podpunkt 3.B

Dwa programy - pierwszy w procesie potomnym uruchamia program z podpunktu (a), po czym z procesu macierzystego wysyła do niego sygnał. 
W procesie macierzystym przed wywołaniem funkcji ```kill()``` proszę wstawić funkcję ```sleep()``` z krótkim czasem uśpienia.

## Podpunkt 3.C

trzy programy - pierwszy tworzy jeden proces potomny i uruchamia w nim program, który ustawia ignorowanie sygnału, staje się liderem swojej grupy procesów, a następnie tworzy kilka procesów potomnych, które uruchamiają program z podpunktu (a); pierwszy proces macierzysty, po krótkim czasie uśpienia (funkcja ```sleep()```) wysyła sygnał do całej grupy procesów; procesy macierzyste po utworzeniu wszystkich swoich procesów potomnych powinny na nie poczekać (funkcja ```wait()``` lub ```waitpid()```).

> Programy kompilować/linkować z opcjami: ```-Wall -std=c99 -pedantic```
> UWAGA: W nowych wersjach Linuksa użycie powyższych opcji kompilatora skutkuje ostrzeżeniem, że funkcja ```kill()``` jest niezadeklarowana - aby tego uniknąć, należy na początku pliku użyć makra preprocesora: ```#define _POSIX_C_SOURCE 200112L```
> Aby uniknąć podobnych ostrzeżeń dla funkcji ```getpid()``` trzeba dodać makro: ```#define _XOPEN_SOURCE 500```

## Jak uruchomic programy: 

Katalog zawiera program Makefile do kompilacji, linkowania
i uruchamiania powyzszych programow, a takze czyszczenia katalogu 
i jego archiwizacji.


### Uruchamianie

Aby uruchomić podpunkt 3A, wykonujemy komendę:

```bash
make SIGNAL=? OPTION=? runA
```
gdzie `SIGNAL` to numer sygnału, a OPTION sposób obsłużenia `[default/ignore/custom]`


Aby uruchomić podpunkt 3B, należy wykonać komendę:

```bash
make SIGNAL=? OPTION=? runB
```
gdzie `SIGNAL` to numer sygnału, a OPTION sposób obsłużenia `[default/ignore/custom]`


Aby uruchomić podpunkt C, należy wykonać komendę:

```bash
make SIGNAL=? OPTION=? runC
```
gdzie `SIGNAL` to numer sygnału, a OPTION sposób obsłużenia `[default/ignore/custom]`


### Czyszczenie
Aby wyczyscic zawartosc katalogu (usunac zbedne pliki), nalezy wykonac:
```bash
make clean
```

### Archiwizacja
W celu archiwizacji oraz kompresji katalogu nalezy wykonac:
```bash
make tar
```



> Zaktualizowano 11.04.2022