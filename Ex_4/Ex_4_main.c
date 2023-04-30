#include <stdio.h>
#include <stdlib.h>
#include "Ex_4.h"

int main(void)
{
    PList beginA = Create();
    InsertLast(beginA,5);
    InsertLast(beginA,25);
    InsertLast(beginA,10);
    InsertLast(beginA,20);
    InsertLast(beginA,15);
    InsertLast(beginA,15);
    InsertLast(beginA,20);
    InsertLast(beginA,10);
    InsertLast(beginA,25);
    InsertLast(beginA,5);
    InsertLast(beginA,30);
    printf("List A:");
    Print(beginA);
    PList Both_AB =  Unite_L(beginA,NULL);
    Print(Both_AB);
    return 0;
}
