# SPRAWOZDANIE

Sprawozdanie wykonane przez Pawła Rumpla o numerze indeksu 283849 z kierunku Cyberbezpieczeństwo drugi rok, trzeci semestr. Sprawozdanie dotyczy drugich laboratoriów z przedmiotu Programowanie Systemowe. Laboratoria te polegały na zaznajomieniu się z Makefile. Zajęcia były przeprowadzone na komputerach z środowiskiem Linux w sali laboratoryjnej 127L w budynku C-3.

## Podstawy Makefile

Na początku zaznajomiłem się z podstawami Makefile. Stworzyłem folder na pulpicie w którym potem stworzyłem plik Makefile. Plik ten miał stworzyć plik którego nazwą miała być aktualna nazwa użytkownika oraz aktualny timestamp. Timestamp to czas w sekundach od 1 Stycznia, 1970 (UTC). Program miał również umieć usunąć ten plik.

<pre>
USERNAME := $(shell whoami)
STAMP := $(shell date +%s)
file_ := $(USERNAME).$(STAMP)

all:
	touch $(file_)
  
clean:
	rm $(Username).*
</pre>

Wywołujemy działanie pliku w terminalu za pomocą komendy: 
<pre><code class="language-bash">
make
touch student.1730052007

make clean
rm student.*
</code></pre>
