#include "Ex_1_Types.h"

void addL(stp current,char item[10]);
stp Create();
stp Search(stp begin,char item[10]);
void InsertLast(stp begin,char item[10]);
void InsertAfter(stp begin,char item[10],stp after);
void Delete(stp begin,stp current);
void DeleteLast(stp begin);
void Print(stp begin);
