#include <stdio.h>
#include <stdlib.h>
#include "Ex_3.h"


int main(void)
{
    PList beginA = Create();
    InsertLast(beginA,1);
    InsertLast(beginA,3);
    InsertLast(beginA,5);
    InsertLast(beginA,7);
    InsertLast(beginA,9);
    InsertLast(beginA,11);
    InsertLast(beginA,13);
    InsertLast(beginA,15);
    InsertLast(beginA,17);
    InsertLast(beginA,19);
    InsertLast(beginA,21);
    printf("List A:");
    Print(beginA);
    PList beginB = Create();
    InsertLast(beginB,2);
    InsertLast(beginB,4);
    InsertLast(beginB,6);
    InsertLast(beginB,8);
    InsertLast(beginB,10);
    InsertLast(beginB,12);
    InsertLast(beginB,14);
    InsertLast(beginB,16);
    InsertLast(beginB,18);
    InsertLast(beginB,20);
    InsertLast(beginB,22);
    printf("List B:");
    Print(beginB);
    PList Both_AB =  UniteL(beginB,beginA);
    Print(Both_AB);
    return 0;
}
