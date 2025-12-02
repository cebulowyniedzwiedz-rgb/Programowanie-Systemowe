# SPRAWOZDANIE - Laboratorium 6
Sprawozdanie wykonane przez Pawła Rumpla o numerze indeksu 283849 z kierunku Cyberbezpieczeństwo, drugi rok, trzeci semestr. Sprawozdanie dotyczy czwartych laboratoriów z przedmiotu Programowanie systemowe. Laboratorium to polegało na dalszym zapoznaniu się z funkcjami fork() i pipe() w języku C. Zajęcia były przeprowadzone na komputerach z systemem Linux w sali laboratoryjnej 127L w budynku C-3. Laboratorium zostało wykonane w dniu 26 listopada 2025 roku.

## Założenia działania programu
Program ma się składać z osobnych plików Worker i Serwer. Jeden z nich ma być operowany przez rodzica a drugi przez proces dziecko. Ma w nich następować pętla które powoduje, że użytkownik może bez końca wpisywać słowo by dostać to samo słowo z zmienioną pierwszą literą. By zakończyć program należy wpisać "exit". Main.c posiada dwie zmienne odpowiadające za obsługe dwóch pipe'ów. Jeden pipe służy do przesyłania rzeczy z rodzica do dziecka a drugi do procesu przeciwnego. Obie te zmienne są przekazywane jako wartości dla funkcji worker() i server(). 

## Worker (PARENT)
Worker miał być rodzicem i odpowiadać za pobranie od użytkownika ciągu znaków oraz później zwróceniu zeedytowanego przez Serwer ciągu znaków. Miał on działać w pętli nieprzerwanie do momentu gdy ciąg znaków będzie wynosił "exit". Wysyła on dane w pipe fd a odbiera w pipe fd1. Poniżej zamieszczam zawartość plików worker.h oraz worker.c.

### worker.h:
```c                                       
#ifndef PARENT_H
#define PARENT_H

void worker(int fd[2], int fd1[2]);

#endif


```

### worker.c:
```c                                                                            
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
void worker(int fd[2], int fd1[2]) {
        char s[256];
        close(fd1[1]);
        close(fd[0]);
        while(1){
                scanf("%s", s);
                write(fd[1], s, strlen(s)+1);
                if(strcmp(s,"exit")==0){
                        break;
                }
                read(fd1[0], s, 256);
                printf("%s", s);
        }
        close(fd[1]);
        close(fd1[0]);
        wait(NULL);
}

```

## Server (CHILD)
Worker miał być dzieckiem i odpowiadać za edycje ciągu znaków przekazanego do niego od rodzica. Miał on działać w pętli nieprzerwanie do momentu gdy ciąg znaków będzie wynosił "exit". Wysyła on dane w pipe fd1 a odbiera w pipe fd. Poniżej zamieszczam zawartość plików server.h oraz server.c.

### server.h:
```c
#ifndef CHILD_H
#define CHILD_H

void server(int fd[2], int fd1[2]);

#endif
```

### server.c:
```c                                           
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
void server(int fd[2],int fd1[2]){
        char s2[256];
        close(fd[1]);
        close(fd1[0]);
        while(1){
                read(fd[0], s2, 256);
                if(strcmp(s2,"exit")==0){
                        break;
                }
                s2[0] = 'X';
                write(fd1[1], s2, strlen(s2)+1);
        }
        close(fd[0]);
        close(fd1[1]);
}
```

## Plik main.c
W pliku main.c obsługujemy obie wcześniej stworzone funkcje oraz tworzymy dwie zmienne fd i fd1. Odpowiadają one za poprawne działanie pipe'ów. Poniżej zamieszczam zawartość pliku main.c.

### main.c:
```c
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

#include "server.h"
#include "worker.h"

int main(){
        int fd[2];
        int fd1[2];

        pipe(fd);
        pipe(fd1);
        pid_t p = fork();

        if (p > 0) {
                worker(fd, fd1);
        }
        if (p==0) {
                server(fd, fd1);
        }
        return 0;
}
```

