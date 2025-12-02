# SPRAWOZDANIE - Laboratorium 5
Sprawozdanie wykonane przez Pawła Rumpla o numerze indeksu 283849 z kierunku Cyberbezpieczeństwo, drugi rok, trzeci semestr. Sprawozdanie dotyczy czwartych laboratoriów z przedmiotu Programowanie systemowe. Laboratorium to polegało na dalszym zapoznaniu się z funkcjami fork() i pipe() w języku C. Zajęcia były przeprowadzone na komputerach z systemem Linux w sali laboratoryjnej 127L w budynku C-3. Laboratorium zostało wykonane w dniu 26 listopada 2025 roku.

## Założenia działania programu
Program ma się składać z osobnych plików Worker i Serwer. Jeden z nich ma być operowany przez rodzica a drugi przez proces dziecko. Ma w nich następować pętla które powoduje, że użytkownik może bez końca wpisywać słowo by dostać to samo słowo z zmienioną pierwszą literą. By zakończyć program należy wpisać "exit". Main.c posiada dwie zmienne odpowiadające za obsługe dwóch pipe'ów. Jeden pipe służy do przesyłania rzeczy z rodzica do dziecka a drugi do procesu przeciwnego. Obie te zmienne są przekazywane jako wartości dla funkcji worker() i server().

## Worker
Worker miał być rodzicem i odpowiadać za pobranie od użytkownika ciągu znaków oraz później zwróceniu zeedytowanego przez Serwer ciągu znaków. Miał on działać w pętli nieprzerwanie do momentu gdy ciąg znaków będzie wynosił "exit". Wysyła on dane w pipe fd a odbiera w pipe fd1. Poniżej zamieszczam zawartość plików worker.h oraz worker.c.

### Worker.c:
```c

```
