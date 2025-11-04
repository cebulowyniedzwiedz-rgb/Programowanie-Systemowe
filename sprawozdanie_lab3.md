# SPRAWOZDANIE - Laboratorium 3
Sprawozdanie wykonane przez Pawłą Rumpla o numerze indeksu 283849 z kierunku Cyberbezpieczeństwo, drugi rok, trzeci semestr. Sprawozdanie dotyczy drugich laboratoriów z przedmiotu Programowanie systemowe. Laboratoria te polegały na użyciu Make do kompilacji kodu w języku C. Zajęcia były przeprowadzone na komputerach z systemem Linux w sasli laboratoryjnej 127L w budynku C-3. Laboratorium zostało wykonane w dniu 29 października 2025 roku.

## Kompilacja dzięki Make
Zostało nam zadane wykonanie kompilacji pliku w języku C do pliku binarnego wykonywalnego, który miał się znajdować w podfolderze /build. Sam kod C miał znajdować się w podfolderze /SRC (od ang. source). Plik który mieliśmy skompilować, nazywał się helloworld.c. Plik binarny miał zachować nazwę, tylko bez końcówki .c. Make często używa się do kompilacji. Dobrą zasadą stosowaną przy kompilacji jest, żeby plik który będziemy kompilować, znajdował się w podfolderze /SRC, a plik binarny, który stworzymy, znajdował się w podfolderze /build. Do kompilacji używamy komendy gcc.

##Przypisanie komendy do zmiennej
Dobrą regułą jest nie przepisywać ciągle tej samej komendy, a zapisać ją jako zmienną, tak samo jak zrobiłem to z komendą gcc. Ułatwia to podmianę komendy gcc na jakąś inną komendę, którą możemy użyć do kompilacji.

##Pusta reguła all
Kolejną dobrą zasadą, którą powinniśmy stosować przy pisaniu Make, jest to żebyśmy ograniczyli regułe all do minimum. Pozwala to podzielić zadanie na mniejsze części, w których łatwiej jest się zorientować i znaleźć błąd. W takim przypadku przy regule all stawiamy warunki, którymi są inne reguły, w naszym przypadku jest to reguła $(TARGET). Ze względu na to, że warunkami reguły $(TARGET) są reguła $(OUTDIR) i reguła $(TARGET).o, one również muszą być spełnione, by wykonać regułę all. 
