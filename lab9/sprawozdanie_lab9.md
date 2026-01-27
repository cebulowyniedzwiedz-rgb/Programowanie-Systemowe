# SPRAWOZDANIE - Laboratorium 9
Sprawozdanie wykonane przez Pawła Rumpla o numerze indeksu 283849 z kierunku Cyberbezpieczeństwo, drugi rok, trzeci semestr. Sprawozdanie dotyczy dziewiątych laboratoriów z przedmiotu Programowanie systemowe. Laboratorium to polegało na zapoznaniu się z wątkami i komunikacją sieciową. Zajęcia były przeprowadzone na komputerach z systemem Linux w sali laboratoryjnej 127L w budynku C-3. Laboratorium zostało wykonane w dniu 14 stycznia 2026 roku.

## Założenie działania programu
Program tak jak poprzednio ma przyjmować jeden na wejściu jakiś ciąg znaków i zamieniać pierwszą litere na 'X'. W tym przypadku trzeba użyć wątków i komunikacji sieciowej. Oprócz tego użyłem pipeów do komunikacji. Użyłem też mutexów do organizacji oraz użyłem inetd do łatwiejszej komunikacji sieciowej.

## Inetd i komunikacja sieciowa
netd jest to standardowy demon systemowy . Działa on w ten sposób, że nasłuchuje na porcie i po nawiązaniu połączenia uruchamia wskazany program, przesyłając do niego jako standardowe wejście dane z danego socketu, a wszystkie dane ze standardowego wyjścia również wysyła na socket. Działam na porcie 8080 i używam program w pythonie jako mojego klienta sieciowego. Warto wspomnieć, że wymagana jest konfiguracja Inetd. Trzeba się upewnić czy jest obecne na komputerze a potem trzeba utworzyć plik konfiguracyjny. Znajdować się powinien w /etc/xinetd.d/"nazwa_pliku_konfiguracyjnego_ktory_stworzymy". Ten plik powinien wyglądać podobnie jak poniżej:

### Plik /etc/xinetd.d/main
```
service main
{
    type        = UNLISTED
    port        = 8080
    socket_type = stream
    protocol    = tcp
    wait        = no
    user        = vagrant #Tutaj nazwa uzytkownika
    server      = /home/vagrant/PSYS-mojewlasne/Programowanie-Systemowe/lab9/build/main #tutaj dokładna ścieżka do pliku naszego programu
    disable     = no
}

```
## Wątki 
Wątki działają w ten sposób, że pozwalają wykonywać wiele zadań jednocześnie w ramach jednego procesu, współdzieląc przy tym tę samą pamięć i zmienne globalne. Worker działa jako wątek, przyjmuje on zmienną arg która posiada inne zmienne takie jak fd i fd1 odpowiadające za działanie pipeów. Dlatego zmieniamy mocno zarówno plik worker.c jak i worker.h.

### main.c
```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include "server.h"
#include "worker.h"

int main() {
    pthread_t t;
    int fd1[2], fd2[2];

    if (pipe(fd1) == -1 || pipe(fd2) == -1) {
        return 1;
    }

    WorkerArgs* args = malloc(sizeof(WorkerArgs));
    if (!args) return 1;

    args->read_fd = fd1[0];
    args->write_fd = fd2[1];

    if (pthread_create(&t, NULL, worker, args) != 0) {
        free(args);
        return 1;
    }

    server(fd1[1], fd2[0]);

    close(fd1[1]);
    close(fd2[0]);
    pthread_join(t, NULL);
    close(fd1[0]);
    close(fd2[1]);

    return 0;
}
```
### server.c
```c
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "server.h"

void server(int write_fd, int read_fd) {
    char buffer[256];
    char result[256];
    int n;

    while (1) {
        memset(buffer, 0, sizeof(buffer));
        
        n = read(0, buffer, 255);
        if (n <= 0) break;

        write(write_fd, buffer, strlen(buffer) + 1);

        if (strcmp(buffer, "exit") == 0) break;

        read(read_fd, result, 256);

        write(1, result, strlen(result));
    }
}
```
### worker.c
```c
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "worker.h"

void* worker(void* arg) {
    WorkerArgs* args = (WorkerArgs*)arg;
    int in_fd = args->read_fd;
    int out_fd = args->write_fd;
    
    free(args);

    char input[256];

    while (1) {
        int n = read(in_fd, input, 256);
        if (n <= 0) break;

        if (strcmp(input, "exit") == 0) break;

        if (strlen(input) > 0) {
            input[0] = 'X';
        }

        write(out_fd, input, strlen(input) + 1);
    }
    return NULL;
}
```
### worker.h
```c
#ifndef WORKER_H
#define WORKER_H

typedef struct {
    int read_fd;
    int write_fd;
} WorkerArgs;

void* worker(void* arg);

#endif
```
### server.h
```c
#ifndef SERVER_H
#define SERVER_H

void server(int write_fd, int read_fd);

#endif
```
## Client w Pythonie
Poniżej przedstawiam kod clienta napisanego w pythonie użytego do komunikacji:
### client_sieciowy.py
```py
import socket

s = socket.socket()
s.connect(('127.0.0.1', 8080))

while True:
    try:
        msg = input()
        s.send(msg.encode())
        if msg == 'exit': break
        print(s.recv(1024).decode())
    except (EOFError, KeyboardInterrupt):
        break

s.close()
```
