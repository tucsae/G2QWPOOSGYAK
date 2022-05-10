#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>

#define MSIZE 128
int main()
{
char inBuffer[MSIZE];
int p[2], nbytes,pid;
if(pipe(p)<0)
{
    perror("Pipe hiba\n");
exit(1);
}
pid=fork();
if(pid<0)
{
    exit(2);
}
if(pid==0)
{
    printf("Child: es most beleirok a pipe-ba nyehehe!\n");
    write(p[1], "XY G2QWPO", MSIZE);
    printf("Child: sikeresen belefirkáltam a pipe-ba!\n");
}
else if(pid>0)
{
    wait(NULL);
    printf("Parent: vettem-vettem, olvassam csak ki!\n");
    read(p[0], inBuffer, MSIZE);
    printf("Ezt olvastam ki: %s\n", inBuffer);
    printf("Parent jelenti: kész!\n");
}
    scanf("%d alahogy meg kell allirani a programot, mert kilep magatol es nem latni csak igy:(",nbytes);
    return 0;
}
