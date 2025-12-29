#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
void worker(int fd, int fd1) {
        char s[256];
        while(1){
                scanf("%s", s);
                write(fd, s, strlen(s)+1);
                if(strcmp(s,"exit")==0){
                        break;
                }
                read(fd1, s, 256);
                printf("%s", s);
        }
        wait(NULL);
}
