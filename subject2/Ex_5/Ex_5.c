#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Ex_5.h"

Heap BHCreate(int Melem)
{
    Heap Hhead;
    Hhead.Nnum = Melem;
    Hhead.Fnode = malloc(sizeof(BHN));
    Hhead.Fnode->left = NULL;
    Hhead.Fnode->right = NULL;
    Hhead.Fnode->item = VNULL;
    Hhead.Fnode->priority = VNULL;
    Hhead.Fnode->parent = NULL;
    return Hhead;
}

int BHIsEmpty(Heap Hhead)
{
    if(Hhead.Fnode->item == VNULL) return TRUE;
    return FALSE;
}

BHItem BHGetMaxItem(Heap Hhead)
{
    BHNode Max = SearchPRBHNode(Hhead.Fnode,BHGetMaxPriority(Hhead));
    return Max->item;
}

BHPriority MaxPR(BHNode Cnode,BHPriority Mpriority)
{
    if(Cnode->priority > Mpriority) Mpriority = Cnode->priority;
    if(Cnode->right != NULL) Mpriority = MaxPR(Cnode->right,Mpriority);
    if(Cnode->left != NULL) Mpriority = MaxPR(Cnode->left,Mpriority);
    return Mpriority;
}

BHPriority BHGetMaxPriority(Heap Hhead)
{
    return MaxPR(Hhead.Fnode,Hhead.Fnode->priority);
}

void BHSwap(BHNode Anode,BHNode Bnode)
{
    BHNode temp = malloc(sizeof(BHN));
    temp->item = Anode->item;
    Anode->item = Bnode->item;
    Bnode->item = temp->item;
    temp->priority = Anode->priority;
    Anode->priority = Bnode->priority;
    Bnode->priority = temp->priority;
    free(temp);
}

void HeapifyUp(BHNode Cnode)
{
    if(Cnode->parent != NULL){
        /**/if(Cnode->parent->priority < Cnode->priority) {
            BHSwap(Cnode->parent,Cnode);
            HeapifyUp(Cnode->parent);
        }
        /**/
    }
}
Heap FindHead(BHNode Cnode)
{
    Heap Hhead;
    while(Cnode->parent != NULL) Cnode = Cnode->parent;
    Hhead.Fnode = Cnode;
    return Hhead;
}
void FIX_NODE(BHNode Cnode)
{
    /**/if((Cnode->left != NULL)&&(Cnode->right != NULL)){
        /**/if((Cnode->priority < Cnode->left->priority)||(Cnode->priority < Cnode->right->priority)){
            /**/if(Cnode->left->priority < Cnode->right->priority){
                BHSwap(Cnode,Cnode->right);
                FIX_NODE(Cnode->right);
            } else {
                BHSwap(Cnode,Cnode->left);
                FIX_NODE(Cnode->left);
            }
            /**/
        }
        /**/
    } else if((Cnode->left != NULL)&&(Cnode->priority < Cnode->left->priority)) {
        BHSwap(Cnode,Cnode->left);
        FIX_NODE(Cnode->left);
    } else if((Cnode->right != NULL)&&(Cnode->priority < Cnode->right->priority)) {
        BHSwap(Cnode,Cnode->right);
        FIX_NODE(Cnode->right);
    }
    /**/
}

void HeapifyDown(BHNode Cnode)
{
    if(Cnode->left != NULL) HeapifyDown(Cnode->left);
    if(Cnode->right != NULL) HeapifyDown(Cnode->right);
    FIX_NODE(Cnode);
}

BHNode SearchItemsBHNode(BHNode Cnode,BHItem item)
{
    BHNode  found = NULL ;
    if((Cnode->left != NULL)&&(Cnode->item != item)) found = SearchItemsBHNode(Cnode->left,item);
    if((Cnode->right != NULL)&&(Cnode->item != item)&&(found == NULL)) found = SearchItemsBHNode(Cnode->right,item);
    if(Cnode->item == item) return (found = Cnode);
    if(found != NULL) return found;
    return NULL;
}

BHNode SearchPRBHNode(BHNode Cnode,BHPriority priority)
{
    BHNode  found = NULL ;
    if((Cnode->left != NULL)&&(Cnode->priority != priority)) found = SearchPRBHNode(Cnode->left,priority);
    if((Cnode->right != NULL)&&(Cnode->priority != priority)&&(found == NULL)) found = SearchPRBHNode(Cnode->right,priority);
    if(Cnode->priority == priority) return (found = Cnode);
    if(found != NULL) return found;
    return NULL;
}

BHNode SearchBHNodeParent(BHNode Cnode,BHNode Fnode)
{
    BHNode  found = NULL;
    if((Cnode->left != NULL)&&(Cnode->left != Fnode)) found = SearchBHNodeParent(Cnode->left,Fnode);
    if((Cnode->right != NULL)&&(Cnode->right != Fnode)&&(found == NULL)) found = SearchBHNodeParent(Cnode->right,Fnode);
    if(found != NULL) return found;
    if((Cnode->left == Fnode)||(Cnode->right == Fnode)) return (found = Cnode);
    return NULL;
}

void BHRemove(Heap Hhead)
{
    BHNode RMV = SearchPRBHNode(Hhead.Fnode,BHGetMaxPriority(Hhead));
    RMV->item = VNULL;
    RMV->priority = VNULL;
    HeapifyDown(Hhead.Fnode);
    RMV = SearchItemsBHNode(Hhead.Fnode,VNULL);
    /**/if(RMV->parent->left == RMV){
        RMV->parent->left = NULL;
        free(RMV);
        return;
    }
    /**/
    RMV->parent->right = NULL;
    free(RMV);
}

void BHInsertNode(BHNode node,BHPriority priority,BHItem item)
{
    /**/if(node->left == NULL){
        node->left = malloc(sizeof(BHN));
        node->left->left = NULL;
        node->left->right = NULL;
        node->left->item = item;
        node->left->priority = priority;
        node->left->parent = node;
        return;
    }
    /**/
    node->right = malloc(sizeof(BHN));
    node->right->left = NULL;
    node->right->right = NULL;
    node->right->item = item;
    node->right->priority = priority;
    node->right->parent = node;
}

void BHInsert(Heap Hhead,BHPriority priority,BHItem item)
{
    BHInsertLast(Hhead,priority,item);
    BHNode LST = BHGetLast(Hhead);
    HeapifyUp(LST);
}

int MaxHeight(BHNode Nnode)
{
    int HGHT_l = 0;
    int HGHT_r = 0;
    if(Nnode->left != NULL) HGHT_l = MaxHeight(Nnode->left);
    if(Nnode->right != NULL) HGHT_r = MaxHeight(Nnode->right);
    /**/if(HGHT_l > HGHT_r ){
        return (HGHT_l + 1);
    }
    /**/
    return (HGHT_r + 1);
}

void BHPrintLevel(BHNode Cnode,int height)
{
    if(Cnode == NULL) return;
    /**/if(height == 0) {
        printf("%d  ",Cnode->item);
        return;
    }
    /**/
    BHPrintLevel(Cnode->left,height-1);
    BHPrintLevel(Cnode->right,height-1);
}

void BHPrint(Heap Hhead)
{
    /**/if(Hhead.Fnode == NULL){
        printf("\nERROR !!! ... Heap DOES NOT EXIST !!!\n");
        printf("UNABLE TO PRINT THE Heap !!!\n");
        return;
    }
    /**/
    int height = MaxHeight(Hhead.Fnode);
    int Levels = height-1;
    printf("\nCurrent Heap :\n");
    /**/while(height-- != 0){
        BHPrintLevel(Hhead.Fnode,Levels-height);
        printf("\n");
    }
    /**/
    printf("______________________________\n");
}

void BHRemoveNode(Heap Hhead,BHNode node)
{
    /**/if(node == NULL){
        printf("\nERROR !!! ... GIVEN NODE DOES NOT EXIST\n");
        return;
    }
    /**/
    /**/if((node->left != NULL)||(node->right != NULL)){
        printf("\nERROR !!! ... NODE HAS CHILDREN !!!\n");
        printf("UNABLE TO REMOVE THE NODE !!!\n");
        return;
    }
    /**/
    /**/if(Hhead.Fnode == node) {
        free(node);
        return;
    }
    /**/
    /**/if(node->parent->left == node){
        node->parent->left = NULL;
        free(node);
        return;
    }
    /**/
    node->parent->right = NULL;
    free(node);
}

void DeleteHeap(Heap Hhead,BHNode Cnode)
{
    if(Cnode->left != NULL) DeleteHeap(Hhead,Cnode->left);
    if(Cnode->right != NULL) DeleteHeap(Hhead,Cnode->right);
    if((Cnode->left == NULL)&&(Cnode->right == NULL)) BHRemoveNode(Hhead,Cnode);
}

void BHDestroy(Heap *Hhead)
{
    /**/if(Hhead->Fnode == NULL){
        return;
    }
    /**/
    DeleteHeap(*Hhead,Hhead->Fnode);
    Hhead->Fnode = NULL;
}

BHNode GetLast(BHNode Cnode,int height)
{
    BHNode found = NULL;
    if(Cnode->right != NULL) found = GetLast(Cnode->right,height-1);
    if((Cnode->left != NULL)&&(found == NULL)) found = GetLast(Cnode->left,height-1);
    if(height == 0) return Cnode;
    if(found != NULL) return found;
    return NULL;
}

BHNode BHGetLast(Heap Hhead)
{
    int height = MaxHeight(Hhead.Fnode);
    return GetLast(Hhead.Fnode,height-1);
}

BHNode GetNext(BHNode Cnode,BHNode Lnode_P,BHNode found,int height)
{
    if(Cnode == Lnode_P) return Lnode_P;
    if(Cnode->left != NULL) found = GetNext(Cnode->left,Lnode_P,found,height-1);
    if((Cnode->right != NULL)&&((found == NULL)||(found == Lnode_P))) found = GetNext(Cnode->right,Lnode_P,found,height-1);
    if((height-1 == 0)&&(found == Lnode_P)) return Cnode;
    return found;
}

BHNode GetFirstOfLastLine(BHNode Cnode)
{
    BHNode found;
    if(Cnode->left != NULL) found = GetFirstOfLastLine(Cnode->left);
    if(Cnode->left == NULL) return Cnode;
    if(found != NULL) return found;
    return NULL;
}

int IsLastOfLine(BHNode Cnode,BHNode Lnode)
{
    int last = 0;
    if(Cnode->right != NULL) last = IsLastOfLine(Cnode->right,Lnode);
    if((Cnode == Lnode)||(last == 1)) return 1;
    return 0;
}

void BHInsertLast(Heap Hhead,BHPriority priority,BHItem item)
{
    /**/if(Hhead.Fnode->item == VNULL){
        Hhead.Fnode->item = item;
        Hhead.Fnode->priority = priority;
        return;
    }
    /**/
    int height = MaxHeight(Hhead.Fnode);
    BHNode LST = GetLast(Hhead.Fnode,height-1);
    /**/if(LST == Hhead.Fnode){
        BHInsertNode(LST,priority,item);
        return;
    }
    /**/
    BHNode LST_P = SearchBHNodeParent(Hhead.Fnode,LST);
    /**/if((LST_P->left != NULL)&&(LST_P->right == NULL)){
        BHInsertNode(LST_P,priority,item);
        return ;
    }
    /**/
    /**/if(IsLastOfLine(Hhead.Fnode,LST)){
        BHInsertNode(GetFirstOfLastLine(Hhead.Fnode),priority,item);
        return;
    }
    /**/
    BHNode Next = GetNext(Hhead.Fnode,LST_P,NULL,height-1);
    BHInsertNode(Next,priority,item);
}

int HeapSize(BHNode Nnode)
{
    int counter = 0;
    if(Nnode->left != NULL) counter += HeapSize(Nnode->left);
    if(Nnode->right != NULL) counter += HeapSize(Nnode->right);
    if(Nnode->item != VNULL) return counter+1;
    if(counter != 0) return counter;
    return 0;
}

void FIll_Array(BHNode Cnode,int **AR,int i,int type,int Hsize)
{
    /**/if(type) {
        AR[0][i] = Cnode->priority;
    } else {
        AR[0][i] = Cnode->item;
    }
    /**/
    if((Cnode->left != NULL)&&(LEFT(i)<Hsize+1)) FIll_Array(Cnode->left,AR,LEFT(i),type,Hsize);
    if((Cnode->right != NULL)&&(RIGHT(i)<Hsize+1)) FIll_Array(Cnode->right,AR,RIGHT(i),type,Hsize);
}

int *BHPriorities(Heap Hhead)
{
    int Hsize = HeapSize(Hhead.Fnode);
    int *PR = malloc((Hsize+1)*sizeof(int));
    int i = 1;
    FIll_Array(Hhead.Fnode,&PR,i,PRIORITIES,Hsize);
    return PR;
}

int *BHItems(Heap Hhead)
{
    int Hsize = HeapSize(Hhead.Fnode);
    int *ITM = malloc((Hsize+1)*sizeof(int));
    int i = 1;
    FIll_Array(Hhead.Fnode,&ITM,i,ITEMS,Hsize);
    return ITM;
}

Heap BHHeapify(int Hsize,int *PR,int *ITM)
{
    Heap Cheap = BHCreate(Hsize);
    int i;
    /**/for(i = 1; i<Hsize+1 ;i++){
        BHInsertLast(Cheap,PR[i],ITM[i]);
    }
    /**/
    HeapifyDown(Cheap.Fnode);
    return Cheap;
}
