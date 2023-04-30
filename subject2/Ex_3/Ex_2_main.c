#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxelem 20
#include "Ex_2.h"

int main(void)
{
    printf("Creating empty tree using ADTCreate function:\n");
    ADTTree tree = ADTCreate(maxelem);
    ADTPrint(tree);
    ADTNode N = ADTGetRoot(tree);
    printf("\nroot = %d",N);
    printf("\nFilling tree's root with value '10' using ADTInsertRoot function:");
    ADTInsertRoot(tree,10);
    ADTPrint(tree);
    printf("\nFilling the tree using the functions ADTInsertLeft ADTInsertRight:");
    N = SearchItemsADTNode(tree,10);
    ADTInsertLeft(tree,N,5);
    ADTInsertRight(tree,N,7);
    N = SearchItemsADTNode(tree,5);
    ADTInsertLeft(tree,N,6);
    ADTInsertRight(tree,N,8);
    N = SearchItemsADTNode(tree,7);
    ADTInsertLeft(tree,N,12);
    ADTInsertRight(tree,N,15);
    N = SearchItemsADTNode(tree,12);
    ADTInsertLeft(tree,N,13);
    ADTInsertRight(tree,N,14);
    N = SearchItemsADTNode(tree,15);
    ADTInsertLeft(tree,N,16);
    ADTInsertRight(tree,N,17);
    N = SearchItemsADTNode(tree,6);
    ADTInsertLeft(tree,N,7);
    ADTInsertRight(tree,N,4);
    N = SearchItemsADTNode(tree,8);
    ADTInsertLeft(tree,N,9);
    ADTInsertRight(tree,N,3);
    ADTPrint(tree);
    int height = ADTHeight(tree);
    int ADTsize = ADTSize(tree);
    printf("\nsize = %d,height = %d\n",ADTsize,height);
    ADTNode RMV = SearchItemsADTNode(tree,17);
    printf("\nRemoving from the tree the value 17 using ADTRemove function:");
    ADTRemove(tree,RMV);
    ADTPrint(tree);
    N = SearchItemsADTNode(tree,15);
    ADTInsertRight(tree,N,20);
    printf("\nAdding value '20' using ADTInsertRight:");
    ADTPrint(tree);
    ADTNode CHN = SearchItemsADTNode(tree,7);
    ADTChange(tree,CHN,36);
    printf("\nChanging the value '7' to '36' using the function ADTChange:");
    ADTPrint(tree);
    PrintOrder(tree);
    printf("\nDeleting the tree using function ADTDestroy...");
    ADTDestroy(tree);
    printf("\n...ALL  GOOD...\n");
    return 0;
}
