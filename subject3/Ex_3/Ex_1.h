#include "Ex_1_Types.h"
#define RIGHT 1
#define LEFT 0
#define TRUE 1
#define FALSE 0
#define maxelem 15
#define VNULL -3793

BTNode BTGetRoot(BTTree tree);
BTTree BTCreate(int Melem);
int BTHeight(BTTree tree);
int MaxHeight(BTNode Nnode);
int BTSize(BTTree tree);
int NSize(BTNode Nnode);
BTNode SearchBTNodeParent(BTNode Fnode,BTNode Cnode);
BTNode SearchItemsBTNode(BTNode Cnode,BTItem item);
BTNode BTGetParent(BTTree tree,BTNode Cnode);
BTNode BTGetChildLeft(BTTree tree,BTNode Cnode);
BTNode BTGetChildRight(BTTree tree,BTNode Cnode);
int BTIsNil(BTNode Cnode);
BTItem BTGetItem(BTTree tree,BTNode Cnode);
void BTInsertRoot(BTTree tree,BTItem item);
void BTInsertLeft(BTTree tree,BTNode node,BTItem item);
void BTInsertRight(BTTree tree,BTNode node,BTItem item);
void BTInsertNode(BTNode node,int Drc,BTItem item);
void BTPrintLevel(BTNode Cnode,int height);
void BTPrint(BTTree tree);
void BTRemove(BTTree tree,BTNode node);
void BTChange(BTTree tree,BTNode node,BTItem item);
void DeleteTree(BTTree tree,BTNode Cnode);
void BTDestroy(BTTree *tree);
void PrintOrder(BTTree tree);
