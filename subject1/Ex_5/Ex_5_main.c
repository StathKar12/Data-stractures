#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Ex_5.h"
#define L_FILE "words"

int main(void)
{
    WordS *library = ReadFile(L_FILE);
    //Print_LiB(library);
    qsort(library,Vsize,sizeof(WordS),compare);
    //Print_LiB(library);
    WordS word = malloc(sizeof(WordS));
    strcpy(word,"art");
    Similar(word,library);
    return 0;
}
