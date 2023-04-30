#include <stdio.h>
#include <stdlib.h>
#include "Ex_3.h"


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
