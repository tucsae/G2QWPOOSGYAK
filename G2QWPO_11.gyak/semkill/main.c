#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <unistd.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <string.h>
#include <pthread.h>
#define N 10

int main()
{
    //sem_t* sems[N];
    sem_t* sekesz[N];
    int i;
    int* val[N];
    for(i=0;i<N;i++)
    {
        if(i%2==0)
        {
            sem_init(&sekesz[i], 0, 1);
        }
        else
        {
            sem_init(&sekesz[i], 0, 0);
        }
        sem_getvalue(&sekesz[i],&val[i]);
        printf("I iz szemafor %d 's ertek: %d\n",i+1,&val[i]);
    }
    printf("\nEs most kinyirjuk szegenykeket\n");
    for(i=0;i<N;i++)
    {
        printf("szemafor %d a %d ertekkel: o no *insert scared cat meme*\n",i+1, &val[i]);
        sem_destroy(&sekesz[i]);
    }
    return 0;
}
