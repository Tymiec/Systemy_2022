# Odpowiedź do zadania 2
> Autor: Tymoteusz Białkowski

## Odpowiedź:

Powstanie n takich procesów. Jest to spowodowane tym, że przy kazdym wywolaniu funkcji fork() (którą wywołujemy 3 razy)
zostanie zostanie uruchomiony program przez funkcje exec(), gdy ten program zakonczy swoje
dzialanie a tym samym nie powieli się tak jak działo się w zadaniach z ćwiczenia 1

> Zaktualizowano 15.03.2022