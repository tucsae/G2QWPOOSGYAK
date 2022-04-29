#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>
#define PIPE_NAME "G2QWPO"
#define MSIZE 128
int main()
{
char inBuffer[MSIZE];
int nbytes, fd;
int pid;
const void* input="Tucsa Eszter";



if(mkfifo(PIPE_NAME,0666)<0)
{
    perror("mkfifo\n");
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
    fd=open(PIPE_NAME, O_WRONLY);
    write(fd, input, MSIZE);
    printf("Child: sikeresen belefirkáltam a pipe-ba!\n");
    close(fd);
}
else if(pid>0)
{
    fd=open(PIPE_NAME, O_RDONLY);

    wait(NULL);
    printf("Parent: vettem-vettem, olvassam csak ki!\n");

    read(fd, inBuffer, MSIZE);
    close(fd);
    printf("Ezt olvastam ki: %s\n", inBuffer);
    printf("Parent jelenti: kész!\n");

}
    scanf("%d alahogy meg kell allirani a programot, mert kilep magatol es nem latni csak igy:(",nbytes);
    return 0;
}
