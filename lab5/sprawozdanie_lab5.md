# SPRAWOZDANIE - Laboratorium 5
Sprawozdanie wykonane przez Pawła Rumpla o numerze indeksu 283849 z kierunku Cyberbezpieczeństwo, drugi rok, trzeci semestr. Sprawozdanie dotyczy czwartych laboratoriów z przedmiotu Programowanie systemowe. Laboratorium to polegało na zapoznaniu się z funkcjami fork() i pipe() w języku C. Zajęcia były przeprowadzone na komputerach z systemem Linux w sali laboratoryjnej 127L w budynku C-3. Laboratorium zostało wykonane w dniu 18 listopada 2025 roku.

## Podstawowy program w C
Stworzyłem bardzo podstawowy kod w C który umożliwiał podanie jakiegoś słowa i zamieniał on pierwszą literę tego słowa na 'X'. Podstawa ta miała pozwolić na przetestowania fork() i pipe() w dalszej częsci laboratorium.

## Gotowy Kod w C
Poniżej znajduje się w pełni gotowy kod w języku C. Przyjmuje on ciąg znaków od użytkownika (w procesie rodzica), zamienia pierwsą litere na 'X' (w procesie dziecka) i wypisuje ten ciąg znaków (również w procesie dziecka).

- Zmienna input przechowuje ciąg znaków wprowadzony przez użytkownika.
- Zmienna fd odpowiada za pomyślne działanie pipe.
- Zmienna input2 pozwala przesłać zmienną input poprzez pipe.

```c                                                   
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
int main() {
        int fd[2];
        pipe(fd);
        pid_t p = fork();
        char s[256];
        char s2[256];
        if(p>0){
                close(fd[0]);
                scanf("%s", s);
                write(fd[1], s, strlen(s)+1);
                close(fd[1]);
                wait(NULL);
        }
        if(p==0){
                close(fd[1]);
                read(fd[0], s2, 256);
                s2[0] = 'X';
                printf("%s", s2);
        }
        return 0;
}
```


## Funkcja Fork()
Funkcja fork() pozwala nam na utworzenie nowego procesu. Teraz program działa równocześnie na dwóch procesach. Przy utworzeniu, funkcja zwraca zmienną pid_t która przechowuje index procesu. Pozwala nam on zidentyfikować czy proces jest procesem rodzicem czy procesem dzieckiem. W przypadku gdy jest to proces dziecko, wartość będzie równa 0. W przypadku rodzica, wartość będzie większa niż 0. Gdy funkcja zwróci wartość mniejszą niż 0 oznacza to iż zaistniał błąd. Pozwala to na łatwe rozpoznanie w jakim procesie się znajdujemy. Trzeba pamiętać żeby przed użyciem fork() wywołać funkcje pipe().


## Funkcja Pipe()
Funkcja pipe() pozwala nam utworzyć kanał komunikacyjny między procesami. Tworzony jest jednokierunkowy strumień danych, w którym jeden koniec służy do zapisu, a drugi do odczytu. Funkcja zapisuje deskryptory tych dwóch końców w tablicy typu int, dzięki czemu procesy mogą korzystać z nich jak ze zwykłych plików. Jeśli proces zapisze dane na końcu do zapisu, drugi proces może je odczytać na końcu do odczytu. Gdy pipe() zwróci wartość mniejszą niż 0, oznacza to błąd utworzenia potoku. Mechanizm ten umożliwia prostą komunikację między procesami powstałymi np. po wywołaniu fork().

## Funkcja Wait()
Funkcja wait(NULL) sprawia, że proces rodzic czeka na zakończenie reszty procesów. NULL oznacza, że nie chcemy zapisywać informacji zwrotnej o zakończeniu procesu dziecka.

## Wnioski
Laboratorium pozwoliło na praktyczne zrozumienie mechanizmów tworzenia procesów i komunikacji międzyprocesowej w systemach Linux. Dzięki fork() i pipe() możliwe jest równoległe wykonywanie zadań oraz przesyłanie danych między procesami.
