#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>


int main()
{
    char buff[20];
    int bufflength;
    int fileDescr;
    int winfo;
    int sinfo;
    int rinfo;

    fileDescr=open("G2QWPO_openclose/G2QWPO.txt", O_RDWR);
    if (fileDescr==-1)
    {
    perror("open() hiba");
    exit(fileDescr);
    }
     printf("fileDescr erteke: %d\n",fileDescr);
     sinfo=lseek(fileDescr, 0, SEEK_SET);
    if (sinfo==-1)
    {
    perror("poz hiba");
    exit(sinfo);
    }
    printf("filepozicio erteke: %d\n",sinfo);
    printf("fileDescr erteke: %d\n",fileDescr);

    rinfo=read(fileDescr, buff, 15);

    if (rinfo==-1)
    {
    perror("read() hiba");
    exit(rinfo);
    }

    printf("A read() erteke: %d\n",rinfo);
    printf("A beolv ertek: %d\n",buff);


    strcpy(buff, "Ez egy teszt");
    bufflength=strlen(buff);
    winfo=write(fileDescr,buff,bufflength);

    if (winfo==-1)
    {
    perror("write() hiba");
    exit(winfo);
    }

    printf("A beirt byte-ok szama: %d\n",winfo);
    return 0;
}
