#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

#include "server.h"
#include "worker.h"
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <sys/wait.h>
int main(int argc, char* argv[]){
        int fd;
        int fd1;
        char * fifo_path = "/tmp/myfifo";
        char * fifo2_path = "/tmp/myfifo2";
        if (argc != 2) {
                fprintf(stderr, "Uzycie: %s <server|klient>\n", argv[0]);
                return 1;
        }
        if(strcmp(argv[1],"server")==0){
                mkfifo(fifo_path, 0666);
                mkfifo(fifo2_path, 0666);
                fd = open(fifo_path, O_WRONLY);
                fd1 = open(fifo2_path, O_RDONLY);
                worker(fd, fd1);
                close(fd);
                close(fd1);
                unlink(fifo_path);
                unlink(fifo2_path);
        }
        else if(strcmp(argv[1],"klient")==0){
                fd = open(fifo_path, O_RDONLY);
                fd1 = open(fifo2_path, O_WRONLY);
                server(fd, fd1);
                close(fd);
                close(fd1);
        }
        else {
                fprintf(stderr, "Niepoprawny argument: %s\n", argv[1]);
                return 1;
        }
        return 0;
}
