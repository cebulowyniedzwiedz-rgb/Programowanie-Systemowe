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
