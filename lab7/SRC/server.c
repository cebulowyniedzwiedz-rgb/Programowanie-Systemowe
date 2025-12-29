#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
void server(int fd,int fd1){
        char s2[256];
        while(1){
                read(fd, s2, 256);
                if(strcmp(s2,"exit")==0){
                        break;
                }
                s2[0] = 'X';
                write(fd1, s2, strlen(s2)+1);
        }
}
