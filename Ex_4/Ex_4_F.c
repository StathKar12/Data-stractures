#include <stdio.h>
#include <stdlib.h>
#include "Ex_4.h"

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
