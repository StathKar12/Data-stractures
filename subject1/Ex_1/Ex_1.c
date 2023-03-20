#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Ex_1.h"

void addL(stp current,char item[10])
{
    /**/if(strcmp(current->air,"NULL") == 0){
        strcpy(current->air,item);
    }
    else {
        stp temp = malloc(sizeof(str));
        temp->next = current->next;
        current->next = malloc(sizeof(str));
        current->next->next = temp->next;
        strcpy(current->next->air,item);
    }
    /**/
}

stp Create()
{
    stp newl = malloc(sizeof(str));
    newl->next = NULL;
    strcpy(newl->air,"NULL");
    return newl;
}

stp Search(stp beginl,char item[10])
{
  if(strcmp(beginl->air,item) == 0) return beginl;
  if(beginl->next != NULL) return Search(beginl->next,item);
  if(beginl->next == NULL) return NULL;
}

void InsertLast(stp begin,char item[10])
{
    /**/while(begin->next != NULL){
        begin = begin->next;
    }
    /**/
    addL(begin,item);
}

void InsertAfter(stp begin,char item[10],stp after)
{
    /**/if(after == NULL){
        printf("Airport code wasn't found\n");
    }
    else {
        addL(after,item);
    }
    /**/
}

void Delete(stp begin,stp current)
{
    /**/while(begin->next != current){
        begin = begin->next;
    }
    /**/
    begin->next = begin->next->next;
    free(current);
}

void DeleteLast(stp begin)
{
    /**/while(begin->next->next != NULL){
        begin = begin->next;
    }
    /**/
    free(begin->next);
    begin->next = NULL;
}

void Print(stp begin)
{
    printf("\nPrint: ( %s ",begin->air);
    begin = begin->next;
    /**/while(begin != NULL){
        printf(", %s ",begin->air);
        begin = begin->next;
    }
    /**/
    printf(")\n");
}
