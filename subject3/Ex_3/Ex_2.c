#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Ex_2.h"
int maxelem;

int ADTIsNil(ADTTree Cnode,ADTNode n)
{
    if((Cnode == NULL)&&(Cnode[0] == EMPTY)&&((Cnode[n] == VNULL)||(n > maxelem))) return TRUE;
    return FALSE;
}


ADTTree ADTCreate(int Melem)
{
    ADTTree Thead;
    Thead = malloc((Melem+1)*sizeof(ADTNode));
    int i = 0;
    Thead[0] = EMPTY;
    /**/for(i = 1; i<=Melem ;i++){
        Thead[i] = VNULL;
    }
    /**/
    maxelem = Melem;
    return Thead;
}

int MaxHeight(ADTTree Nnode,int n)
{
    int HGHT_l = 0;
    int HGHT_r = 0;
    if((Nnode[LEFT(n)] != VNULL)&&(LEFT(n) <= maxelem)) HGHT_l = MaxHeight(Nnode,LEFT(n));
    if((Nnode[RIGHT(n)] != VNULL)&&(RIGHT(n) <= maxelem)) HGHT_r = MaxHeight(Nnode,RIGHT(n));
    if(HGHT_l > HGHT_r ){
        return (HGHT_l + 1);
    }
    return (HGHT_r + 1);
}

int ADTHeight(ADTTree tree)
{
    /**/if(ADTIsNil(tree,1)){
        printf("\nERROR !!! ... TREE IS EMPTY OR DOES NOT EXIST !!!\n");
        return VNULL;
    }
    /**/
    return MaxHeight(tree,1);
}

void ADTPrintLevel(ADTTree Cnode,int n,int height)
{
    if(Cnode == NULL) return;
    /**/if(height == 0) {
        printf("%d  ",Cnode[n]);
        return;
    }
    /**/
    if(Cnode[LEFT(n)] != VNULL) ADTPrintLevel(Cnode,LEFT(n),height-1);
    if(Cnode[RIGHT(n)] != VNULL) ADTPrintLevel(Cnode,RIGHT(n),height-1);
}

void ADTPrint(ADTTree tree)
{
    /**/if(ADTIsNil(tree,1)){
        /**/if(tree[0] == EMPTY){
            printf("\nTHE TREE IS EMPTY !!!\n");
            return ;
        }
        /**/
        printf("\nERROR !!! ... TREE DOES NOT EXIST !!!\n");
        printf("UNABLE TO PRINT THE TREE !!!\n");
        return;
    }
    /**/
    int height = ADTHeight(tree);
    int Levels = height-1;
    printf("\nCurrent Tree :\n");
    /**/while(height-- != 0){
        ADTPrintLevel(tree,1,Levels-height);
        printf("\n");
    }
    /**/
    printf("______________________________\n");
}

int NSize(ADTTree Nnode,int n)
{
    int counter = 0;
    if((Nnode[LEFT(n)] != VNULL)&&(LEFT(n) <= maxelem)) counter += NSize(Nnode,LEFT(n));
    if((Nnode[RIGHT(n)] != VNULL)&&(RIGHT(n) <= maxelem)) counter += NSize(Nnode,RIGHT(n));
    if(Nnode[n] != VNULL) return counter+1;
    if(counter != 0) return counter;
    return 0;
}

int ADTSize(ADTTree tree)
{
    /**/if(ADTIsNil(tree,1)){
        printf("\nERROR !!! ... TREE IS EMPTY OR DOES NOT EXIST !!!\n");
        return -1;
    }
    /**/
    return NSize(tree,1);
}

ADTNode ADTGetRoot(ADTTree tree)
{
    return (tree != NULL)? 1:VNULL;
}

ADTNode ADTGetParent(ADTTree tree,ADTNode n)
{
    /**/if(tree[1] == tree[n]){
        printf("\nERROR !!! ...  NODE IS ROOT !!!\n");
        printf("UNABLE TO FIND NODE'S PARENT !!!\n");
        return VNULL;
    }
    /**/
    return PAR(n);
}

ADTNode SearchItemsADTNode(ADTTree tree,ADTItem item)
{
    int n;
    /**/for(n = 1; n <= maxelem ;n++){
        if(tree[n] == item) return n;
    }
    /**/
    return VNULL;
}

ADTNode ADTGetChildLeft(ADTTree tree,ADTNode n)
{
    if((tree[n] != VNULL)&&(LEFT(n) <= maxelem)) return LEFT(n);
    return VNULL;
}

ADTNode ADTGetChildRight(ADTTree tree,ADTNode n)
{
    if((tree[n] != VNULL)&&(RIGHT(n) <= maxelem)) return RIGHT(n);
    return VNULL;
}

ADTItem ADTGetItem(ADTTree tree,ADTNode n)
{
    /**/if(ADTIsNil(tree,n)){
        printf("\nERROR !!! ... NODE IS NIL OR DOES NOT EXIST!!!\n");
        printf("UNABLE TO GET NODE'S ITEM !!!\n");
        return VNULL;
    }
    /**/
    return tree[n];
}

void ADTInsertRoot(ADTTree tree,ADTItem item)
{
    /**/if(tree[0] == NOT_EMPTY){
        printf("\nERROR!!! ... TREE IS NOT EMPTY\n");
        printf("UNABLE TO INSERT ROOT !!!\n");
        return;
    }
    /**/
    ADTTree *ROOT = &tree;
    ROOT[0][0] = NOT_EMPTY;
    ROOT[0][1] = item;
}

void ADTInsertLeft(ADTTree tree,ADTNode n,ADTItem item)
{
    /**/if(LEFT(n) > maxelem){
        printf("\nERROR!!! ... OUT OF BOUNDS !!!\n");
        return;
    }
    /**/
    /**/if(ADTIsNil(tree,n)){
        printf("\nERROR!!! ... THE PARENT OF THE NODE IS EMPTY OR DOES NOT EXIST!!!\n");
        printf("UNABLE TO INSERT NEW LEFT NODE !!!\n");
        return;
    }
    /**/
    /**/if(tree[LEFT(n)] != VNULL){
        printf("\nERROR!!! ... NODE IS NOT EMPTY!!!\n");
        printf("UNABLE TO INSERT NEW LEFT NODE !!!\n");
        return;
    }
    /**/
    ADTTree *ADL = &tree;
    ADL[0][LEFT(n)] = item;
}

void ADTInsertRight(ADTTree tree,ADTNode n,ADTItem item)
{
    /**/if(LEFT(n) > maxelem){
        printf("\nERROR!!! ... OUT OF BOUNDS !!!\n");
        return;
    }
    /**/
    /**/if(ADTIsNil(tree,n)){
        printf("\nERROR!!! ... THE PARENT OF THE NODE IS EMPTY OR DOES NOT EXIST!!!\n");
        printf("UNABLE TO INSERT NEW RIGHT NODE !!!\n");
        return;
    }
    /**/
    /**/if(tree[RIGHT(n)] != VNULL){
        printf("\nERROR!!! ... NODE IS NOT EMPTY!!!\n");
        printf("UNABLE TO INSERT NEW RIGHT NODE !!!\n");
        return;
    }
    /**/
    ADTTree *ADR = &tree;
    ADR[0][RIGHT(n)] = item;
}

void ADTRemove(ADTTree tree,ADTNode n)
{
    /**/if(((tree[LEFT(n)] != VNULL)||(tree[RIGHT(n)] != VNULL))&&((LEFT(n) <= maxelem)||(RIGHT(n) <= maxelem))){
        printf("\nERROR !!! ... NODE HAS CHILDREN !!!\n");
        printf("UNABLE TO REMOVE THE NODE !!!\n");
        return;
    }
    /**/
    ADTTree *RM = &tree;
    RM[0][n] = VNULL;
}

void ADTChange(ADTTree tree,ADTNode n,ADTItem item)
{
    /**/if(ADTIsNil(tree,n)){
        printf("\nERROR !!! ... NODE DOES NOT EXIST\n");
        printf("UNABLE TO CHANGE NODE'S ITEM\n");
        return;
    }
    /**/
    ADTTree *CH = &tree;
    CH[0][n] = item;
}

void ADTDestroy(ADTTree tree)
{
    /**/if(tree == NULL){
        printf("\nUNABLE TO DELETE THE TREE BECAUSE IT DOES NOT EXIST !!!\n");
        return;
    }
    /**/
    free(tree);
    tree = NULL;
}

void Visit(ADTItem item)
{
    printf("%3d",item);
}
void ADTPreOrder(ADTTree tree,ADTNode n,void (*Visit)(int item))
{
    if(n > maxelem) return;
    Visit(tree[n]);
    if(tree[LEFT(n)] != VNULL) ADTPreOrder(tree,LEFT(n),Visit);
    if(tree[RIGHT(n)] != VNULL) ADTPreOrder(tree,RIGHT(n),Visit);
}

void ADTInOrder(ADTTree tree,ADTNode n,void (*Visit)(int item))
{
    if(n > maxelem) return;
    if(tree[LEFT(n)] != VNULL) ADTInOrder(tree,LEFT(n),Visit);
    Visit(tree[n]);
    if(tree[RIGHT(n)] != VNULL) ADTInOrder(tree,RIGHT(n),Visit);
}

void ADTPostOrder(ADTTree tree,ADTNode n,void (*Visit)(int item))
{
    if(n > maxelem) return;
    if(tree[LEFT(n)] != VNULL) ADTPostOrder(tree,LEFT(n),Visit);
    if(tree[RIGHT(n)] != VNULL) ADTPostOrder(tree,RIGHT(n),Visit);;
    Visit(tree[n]);
}

void PrintOrder(ADTTree tree)
{
    printf("\nPrint Pre Order :\n");
    ADTPreOrder(tree,1,Visit);
    printf("\nPrint In Order :\n");
    ADTInOrder(tree,1,Visit);
    printf("\nPrint Post Order :\n");
    ADTPostOrder(tree,1,Visit);
    printf("\n");
}
