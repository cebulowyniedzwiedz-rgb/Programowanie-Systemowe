# SPRAWOZDANIE - Laboratorium 3
Sprawozdanie wykonane przez Pawła Rumpla o numerze indeksu 283849 z kierunku Cyberbezpieczeństwo, drugi rok, trzeci semestr. Sprawozdanie dotyczy drugich laboratoriów z przedmiotu Programowanie systemowe. Laboratoria te polegały na użyciu `Make` do kompilacji kodu w języku C. Zajęcia były przeprowadzone na komputerach z systemem Linux w sali laboratoryjnej 127L w budynku C-3. Laboratorium zostało wykonane w dniu 29 października 2025 roku.

## Plik C
Przygotowałem krótki plik C który zawierał krótką funkcje hello world. 
```c
#include <stdio.h>
int main() {
   printf("Hello World!");
   return 0;
}
```
## Kompilacja dzięki Make
Zostało nam zadane wykonanie kompilacji pliku w języku C do pliku binarnego wykonywalnego, który miał się znajdować w podfolderze `/build`. Sam kod C miał znajdować się w podfolderze `/src` (od ang. source). Plik, który mieliśmy skompilować, nazywał się `helloworld.c`. Plik binarny miał zachować nazwę, tylko bez końcówki `.c`. `Make` często używa się do kompilacji. Dobrą zasadą stosowaną przy kompilacji jest, żeby plik, który będziemy kompilować, znajdował się w podfolderze `/src`, a plik binarny, który stworzymy, znajdował się w podfolderze `/build`. Do kompilacji używamy komendy `gcc`.
```make
SRCDIR := SRC
OUTDIR := build
TARGET := helloworld
CC := gcc

all: $(TARGET)

$(TARGET): $(TARGET).o $(OUTDIR)
	$(CC) $(OUTDIR)/$(TARGET).o -o $(OUTDIR)/$(TARGET)
$(TARGET).o: $(OUTDIR)
	$(CC) -c $(SRCDIR)/$(TARGET).c -o $(OUTDIR)/$(TARGET).o
clean:
	rm $(OUTDIR)/$(TARGET)
$(OUTDIR):
	mkdir $(OUTDIR)

```
## Przypisanie komendy do zmiennej
Dobrą regułą jest nie przepisywać ciągle tej samej komendy, a zapisać ją jako zmienną, tak samo jak zrobiłem to z komendą `gcc`. Ułatwia to podmianę komendy `gcc` na jakąś inną komendę, którą możemy użyć do kompilacji.

## Pusta reguła all
Kolejną dobrą zasadą, którą powinniśmy stosować przy pisaniu `Make`, jest to, żebyśmy ograniczyli regułę `all` do minimum. Pozwala to podzielić zadanie na mniejsze części, w których łatwiej jest się zorientować i znaleźć błąd. W takim przypadku przy regule `all` stawiamy warunki, którymi są inne reguły, w naszym przypadku jest to reguła `$(TARGET)`. Ze względu na to, że warunkami reguły `$(TARGET)` są reguła `$(OUTDIR)` i reguła `$(TARGET).o`, one również muszą być spełnione, by wykonać regułę `all`. Warto zaznaczyć, że dwie różne reguły mogą posiadać ten sam warunek, w tym przypadku zarówno `$(TARGET).o`, jak i `$(TARGET)` posiadają warunek `$(OUTDIR)`.

## Działanie komendy gcc
Komendy `gcc` używamy do kompilacji pliku w języku C. Dodajemy `-o` (od ang. output) do komendy, żeby wskazać dokładny plik binarny, do którego ma być skompilowany nasz plik w języku C. Komenda `gcc` automatycznie kompiluje i linkuje plik. Jeśli użyjemy komendy `gcc` z dodatkiem `-c`, plik tylko skompilujemy, bez linkowania. Takie pliki nazywamy z końcówką `.o`. Taki plik możemy zlinkować, wywołując normalne polecenie `gcc` na nim.

## Używanie zmiennych
Używanie zmiennych zamiast ciągłego wpisywania tej samej wartości ma bardzo wiele zalet. Szczególnie ułatwia to późniejszą ewentualną podmianę wartości. Mój plik `Makefile` zawiera bardzo dużo zmiennych, prawie wszystko jest w nich zapisane, co bardzo ułatwia pracę nad takim plikiem, szczególnie gdyby był on większy.
