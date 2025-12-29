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
