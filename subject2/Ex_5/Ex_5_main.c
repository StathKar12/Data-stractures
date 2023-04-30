#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Ex_5.h"

int main(void)
{
    printf("In this test items and priorities have the same values...\n\n");
    printf("\nCreating a Heap and filling it with BHInsert which uses heapify_up algorithm:\nFirst Heap:\n");
    Heap Hhead = BHCreate(15);
    BHInsert(Hhead,2,2);
    BHInsert(Hhead,4,4);
    BHInsert(Hhead,5,5);
    BHInsert(Hhead,7,7);
    BHInsert(Hhead,3,3);
    BHInsert(Hhead,10,10);
    BHInsert(Hhead,8,8);
    BHInsert(Hhead,1,1);
    BHInsert(Hhead,9,9);
    BHInsert(Hhead,6,6);
    BHInsert(Hhead,15,15);
    BHInsert(Hhead,12,12);
    BHPrint(Hhead);
    printf("^^^The highest priority in the First Heap is: %d\n",BHGetMaxPriority(Hhead));
    printf("^^^The item with the highest priority in the First Heap is: %d\n",BHGetMaxItem(Hhead));
    printf("^^^Removing the item with the highest priority in the First Heap using the BHRemove function:\n");
    BHRemove(Hhead);
    BHPrint(Hhead);
    printf("\nCreating a Heap and filling it with BHInsertLast which doesn't use heapify_up algorithm:\nSecond Heap:\n");
    Heap Hhead_B = BHCreate(15);
    BHInsertLast(Hhead_B,2,2);
    BHInsertLast(Hhead_B,4,4);
    BHInsertLast(Hhead_B,5,5);
    BHInsertLast(Hhead_B,7,7);
    BHInsertLast(Hhead_B,3,3);
    BHInsertLast(Hhead_B,10,10);
    BHInsertLast(Hhead_B,8,8);
    BHInsertLast(Hhead_B,1,1);
    BHInsertLast(Hhead_B,9,9);
    BHInsertLast(Hhead_B,6,6);
    BHPrint(Hhead_B);
    printf("^^^The highest priority in the Second Heap is: %d\n",BHGetMaxPriority(Hhead_B));
    printf("^^^The item with the highest priority in the Second Heap is: %d\n",BHGetMaxItem(Hhead_B));
    printf("\nCreating a heapified version of Second Heap using BHHeapify function:\n");
    int Hsize = HeapSize(Hhead_B.Fnode);
    int *ITM = BHItems(Hhead_B);
    int *PR = BHPriorities(Hhead_B);
    Heap N_Hhead_B = BHHeapify(Hsize,PR,ITM);
    BHPrint(N_Hhead_B);
    printf("\nAdding num.15 in the Second Heap using BHInsert function which uses heapify_up algorithm:\n");
    BHInsert(N_Hhead_B,15,15);
    BHPrint(N_Hhead_B);
    printf("\nAdding num.12 in the Second Heap using BHInsert function which uses heapify_up algorithm:\n");
    BHInsert(N_Hhead_B,12,12);
    BHPrint(N_Hhead_B);
    printf("^^^Removing the item with the highest priority in the Heapified version of the Second Heap using the BHRemove function:\n");
    BHRemove(N_Hhead_B);
    BHPrint(N_Hhead_B);
    printf("\nDestroying all Heaps using the BHDestroy function\n");
    BHDestroy(&Hhead);
    BHDestroy(&Hhead_B);
    BHDestroy(&N_Hhead_B);
    BHPrint(Hhead);
    BHPrint(Hhead_B);
    BHPrint(N_Hhead_B);
    printf("\n...ALL  GOOD...\n");
    return 0;
}
