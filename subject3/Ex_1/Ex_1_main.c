#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Ex_1.h"

int main(void)
{
    printf("Creating an Empty Tree using BTCreate:\n");
    BTTree tree = BTCreate(maxelem);
    BTPrint(tree);
    printf("Getting the root of the tree using the BTGetRoot function:\n");
    BTNode treeR = BTGetRoot(tree);
    printf("root = %d,  tree root= %d\n",treeR,tree.Fnode);
    printf("\nFilling tree's root with value '10'");
    BTInsertRoot(tree,10);
    BTPrint(tree);
    printf("\nAdding values 5,7,6,8,12,15 using functions BTInsertLeft BTInsertRight:");
    BTInsertLeft(tree,tree.Fnode,5);
    BTInsertRight(tree,tree.Fnode,7);
    BTInsertLeft(tree,tree.Fnode->left,6);
    BTInsertRight(tree,tree.Fnode->left,8);
    BTInsertLeft(tree,tree.Fnode->right,12);
    BTInsertRight(tree,tree.Fnode->right,15);
    BTPrint(tree);
    printf("\nRemoving from the tree the value 15 using BTRemove function:");
    BTNode RMV = SearchItemsBTNode(tree.Fnode,15);
    BTRemove(tree,RMV);
    BTPrint(tree);
    printf("\nAdding value '20' using BTInsertRight:");
    BTInsertRight(tree,tree.Fnode->right,20);
    BTPrint(tree);
    printf("\nChanging the value '7' to '36' using the function BTChange:");
    BTNode CHN = SearchItemsBTNode(tree.Fnode,7);
    BTChange(tree,CHN,36);
    BTPrint(tree);
    PrintOrder(tree);
    printf("\nDeleting the tree using function BTDestroy:");
    BTDestroy(&tree);
    BTPrint(tree);
    printf("\n...ALL  GOOD...\n");
    return 0;
}
