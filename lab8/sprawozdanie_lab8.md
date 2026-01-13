
# SPRAWOZDANIE - Laboratorium 8
Sprawozdanie wykonane przez Pawła Rumpla o numerze indeksu 283849 z kierunku Cyberbezpieczeństwo, drugi rok, trzeci semestr. Sprawozdanie dotyczy ósmych laboratoriów z przedmiotu Programowanie systemowe. Laboratorium to polegało na zapoznaniu się z shared memory i semaforami. Zajęcia były przeprowadzone na komputerach z systemem Linux w sali laboratoryjnej 127L w budynku C-3. Laboratorium zostało wykonane w dniu 17 grudnia 2025 roku.

## Założenie działanie programu
Podobnie jak w poprzednich zadaniach, program miał przyjmować dane tekstowe, zamieniać pierwszą literę, a następnie zwracać zmieniony tekst. W tym przypadku do komunikacji między dwiema instancjami tego programu używamy pamięci współdzielonej (shared memory). Pamięć współdzielona w systemie Linux to mechanizm komunikacji międzyprocesowej (IPC), który pozwala wielu procesom na dostęp do tego samego obszaru pamięci. Dzięki temu możliwa jest szybka wymiana danych bez konieczności kopiowania ich między procesami. Wymaga ona jednak odpowiedniej synchronizacji, aby uniknąć konfliktów podczas jednoczesnego dostępu. 

## Semafory
Używam semaforów do koordynacji działań pomiędzy procesami. Bez semaforów procesy wykonywałyby swoje operacje bez koordynacji i nie czekałyby na siebie. Używam dwóch semaforów: jeden do kontrolowania zapisu, a drugi do kontrolowania odczytywania danych. Semafory zapewniają synchronizację dostępu do zasobów współdzielonych, dzięki czemu zapobiegają jednoczesnemu zapisowi lub odczytowi w nieodpowiednim momencie. Pozwala to na poprawną i bezpieczną komunikację między procesami.

## Pliki server.c i worker.c
Działają podobnie jak w poprzednich zadaniach, z tą różnicą, że operują na pamięci współdzielonej (shared memory) oraz na semaforach. Przyjmują one lokalizację pamięci współdzielonej, jak również oba semafory.

### server.c:
```c
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <semaphore.h>
#include <stdlib.h>
#include <sys/wait.h>
void server(char *ptr, sem_t *sem_write, sem_t *sem_read){
        char s2[256];
        while(1){
		sem_wait(sem_read);
                strncpy(s2, ptr, sizeof(s2) - 1);
        	s2[sizeof(s2) - 1] = '\0';
                if(strcmp(s2,"exit")==0){
                        break;
                }
                s2[0] = 'X';
                strcpy(ptr,s2);
		sem_post(sem_write);
        }
}
```

### server.h:
```c
#ifndef CHILD_H
#define CHILD_H
#include <semaphore.h>
void server(char *ptr, sem_t *sem_write, sem_t *sem_read);

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
#include <semaphore.h>
void worker(char *ptr, sem_t *sem_write, sem_t *sem_read) {
        char s[256];
        while(1){
		sem_wait(sem_write);
                scanf("%s", s);
		strcpy(ptr, s);
		sem_post(sem_read);
                if(strcmp(s,"exit")==0){
                        break;
                }
		sem_wait(sem_write);
                printf("%s", ptr);
		sem_post(sem_write);
        }
}
```

### worker.h:
```c
#ifndef PARENT_H
#define PARENT_H
#include <semaphore.h>
void worker(char *ptr, sem_t *sem_write, sem_t *sem_read);

#endif
```
### main.c
```c
#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

#include "server.h"
#include "worker.h"
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <semaphore.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/mman.h>
int main(int argc, char* argv[]){
	int fd;
	sem_t *sem_write;
	sem_t *sem_read;
	const size_t size = 128;
	const char * shm_name = "/sharedmemory";
	const char * sem_write_name = "/sem_write";
	const char * sem_read_name = "/sem_read";
	if (argc != 2) {
		fprintf(stderr, "Uzycie: %s <server|klient>\n", argv[0]);
		return 1;
	}
	if(strcmp(argv[1],"server")==0){
		fd = shm_open(shm_name, O_CREAT | O_RDWR, 0666);
		ftruncate(fd,size);
		char *ptr = mmap(NULL, size, PROT_WRITE | PROT_READ, MAP_SHARED, fd, 0);
		sem_write = sem_open(sem_write_name, O_CREAT, 0666, 1);
		sem_read = sem_open(sem_read_name, O_CREAT, 0666, 0);
		worker(ptr, sem_write, sem_read);
		munmap(ptr, size);
		close(fd);
		shm_unlink(shm_name);
		sem_close(sem_write);
		sem_close(sem_read);
		sem_unlink(sem_write_name);
		sem_unlink(sem_read_name);
	}
	else if(strcmp(argv[1],"klient")==0){
		fd = shm_open(shm_name, O_RDWR, 0666);
		char *ptr = mmap(NULL, size, PROT_WRITE | PROT_READ, MAP_SHARED, fd, 0);
		sem_write = sem_open(sem_write_name, 0);
		sem_read = sem_open(sem_read_name, 0);
		server(ptr, sem_write, sem_read);
		munmap(ptr, size);
		close(fd);
		sem_close(sem_write);
		sem_close(sem_read);
	}
	else {
			fprintf(stderr, "Niepoprawny argument: %s\n", argv[1]);
			return 1;
	}
	return 0;
}
```
