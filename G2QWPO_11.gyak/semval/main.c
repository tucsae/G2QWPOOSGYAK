#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <unistd.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <string.h>
#include <pthread.h>
int main()
{
    sem_t sem;
    int semval;
    sem_getvalue(&sem,&semval);
    printf("Szemafor erteke: %d", semval);
    return 0;
}
