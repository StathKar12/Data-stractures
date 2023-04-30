#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Ex_1.h"

int main(void)
{
    printf("Creating a new list using Create");
    stp begin = Create();
    Print(begin);
    printf("Inseting AAA using InserLast");
    InsertLast(begin,"AAA");
    Print(begin);
    printf("Inseting DDD using InserLast");
    InsertLast(begin,"DDD");
    Print(begin);
    printf("Adding CCC after AAA using InsertAfter");
    stp node = Search(begin,"AAA");
    InsertAfter(begin,"CCC",node);
    Print(begin);
    printf("Calling DeleteLast");
    DeleteLast(begin);
    Print(begin);
    return 0;
}
