#ifndef CHILD_H
#define CHILD_H
#include <semaphore.h>
void server(char *ptr, sem_t *sem_write, sem_t *sem_read);

#endif
