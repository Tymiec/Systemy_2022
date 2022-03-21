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
(funkcja ```pause()```); numer sygnału przekazywać jako argument wywołania programu; niech proces wypisze na ekranie swój PID, a funkcja do własnej obsługi sygnału wypisze jego numer i nazwę (można wstawić krótki sleep).

## Podpunkt 3.B

Dwa programy - pierwszy w procesie potomnym uruchamia program z podpunktu (a), po czym z procesu macierzystego wysyła do niego sygnał; w procesie macierzystym przed wywołaniem funkcji kill() proszę wstawić funkcję sleep() z krótkim czasem uśpienia.

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