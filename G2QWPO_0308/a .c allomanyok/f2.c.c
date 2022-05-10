#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main()
{
    printf("write a command\n");
    char cmd[3][4]={{"pwd"},{"date"},{"who"}};
    char ycmd[4];
    bool k=true;

    do
    {
        scanf("%s", ycmd);
        if(strcmp(ycmd, cmd[1])==0 || strcmp(ycmd, cmd[2])==0 || strcmp(ycmd, cmd[3])==0)
        {

        }
        else
        {
            k=false;
            printf("rossz command\n");
            fflush(stdin);
        }
    }while(!k);

    system(ycmd);
    return 0;
}
