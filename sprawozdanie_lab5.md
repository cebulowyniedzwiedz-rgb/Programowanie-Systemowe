# SPRAWOZDANIE - Laboratorium 5
Sprawozdanie wykonane przez Pawła Rumpla o numerze indeksu 283849 z kierunku Cyberbezpieczeństwo, drugi rok, trzeci semestr. Sprawozdanie dotyczy czwartych laboratoriów z przedmiotu Programowanie systemowe. Laboratorium to polegało na zapoznaniu się z funkcjami fork() i pipe() w języku C. Zajęcia były przeprowadzone na komputerach z systemem Linux w sali laboratoryjnej 127L w budynku C-3. Laboratorium zostało wykonane w dniu 18 listopada 2025 roku.

##Podstawowy program w C
Stworzyłem bardzo podstawowy kod w C który umożliwiał podanie jakiegoś słowa i zamieniał on pierwszą literę tego słowa na 'X'. Podstawa ta miała pozwolić na przetestowania fork() i pipe() w dalszej częsci laboratorium.

##Funkcja Fork()
Funkcja fork() pozwala nam na utworzenie nowego procesu. Teraz program działa równocześnie na dwóch procesach. Przy utworzeniu, funkcja zwraca zmienną pid_t która przechowuje index procesu. Pozwala nam on zidentyfikować czy proces jest procesem rodzicem czy procesem dzieckiem. W przypadku gdy jest to proces dziecko, wartość będzie równa 0. W przypadku rodzica, wartość będzie większa niż 0. Gdy funkcja zwróci wartość mniejszą niż 0 oznacza to iż zaistniał błąd. Pozwala to na łatwe rozpoznanie w jakim procesie się znajdujemy.
