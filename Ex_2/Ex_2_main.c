#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Ex_2.h"

int main(void)
{
  printf("\nCreating a new list using Create");
  dms begin_L = Create();
  Print(begin_L.first->next,"%s");
  printf("\nInserting AAA using InsertLast");
  InsertLast(begin_L.last->previous,"AAA");
  Print(begin_L.first->next,"%s");
  printf("\nAdding BBB at the beginning using InsertBefore");
  stp node = Search(begin_L.first->next,"AAA",compare);
  InsertBefore(begin_L.first->next,"BBB",node);
  Print(begin_L.first->next,"%s");
  printf("\nAdding CCC using InsertLast");
  InsertLast(begin_L.last->previous,"CCC");
  Print(begin_L.first->next,"%s");
  printf("\nAdding DDD after AAA using InsertAfter");
  node = Search(begin_L.first->next,"AAA",compare);
  InsertAfter(begin_L.last->previous,"DDD",node);
  Print(begin_L.first->next,"%s");
  printf("\nCalling DeleteLast");
  DeleteLast(begin_L.last->previous);
  Print(begin_L.first->next,"%s");
  free(node);
  return 0;
}
