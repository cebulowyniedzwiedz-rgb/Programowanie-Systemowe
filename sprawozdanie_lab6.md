# SPRAWOZDANIE - Laboratorium 5
Sprawozdanie wykonane przez Pawła Rumpla o numerze indeksu 283849 z kierunku Cyberbezpieczeństwo, drugi rok, trzeci semestr. Sprawozdanie dotyczy czwartych laboratoriów z przedmiotu Programowanie systemowe. Laboratorium to polegało na dalszym zapoznaniu się z funkcjami fork() i pipe() w języku C. Zajęcia były przeprowadzone na komputerach z systemem Linux w sali laboratoryjnej 127L w budynku C-3. Laboratorium zostało wykonane w dniu 26 listopada 2025 roku.

## Założenia działania programu
Program ma się składać z dwóch plików Worker i Serwer. Jeden z nich ma być operowany przez rodzica a drugi przez proces dziecko. Ma w nich następować pętla które powoduje, że użytkownik może bez końca wpisywać słowo by dostać to samo słowo z zmienioną pierwszą literą. By zakończyć program należy wpisać "exit".
