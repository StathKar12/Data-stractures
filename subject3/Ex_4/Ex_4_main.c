#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Ex_4.h"

int main(void)
{
    printf("Creating an Empty Tree using CBTCreate:\n");
    CBTTree tree = CBTCreate(maxelem);
    CBTPrint(tree);
    CBTNode treeR = CBTGetRoot(tree);
    printf("Getting the root of the tree using the CBTGetRoot function:\n");
    printf("root = %d,  tree root= %d\n",treeR,tree.Fnode);
    printf("\nFilling the tree using CBTInsertLast function:");
    CBTInsertLast(tree,10);
    CBTInsertLast(tree,5);
    CBTInsertLast(tree,7);
    CBTInsertLast(tree,6);
    CBTInsertLast(tree,8);
    CBTInsertLast(tree,12);
    CBTInsertLast(tree,15);
    CBTInsertLast(tree,16);
    CBTInsertLast(tree,17);
    CBTInsertLast(tree,18);
    CBTInsertLast(tree,19);
    CBTInsertLast(tree,20);
    CBTInsertLast(tree,21);
    CBTInsertLast(tree,22);
    CBTInsertLast(tree,23);
    CBTInsertLast(tree,24);
    CBTInsertLast(tree,25);
    CBTInsertLast(tree,26);
    CBTInsertLast(tree,27);
    CBTInsertLast(tree,28);
    CBTInsertLast(tree,29);
    CBTInsertLast(tree,30);
    CBTInsertLast(tree,31);
    CBTInsertLast(tree,32);
    CBTInsertLast(tree,33);
    CBTInsertLast(tree,34);
    CBTInsertLast(tree,35);
    CBTInsertLast(tree,36);
    CBTInsertLast(tree,37);
    CBTInsertLast(tree,38);
    CBTInsertLast(tree,39);
    CBTPrint(tree);
    printf("\nRemoving from the tree the Last value using CBTRemoveLast function:");
    CBTRemoveLast(tree);
    CBTPrint(tree);
    printf("\nAdding the value '50' to the tree using CBTInsertLast function:");
    CBTInsertLast(tree,50);
    CBTPrint(tree);
    printf("\nChanging the value '7' to '36' using the function CBTChange:");
    CBTNode CHN = SearchItemsCBTNode(tree.Fnode,7);
    CBTChange(tree,CHN,36);
    CBTPrint(tree);
    PrintOrder(tree);
    CBTNode FND = CBTGetLast(tree);
    printf("\n\nTree's last value is %d\n\n",FND->item);
    printf("\nRemoving from the tree the Last value using CBTRemoveLast function:");
    CBTRemoveLast(tree);
    CBTPrint(tree);
    FND = CBTGetLast(tree);
    printf("\n\nTree's last value is %d\n\n",FND->item);
    printf("\nDeleting the tree using function CBTDestroy:");
    CBTDestroy(&tree);
    CBTPrint(tree);
    printf("\n...ALL  GOOD...\n");
    return 0;
}
