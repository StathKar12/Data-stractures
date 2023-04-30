#include "Ex_2_Types.h"

void addL(stp current,AirportCode item);
dms Create();
stp Search(stp begin_L,AirportCode item,CompareType COMP);
void InsertLast(stp last,AirportCode item);
void InsertBefore(stp begin_L,AirportCode item,stp before);
void InsertAfter(stp begin_L,AirportCode item,stp after);
void Delete(stp begin_L,stp current);
void DeleteLast(stp last);
void Print(stp begin_L,char *format);
int compare(AirportCode a,AirportCode b);
