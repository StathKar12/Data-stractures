#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Ex_1.h"

BTTree BTCreate(int Melem)
{
    BTTree Thead;
    Thead.Nnum = Melem;
    Thead.Fnode = malloc(sizeof(BTN));
    Thead.Fnode->left = NULL;
    Thead.Fnode->right = NULL;
    Thead.Fnode->item = VNULL;
    return Thead;
}

int MaxHeight(BTNode Nnode)
{
    int HGHT_l = 0;
    int HGHT_r = 0;
    if(Nnode->left != NULL) HGHT_l = MaxHeight(Nnode->left);
    if(Nnode->right != NULL) HGHT_r = MaxHeight(Nnode->right);
    if(HGHT_l > HGHT_r ){
        return (HGHT_l + 1);
    }
    return (HGHT_r + 1);
}

int BTHeight(BTTree tree)
{
    return MaxHeight(tree.Fnode);
}

int NSize(BTNode Nnode)
{
    int counter = 0;
    if(Nnode->left != NULL) counter += NSize(Nnode->left);
    if(Nnode->right != NULL) counter += NSize(Nnode->right);
    if(Nnode->item != VNULL) return counter+1;
    if(counter != 0) return counter;
    return 0;
}

int BTSize(BTTree tree)
{
    return NSize(tree.Fnode);
}

BTNode BTGetRoot(BTTree tree)
{
    return (tree.Fnode != NULL)? tree.Fnode:NULL;
}

BTNode SearchItemsBTNode(BTNode Cnode,BTItem item)
{
    BTNode  found = NULL ;
    if((Cnode->left != NULL)&&(Cnode->item != item)) found = SearchItemsBTNode(Cnode->left,item);
    if((Cnode->right != NULL)&&(Cnode->item != item)&&(found == NULL)) found = SearchItemsBTNode(Cnode->right,item);
    if(Cnode->item == item) return (found = Cnode);
    if(found != NULL) return found;
    return NULL;
}

BTNode SearchBTNodeParent(BTNode Cnode,BTNode Fnode)
{
    BTNode  found = NULL;
    if((Cnode->left != NULL)&&(Cnode->left != Fnode)) found = SearchBTNodeParent(Cnode->left,Fnode);
    if((Cnode->right != NULL)&&(Cnode->right != Fnode)&&(found == NULL)) found = SearchBTNodeParent(Cnode->right,Fnode);
    if(found != NULL) return found;
    if((Cnode->left == Fnode)||(Cnode->right == Fnode)) return (found = Cnode);
    return NULL;
}

BTNode BTGetParent(BTTree tree,BTNode Cnode)
{
    /**/if(tree.Fnode == Cnode){
        printf("\nERROR !!! ...  NODE IS ROOT !!!\n");
        printf("UNABLE TO FIND NODE'S PARENT !!!\n");
        return NULL;
    }
    /**/
    return SearchBTNodeParent(tree.Fnode,Cnode);
}

BTNode BTGetChildLeft(BTTree tree,BTNode Cnode)
{
    if(Cnode != NULL) return Cnode->left;
    printf("\nERROR !!! ... NODE DOES NOT EXIST !!!\n");
    printf("UNABLE TO FIND NODE'S LEFT CHILD !!!\n");
    return NULL;
}

BTNode BTGetChildRight(BTTree tree,BTNode Cnode)
{
    if(Cnode != NULL) return Cnode->right;
    printf("\nERROR !!! ... NODE DOES NOT EXIST !!!\n");
    printf("UNABLE TO FIND NODE'S RIGHT CHILD !!!\n");
    return NULL;
}

int BTIsNil(BTNode Cnode)
{
    if((Cnode == NULL)||(Cnode->item == VNULL)) return TRUE;
    return FALSE;
}

BTItem BTGetItem(BTTree tree,BTNode Cnode)
{
    /**/if(BTIsNil(Cnode)){
        printf("\nERROR !!! ... NODE IS NIL OR DOES NOT EXIST!!!\n");
        printf("UNABLE TO GET NODE'S ITEM !!!\n");
        return VNULL;
    }
    /**/
    return Cnode->item;
    printf("\n...ALL_GOOD...\n");
}

void BTInsertRoot(BTTree tree,BTItem item)
{
    /**/if(!BTIsNil(tree.Fnode)){
        printf("\nERROR!!! ... TREE IS NOT EMPTY\n");
        printf("UNABLE TO INSERT ROOT !!!\n");
        return;
    }
    /**/
    tree.Fnode->item = item;
}

void BTInsertLeft(BTTree tree,BTNode node,BTItem item)
{
    /**/if(BTIsNil(node)){
        printf("\nERROR!!! ... THE PARENT OF THE NODE IS EMPTY OR DOES NOT EXIST!!!\n");
        printf("UNABLE TO INSERT NEW NODE !!!\n");
        return;
    }
    /**/
    /**/if(!BTIsNil(node->left)){
        printf("\nERROR!!! ... NODE IS NOT EMPTY!!!\n");
        printf("UNABLE TO INSERT NEW NODE !!!\n");
        return;
    }
    /**/
    BTInsertNode(node,LEFT,item);
}

void BTInsertRight(BTTree tree,BTNode node,BTItem item)
{
    /**/if(BTIsNil(node)){
        printf("\nERROR!!! ... THE PARENT OF THE NODE IS EMPTY OR DOES NOT EXIST!!!\n");
        printf("UNABLE TO INSERT NEW NODE !!!\n");
        return;
    }
    /**/
    /**/if(!BTIsNil(node->right)){
        printf("\nERROR!!! ... NODE IS NOT EMPTY!!!\n");
        printf("UNABLE TO INSERT NEW NODE !!!\n");
        return;
    }
    /**/
    BTInsertNode(node,RIGHT,item);
}

void BTInsertNode(BTNode node,int Drc,BTItem item)
{
    /**/if(Drc == LEFT){
        node->left = malloc(sizeof(BTN));
        node->left->left = NULL;
        node->left->right = NULL;
        node->left->item = item;
        return;
    }
    /**/
    node->right = malloc(sizeof(BTN));
    node->right->left = NULL;
    node->right->right = NULL;
    node->right->item = item;
}

void BTPrintLevel(BTNode Cnode,int height)
{
    if(Cnode == NULL) return;
    /**/if(height == 0) {
        printf("%d  ",Cnode->item);
        return;
    }
    /**/
    BTPrintLevel(Cnode->left,height-1);
    BTPrintLevel(Cnode->right,height-1);
}

void BTPrint(BTTree tree)
{
    /**/if(tree.Fnode == NULL){
        printf("\nERROR !!! ... TREE DOES NOT EXIST !!!\n");
        printf("UNABLE TO PRINT THE TREE !!!\n");
        return;
    }
    /**/
    int height = BTHeight(tree);
    int Levels = height-1;
    printf("\nCurrent Tree :\n");
    /**/while(height-- != 0){
        BTPrintLevel(tree.Fnode,Levels-height);
        printf("\n");
    }
    /**/
    printf("______________________________\n");
}

void BTRemove(BTTree tree,BTNode node)
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
    /**/if(BTGetRoot(tree) == node) {
        free(node);
        return;
    }
    /**/
    BTNode RMN = SearchBTNodeParent(tree.Fnode,node);
    /**/if(RMN->left == node){
        RMN->left = NULL;
        free(node);
        return;
    }
    /**/
    free(node);
    RMN->right = NULL;
}

void BTChange(BTTree tree,BTNode node,BTItem item)
{
    /**/if(node == NULL){
        printf("\nERROR !!! ... NODE DOES NOT EXIST\n");
        printf("UNABLE TO CHANGE NODE'S ITEM\n");
        return;
    }
    /**/
    node->item = item;
}

void DeleteTree(BTTree tree,BTNode Cnode)
{
    if(Cnode->left != NULL) DeleteTree(tree,Cnode->left);
    if(Cnode->right != NULL) DeleteTree(tree,Cnode->right);
    if((Cnode->left == NULL)&&(Cnode->right == NULL)) BTRemove(tree,Cnode);
}

void BTDestroy(BTTree *tree)
{
    /**/if(tree->Fnode == NULL){
        return;
    }
    /**/
    DeleteTree(*tree,tree->Fnode);
    tree->Fnode = NULL;
}

void Visit(BTItem item)
{
    printf("%3d",item);
}
void BTPreOrder(BTNode Cnode,void (*Visit)(int item))
{
    Visit(Cnode->item);
    if(Cnode->left != NULL) BTPreOrder(Cnode->left,Visit);
    if(Cnode->right != NULL) BTPreOrder(Cnode->right,Visit);
}

void BTInOrder(BTNode Cnode,void (*Visit)(int item))
{
    if(Cnode->left != NULL) BTInOrder(Cnode->left,Visit);
    Visit(Cnode->item);
    if(Cnode->right != NULL) BTInOrder(Cnode->right,Visit);
}

void BTPostOrder(BTNode Cnode,void (*Visit)(int item))
{
    if(Cnode->left != NULL) BTPostOrder(Cnode->left,Visit);
    if(Cnode->right != NULL) BTPostOrder(Cnode->right,Visit);
    Visit(Cnode->item);
}

void PrintOrder(BTTree tree)
{
    printf("\nPrint Pre Order :\n");
    BTPreOrder(tree.Fnode,Visit);
    printf("\nPrint In Order :\n");
    BTInOrder(tree.Fnode,Visit);
    printf("\nPrint Post Order :\n");
    BTPostOrder(tree.Fnode,Visit);
    printf("\n");
}

