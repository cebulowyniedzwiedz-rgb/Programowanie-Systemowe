# SPRAWOZDANIE - Laboratorium 3
Sprawozdanie wykonane przez Pawła Rumpla o numerze indeksu 283849 z kierunku Cyberbezpieczeństwo drugi rok, trzeci semestr. Sprawozdanie dotyczy drugich laboratoriów z przedmiotu Programowanie Systemowe. Laboratoria te polegały na użyciu Make do kompilacji kodu C. Zajęcia były przeprowadzone na komputerach z środowiskiem Linux w sali laboratoryjnej 127L w budynku C-3. Laboratorium zostało wykonane w dniu 29 października 2025 roku. 

## Kompilacja dzięki Make
Zostało nam zadane wykonanie kompilacji pliku w języku C do pliku binarnego wykonywalnego który miał się znajdować w podfolderze /build. Sam kod w języku C miał znajdować się w folderze SRC (od ang. source). Plik który mieliśmy zkompilować nazywał się "helloworld.c:". Plik binarny miał zachować nazwe tylko bez końcówki ".c". Make często używa się do kompilacji. Dobrą zasadą używaną przy kompilacji jest żeby plik który będziemy kompilować znajdował się w podfolderze /SRC a plik binarny który stworzymy będzie znajdował się w podfolderze /build. Do kompilacji użyjemu komendy gcc.

### Przypisanie komendy do zmniennej
Dobrą regułą jest nie przepisywać ciągle tej samej komendy a zapisać ją jako zmienną tak samo jak ja zrobiłem to z komendą gcc. Ułatwia to podmienienie komendy gcc na jakąś inną komende którą możemy użyć do kompilacji. 

### Pusta reguła all
Kolejną dobrą zasadą którą powinniśmy używać przy pisaniu Make, jest to żebyśmy ograniczyli regułe all do minimum. Pozwala to podzielenie zadania na mniejsze części w których łatwiej jest się zorientować i znaleźć błąd. W takim przypadku przy regule all stawiamy warunki którymi są inne reguły, w naszym przypadku jest to reguła $(TARGET). 
