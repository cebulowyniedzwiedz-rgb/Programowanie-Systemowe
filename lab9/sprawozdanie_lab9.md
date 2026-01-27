# SPRAWOZDANIE - Laboratorium 9
Sprawozdanie wykonane przez Pawła Rumpla o numerze indeksu 283849 z kierunku Cyberbezpieczeństwo, drugi rok, trzeci semestr. Sprawozdanie dotyczy dziewiątych laboratoriów z przedmiotu Programowanie systemowe. Laboratorium to polegało na zapoznaniu się z wątkami i komunikacją sieciową. Zajęcia były przeprowadzone na komputerach z systemem Linux w sali laboratoryjnej 127L w budynku C-3. Laboratorium zostało wykonane w dniu 14 stycznia 2026 roku.

## Założenie działania programu
Program tak jak poprzednio ma przyjmować jeden na wejściu jakiś ciąg znaków i zamieniać pierwszą litere na 'X'. W tym przypadku trzeba użyć wątków i komunikacji sieciowej. Oprócz tego użyłem pipeów do komunikacji. Użyłem też mutexów do organizacji oraz użyłem inetd do łatwiejszej komunikacji sieciowej.

## Inetd i komunikacja sieciowa
netd jest to standardowy demon systemowy . Działa on w ten sposób, że nasłuchuje na porcie i po nawiązaniu połączenia uruchamia wskazany program, przesyłając do niego jako standardowe wejście dane z danego socketu, a wszystkie dane ze standardowego wyjścia również wysyła na socket. Działam na porcie 8080 i używam program w pythonie jako mojego klienta sieciowego. Warto wspomnieć, że wymagana jest konfiguracja Inetd. Trzeba się upewnić czy jest obecne na komputerze a potem trzeba utworzyć plik konfiguracyjny. Znajdować się powinien w /src/xinetd.d/"nazwa_pliku_konfiguracyjnego_ktory_stworzymy". Ten plik powinien wyglądać podobnie jak poniżej:

### Plik 
```
service main
{
    type        = UNLISTED
    port        = 8080
    socket_type = stream
    protocol    = tcp
    wait        = no
    user        = vagrant
    server      = /home/vagrant/PSYS-mojewlasne/Programowanie-Systemowe/lab9/build/main
    disable     = no
}

```
## Wątki 
Wątki działają w ten sposób, że pozwalają wykonywać wiele zadań jednocześnie w ramach jednego procesu, współdzieląc przy tym tę samą pamięć i zmienne globalne. Worker działa jako wątek, przyjmuje on zmienną arg która posiada inne zmienne takie jak fd i fd1 odpowiadające za działanie pipeów. Dlatego zmieniamy mocno zarówno plik worker.c jak i worker.h.

### main.c
```c
```
