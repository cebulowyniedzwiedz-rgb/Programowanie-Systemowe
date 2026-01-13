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
