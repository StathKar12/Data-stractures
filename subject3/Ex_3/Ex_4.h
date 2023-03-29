#include "Ex_4_Types.h"
#define RIGHT 1
#define LEFT 0
#define TRUE 1
#define FALSE 0
#define maxelem 15
#define VNULL -3793

CBTNode CBTGetRoot(CBTTree tree);
CBTTree CBTCreate(int Melem);
int CBTHeight(CBTTree tree);
int MaxHeight(CBTNode Nnode);
int CBTSize(CBTTree tree);
int NSize(CBTNode Nnode);
CBTNode SearchCBTNodeParent(CBTNode Fnode,CBTNode Cnode);
CBTNode SearchItemsCBTNode(CBTNode Cnode,CBTItem item);
CBTNode CBTGetParent(CBTTree tree,CBTNode Cnode);
CBTNode CBTGetChildLeft(CBTTree tree,CBTNode Cnode);
CBTNode CBTGetChildRight(CBTTree tree,CBTNode Cnode);
int CBTIsNil(CBTNode Cnode);
CBTItem CBTGetItem(CBTTree tree,CBTNode Cnode);
void CBTInsertNode(CBTNode node,CBTItem item);
void CBTPrintLevel(CBTNode Cnode,int height);
void CBTPrint(CBTTree tree);
void CBTRemove(CBTTree tree,CBTNode node);
void CBTChange(CBTTree tree,CBTNode node,CBTItem item);
void DeleteTree(CBTTree tree,CBTNode Cnode);
void CBTDestroy(CBTTree *tree);
void PrintOrder(CBTTree tree);
CBTNode GetLast(CBTNode Cnode,int height);
CBTNode CBTGetLast(CBTTree tree);
CBTNode GetNext(CBTNode Cnode,CBTNode Lnode_P,CBTNode found,int height);
CBTNode GetFirstOfLastLine(CBTNode Cnode);
int IsLastOfLine(CBTNode Cnode,CBTNode Lnode);
void CBTInsertLast(CBTTree tree,CBTItem item);
void CBTRemoveLast(CBTTree tree);
