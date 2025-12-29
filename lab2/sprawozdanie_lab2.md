# SPRAWOZDANIE

Sprawozdanie wykonane przez Pawła Rumpla o numerze indeksu 283849 z kierunku Cyberbezpieczeństwo drugi rok, trzeci semestr. Sprawozdanie dotyczy drugich laboratoriów z przedmiotu Programowanie Systemowe. Laboratoria te polegały na zaznajomieniu się z Makefile. Zajęcia były przeprowadzone na komputerach z środowiskiem Linux w sali laboratoryjnej 127L w budynku C-3. Laboratorium zostało wykonane w dniu 22 października 2025 roku. 

## Podstawy Makefile

Na początku zaznajomiłem się z podstawami Makefile. Makefile to plik konfiguracyjny dla programu make, który pozwala automatycznie wykonywać powtarzalne zadania w projekcie. Jest to bardzo przydatne do czynności takich jak build, run czy clean. W Makefile definiujemy cele (targets) w postaci:

<pre>
cel: zależności
	komendy
</pre>
Możemy natknąć również się na zmienne, które pozwalają nam na przechowywanie danych. Stworzyłem folder na pulpicie w którym potem stworzyłem plik Makefile. Plik ten miał stworzyć plik którego nazwą miała być aktualna nazwa użytkownika oraz aktualny timestamp. Timestamp to czas w sekundach od 1 Stycznia, 1970 (UTC). Program miał również umieć usunąć ten plik.

<pre>
USERNAME := $(shell whoami)
STAMP := $(shell date +%s)
file := $(USERNAME).$(STAMP)

all:
	touch $(file)
  
clean:
	rm $(USERNAME).*
</pre>

Wywołujemy działanie pliku w terminalu za pomocą komendy: 
```console
student:~$ make
touch student.1730052007

student:~$ make clean
rm student.*
```

## Warunki Celów

W dalszej części laboratorium zaznajomiłem się z możliwością ustawienia warunków dla celów w Makefile. Po pierwsze, dodałem do makefile możliwość kopiowania pliku data.txt. Warunek celu, ma upewnić się, że plik data.txt istnieje. W przypadku gdy plik nie istnieje i wystąpiłby błąd, tworzony jest plik data.txt o zawartości "abcd", w przypadku gdy jakiś plik data.txt istnieje, nie zostanie on nadpisany. Przy komendzie rm używamy * żeby usuneło wszystkie pliki zaczynające się od USERNAME, ponieważ tej części nazwy pliku jesteśmy pewni, nie jesteśmy w stanie znać pełnej nazwy pliku gdyż timestamp ciągle się zmienia.

<pre>
USERNAME := $(shell whoami)
STAMP := $(shell date +%s)
file := $(USERNAME).$(STAMP)

all: data.txt
	cp data.txt $(file)	
clean:
	rm $(USERNAME).*
        
data.txt:
	echo "abcd" > data.txt
</pre>

## Tworzenie Folderów za pomocą Makefile

Pod koniec laboratorium zastosowałem make do stworzenia folderu o wybranej nazwie. Program upewnia się, że istnieje zarówno plik data.txt w podfolderze o wybranej nazwie jak i sam podfolder. Cele mogą również zawierać nazwy pod postacią zmiennych.
<pre>
USERNAME := $(shell whoami)
STAMP := $(shell date +%s)
file := $(USERNAME).$(STAMP)
folder := build

all: data.txt $(folder)

	cp data.txt $(folder)/$(file)    
clean:
	rm -rf $(folder) data.txt
        
data.txt:
	echo "abcd" > data.txt
$(folder):
	mkdir $(folder)
</pre>

## Wnioski
Make pomaga w automatyzacji różnych celów jak np build, run czy clean. Jest on podręczny gdyż w jednym pliku możemy przechowywać różne cele. Posiadanie zmiennych również ułatwia użytkowanie.
