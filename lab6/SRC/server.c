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
