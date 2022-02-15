/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE* fp;
    
    fp=fopen("vezeteknev.txt","w+");
    fprintf(fp,"Tucsa Eszter Boglarka\nMernokinformatikus Bsc\nG2QWPO\n");
    
    fclose(fp);

    return 0;
}
