#include "Ex_2_Types.h"
#define EMPTY 0
#define NOT_EMPTY 1
#define RIGHT(n) 2*n+1
#define LEFT(n) 2*n
#define PAR(n) n/2
#define TRUE 1
#define FALSE 0
#define VNULL -1

int ADTIsNil(ADTTree Cnode,ADTNode n);
ADTTree ADTCreate(int Melem);
int MaxHeight(ADTTree Nnode,int n);
int ADTHeight(ADTTree tree);
void ADTPrintLevel(ADTTree Cnode,int n,int height);
void ADTPrint(ADTTree tree);
int NSize(ADTTree Nnode,int n);
int ADTSize(ADTTree tree);
ADTNode ADTGetRoot(ADTTree tree);
ADTNode ADTGetParent(ADTTree tree,ADTNode n);
ADTNode ADTGetChildLeft(ADTTree tree,ADTNode n);
ADTNode ADTGetChildRight(ADTTree tree,ADTNode n);
ADTItem ADTGetItem(ADTTree tree,ADTNode n);
void ADTInsertRoot(ADTTree tree,ADTItem item);
void ADTInsertLeft(ADTTree tree,ADTNode n,ADTItem item);
void ADTInsertRight(ADTTree tree,ADTNode n,ADTItem item);
void ADTRemove(ADTTree tree,ADTNode n);
void ADTChange(ADTTree tree,ADTNode n,ADTItem item);
void ADTDestroy(ADTTree tree);
void Visit(ADTItem item);
void ADTPreOrder(ADTTree tree,ADTNode n,void (*Visit)(int item));
void ADTInOrder(ADTTree tree,ADTNode n,void (*Visit)(int item));
void ADTPostOrder(ADTTree tree,ADTNode n,void (*Visit)(int item));
void PrintOrder(ADTTree tree);
ADTNode SearchItemsADTNode(ADTTree tree,ADTItem item);
