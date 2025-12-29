#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

#include "server.h"
#include "worker.h"

int main(){
        int fd[2];
        int fd1[2];

        pipe(fd);
        pipe(fd1);
        pid_t p = fork();

        if (p > 0) {
                worker(fd, fd1);
        }
        if (p==0) {
                server(fd, fd1);
        }
        return 0;
}
