#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Ex_2.h"

int compare(AirportCode a,AirportCode b)
{
  return (strcmp(a,b) == 0)? 0:1;
}

void addL(stp current,AirportCode item)
{
  /**/if(strcmp(current->air,"NULL") == 0){
      strcpy(current->air,item);
  }
  else {
      stp temp = malloc(sizeof(str));
      temp->next = current->next;
      current->next = malloc(sizeof(str));
      current->next->next = temp->next;
      current->next->previous = current ;
      strcpy(current->next->air,item);
      current->next->next->previous = current->next;
  }
  /**/
}

dms Create()
{
  dms new;
  new.first = malloc(sizeof(str));
  new.last = malloc(sizeof(str));
  new.first->next= malloc(sizeof(str));
  strcpy(new.first->next->air,"NULL");
  new.first->next->previous = new.first;
  new.first->next->next = new.last;
  new.last->previous = new.first->next;
  new.first->previous = NULL;
  new.last->next = NULL;
  strcpy(new.first->air,"FNULL");
  strcpy(new.last->air,"LNULL");
  return new;
}

stp Search(stp begin_L,AirportCode item,CompareType COMP)
{
  if(COMP(begin_L->air,item) == 0) return begin_L;
  if(begin_L->next != NULL) return Search(begin_L->next,item,COMP);
  if(begin_L->next == NULL) return NULL;
}

void InsertLast(stp last,AirportCode item)
{
  addL(last,item);
}

void InsertBefore(stp begin_L,AirportCode item,stp before)
{
  /**/if(before == NULL){
      printf("Airport code wasn't found\n");
  }
  else {
      addL(before->previous,item);
  }
  /**/
}

void InsertAfter(stp begin_L,AirportCode item,stp after)
{
  /**/if(after == NULL){
      printf("Airport code wasn't found\n");
  }
  else {
      addL(after,item);
  }
  /**/
}

void Delete(stp begin_L,stp current)
{
  stp CR = Search(begin_L,current->air,compare);
  CR->previous->next = CR->next;
  CR->next->previous = CR->previous;
  free(CR);
}

void DeleteLast(stp last)
{
  last->previous->next = last->next;
  last->next->previous = last->previous;
  free(last);
}

void Print(stp begin_L,char *format)
{
    printf("\nPrint: (");
    printf(format,begin_L->air);
    begin_L = begin_L->next;
    /**/while(begin_L->next != NULL){
        printf(",");
        printf(format,begin_L->air);
        begin_L = begin_L->next;
    }
    /**/
    printf(")\n");
}
