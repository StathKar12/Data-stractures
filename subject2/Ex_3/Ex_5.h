#include "Ex_5_Types.h"
#define ITEMS 0
#define PRIORITIES 1
#define RIGHT(n) (n*2)+1
#define LEFT(n) n*2
#define TRUE 1
#define FALSE 0
#define maxelem 15
#define VNULL -3793

Heap BHCreate(int Melem);
int BHIsEmpty(Heap Hhead);
BHItem BHGetMaxItem(Heap Hhead);
BHPriority MaxPR(BHNode Cnode,BHPriority Mpriority);
BHPriority BHGetMaxPriority(Heap Hhead);
void BHSwap(BHNode Anode,BHNode Bnode);
void HeapifyUp(BHNode Cnode);
Heap FindHead(BHNode Cnode);
void FIX_NODE(BHNode Cnode);
void HeapifyDown(BHNode Cnode);
BHNode SearchItemsBHNode(BHNode Cnode,BHItem item);
BHNode SearchPRBHNode(BHNode Cnode,BHPriority priority);
BHNode SearchBHNodeParent(BHNode Cnode,BHNode Fnode);
void BHRemove(Heap Hhead);
void BHInsertNode(BHNode node,BHPriority priority,BHItem item);
void BHInsert(Heap Hhead,BHPriority priority,BHItem item);
int MaxHeight(BHNode Nnode);
void BHPrintLevel(BHNode Cnode,int height);
void BHPrint(Heap Hhead);
void BHRemoveNode(Heap Hhead,BHNode node);
void DeleteHeap(Heap Hhead,BHNode Cnode);
void BHDestroy(Heap *Hhead);
BHNode GetLast(BHNode Cnode,int height);
BHNode BHGetLast(Heap Hhead);
BHNode GetNext(BHNode Cnode,BHNode Lnode_P,BHNode found,int height);
BHNode GetFirstOfLastLine(BHNode Cnode);
int IsLastOfLine(BHNode Cnode,BHNode Lnode);
void BHInsertLast(Heap Hhead,BHPriority priority,BHItem item);
int HeapSize(BHNode Nnode);
void FIll_Array(BHNode Cnode,int **AR,int i,int type,int Hsize);
int *BHPriorities(Heap Hhead);
int *BHItems(Heap Hhead);
Heap BHHeapify(int Hsize,int *PR,int *ITM);

