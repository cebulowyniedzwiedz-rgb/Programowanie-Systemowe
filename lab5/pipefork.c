#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
int main() {
        int fd[2];
        pipe(fd);
        pid_t p = fork();
        char s[256];
        char s2[256];
        if(p>0){
                close(fd[0]);
                scanf("%s", s);
                write(fd[1], s, strlen(s)+1);
                close(fd[1]);
                wait(NULL);
        }
        if(p==0){
                close(fd[1]);
                read(fd[0], s2, 256);
                s2[0] = 'X';
                printf("%s", s2);
        }
        return 0;
}
