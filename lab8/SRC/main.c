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
