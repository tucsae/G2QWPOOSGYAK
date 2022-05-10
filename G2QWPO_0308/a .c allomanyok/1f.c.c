#include <stdio.h>
#include <stdlib.h>

int main()
{
    if(system("dir"))
    {
        for(int i=0; i<3; i++)
        {
            printf("KORTE\n");
        }
    }
    system("color a"); //dir cmd elott szin megvaltozott
    system("nincs ilyen parancs"); //rendszertol hiba
    return 0;
}
