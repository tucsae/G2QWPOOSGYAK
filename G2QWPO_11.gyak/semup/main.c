#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <unistd.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <string.h>
#include <pthread.h>
#include <sys/sem.h>
#define KEY 0x1111
union semun
{
    int val;
    struct semid_ds *buf;
    unsigned short *arr;
};

int main()
{
    int semid, res;
    struct sembuf sembuf,p;
    sembuf.sem_op=1;
    p.sem_op=1;

    semid=semget(KEY,1,0600|IPC_CREAT);
    printf("%d\n",semid);
    union semun u;
    u.val=1;
    semctl(semid, 0, SETVAL,u);
    res=semop(semid,&sembuf, 1);
    printf("inkrementalas eredmenye: %d",res);
    return 0;
}
