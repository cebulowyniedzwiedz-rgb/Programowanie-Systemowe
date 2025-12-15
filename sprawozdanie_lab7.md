# SPRAWOZDANIE - Laboratorium 7
Sprawozdanie wykonane przez Pawła Rumpla o numerze indeksu 283849 z kierunku Cyberbezpieczeństwo, drugi rok, trzeci semestr. Sprawozdanie dotyczy czwartych laboratoriów z przedmiotu Programowanie systemowe. Laboratorium to polegało na zapoznaniu się z pipe'ami nazwanymi. Zajęcia były przeprowadzone na komputerach z systemem Linux w sali laboratoryjnej 127L w budynku C-3. Laboratorium zostało wykonane w dniu 26 listopada 2025 roku.

## Założenie działania programu
Program miał być rozszerzeniem programu stworzonego na poprzednich zajęciach, z tą różnicą, że zamiast zwykłych pipe’ów miał on używać pipe’ów nazwanych. Jest to mechanizm komunikacji pomiędzy procesami komputera. W przeciwieństwie do zwykłego (anonymous) pipe’a, pipe nazwany umożliwia komunikację pomiędzy procesami, które mogą być od siebie niezależne. Jest to możliwe dzięki utworzeniu odpowiedniego pliku służącego do komunikacji za pomocą pipe’a. Dane przechowywane są w pamięci i można je otwierać, zamykać, czytać oraz zapisywać.

## Pliki server.c i worker.c
Pliki te są identyczne jak w poprzednim zadaniu, z tą jedyną różnicą, że funkcje server() i worker() zamiast przyjmować dwuelementowe tablice typu int, przyjmują pojedyncze wartości typu int. Wynika to z faktu, że nie jest przekazywany cały pipe, lecz tylko jeden z jego końców (do odczytu lub zapisu).
