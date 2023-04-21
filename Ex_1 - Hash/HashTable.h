#include "HashTable_Types.h"

HTHash HTCreate();
int HTSize(HTHash hash);
int HashF(HTHash* hash,HKey key);
HTIList SearchForKey(HTIList List,HKey key);
int HTGet(HTHash hash,HKey key,HTItemPtr pitem);
void InsertNode(HTIList *Cnode,HKey key,HTItem item);
void HTInsert(HTHashPtr hash,HKey key,HTItem item);
void HTPrint(HTHash hash,Print PRT);
void HTRemove(HTHash hash,HKey key);
void RemoveNode(HTIList *Cnode,HTIList Rnode);
void DestroyNode(HTIList Cnode);
void HTDestroy(HTHash hash);
void print_INT(HTIList Cnode);
void print_CHAR(HTIList Cnode);
void print_FLOAT(HTIList Cnode);
void print_DOUBLE(HTIList Cnode);
HTHash HTUpgradeHash(HTHash hash);
void HTVisit(HTHash hash,Visit vst);
void Visit_node(HTHash hash,HTIList Cnode,Visit vst);
int int_CMP(HTItem item,int num);
int double_CMP(HTItem item,double num);
int string_CMP(HTItem item,char *str);
double Get_Double(HTItem item);
char *Get_String(HTItem item);
int Get_Int(HTItem item);
