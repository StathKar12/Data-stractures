#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NONE 0
#include "Ex_3.h"

void addL(PList current,int item)
{
    /**/if(current->code == NONE){
        current->code = item;
    }
    else {
        PList temp = malloc(sizeof(Lnode));
        temp->next = current->next;
        current->next = malloc(sizeof(Lnode));
        current->next->next = temp->next;
        current->next->code = item ;
    }
    /**/
}

PList Create()
{
    PList newl = malloc(sizeof(Lnode));
    newl->next = NULL;
    newl->code = NONE;
    return newl;
}

void InsertLast(PList begin,int item)
{
    /**/while(begin->next != NULL){
        begin = begin->next;
    }
    /**/
    addL(begin,item);
}


void Print(PList begin)
{
    printf("\nPrint: ( %d ",begin->code);
    begin = begin->next;
    /**/while(begin != NULL){
        printf(", %d ",begin->code);
        begin = begin->next;
    }
    /**/
    printf(")\n");
}

//Ex_3:      #######################################
PList UniteL(PList List_L,PList ListB)
{
    PList current = List_L;
    /**/while(current->next != NULL){
        current = current->next;
    }
    /**/
    current->next = ListB;
    int temp;
    current = List_L;
    /**/while(current->next != NULL){
        /**/if(current->code > current->next->code){
            temp = current->next->code;
            current->next->code = current->code;
            current->code = temp;
            current = List_L;
            continue;
        }
        current = current->next;
    }
    /**/
    return List_L;
}
//#######################################      :Ex_3
