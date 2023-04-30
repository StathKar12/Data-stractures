#include <stdio.h>
#include <stdlib.h>
#include "Ex_4.h"
#define NONE 0

//MERGESORT:      #######################################
PList Unite_L(PList List_L,PList ListB)
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

PList assort_L(PList List_L,PList List_E)
{
    /**/if(List_L->next != NULL){
        PList toMiddle = List_L;
        PList toEnd    = List_L;
        /**/while((toEnd->next != List_E)||(toEnd->next->next != List_E)){
            toMiddle = toMiddle->next;
            toEnd    = toEnd->next->next;
        }
        /**/
        return Unite_L((assort_L(List_L,toMiddle)),(assort_L(toMiddle,toEnd)));
    }
    /**/
    return List_L;
}
//#######################################      :MERGESORT

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
