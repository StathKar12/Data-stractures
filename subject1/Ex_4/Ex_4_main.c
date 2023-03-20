#include <stdio.h>
#include <stdlib.h>
#include "Ex_4.h"

int main(void)
{
    PList beginA = Create();
    InsertLast(beginA,5);
    InsertLast(beginA,14);
    InsertLast(beginA,6);
    InsertLast(beginA,13);
    InsertLast(beginA,7);
    InsertLast(beginA,12);
    InsertLast(beginA,8);
    InsertLast(beginA,11);
    InsertLast(beginA,9);
    InsertLast(beginA,10);
    InsertLast(beginA,2);
    printf("List A:");
    Print(beginA);
    PList Both_AB =  Unite_L(beginA,NULL);
    Print(Both_AB);
    return 0;
}
