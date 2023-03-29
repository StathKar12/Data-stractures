#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Ex_4.h"

CBTTree CBTCreate(int Melem)
{
    CBTTree Thead;
    Thead.Nnum = Melem;
    Thead.Fnode = malloc(sizeof(CBTN));
    Thead.Fnode->left = NULL;
    Thead.Fnode->right = NULL;
    Thead.Fnode->item = VNULL;
    return Thead;
}

int MaxHeight(CBTNode Nnode)
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

int CBTHeight(CBTTree tree)
{
    return MaxHeight(tree.Fnode);
}

int NSize(CBTNode Nnode)
{
    int counter = 0;
    if(Nnode->left != NULL) counter += NSize(Nnode->left);
    if(Nnode->right != NULL) counter += NSize(Nnode->right);
    if(Nnode->item != VNULL) return counter+1;
    if(counter != 0) return counter;
    return 0;
}

int CBTSize(CBTTree tree)
{
    return NSize(tree.Fnode);
}

CBTNode CBTGetRoot(CBTTree tree)
{
    return (tree.Fnode != NULL)? tree.Fnode:NULL;
}

CBTNode SearchItemsCBTNode(CBTNode Cnode,CBTItem item)
{
    CBTNode  found = NULL ;
    if((Cnode->left != NULL)&&(Cnode->item != item)) found = SearchItemsCBTNode(Cnode->left,item);
    if((Cnode->right != NULL)&&(Cnode->item != item)&&(found == NULL)) found = SearchItemsCBTNode(Cnode->right,item);
    if(Cnode->item == item) return (found = Cnode);
    if(found != NULL) return found;
    return NULL;
}

CBTNode SearchCBTNodeParent(CBTNode Cnode,CBTNode Fnode)
{
    CBTNode  found = NULL;
    if((Cnode->left != NULL)&&(Cnode->left != Fnode)) found = SearchCBTNodeParent(Cnode->left,Fnode);
    if((Cnode->right != NULL)&&(Cnode->right != Fnode)&&(found == NULL)) found = SearchCBTNodeParent(Cnode->right,Fnode);
    if(found != NULL) return found;
    if((Cnode->left == Fnode)||(Cnode->right == Fnode)) return (found = Cnode);
    return NULL;
}

CBTNode CBTGetParent(CBTTree tree,CBTNode Cnode)
{
    /**/if(tree.Fnode == Cnode){
        printf("\nERROR !!! ...  NODE IS ROOT !!!\n");
        printf("UNABLE TO FIND NODE'S PARENT !!!\n");
        return NULL;
    }
    /**/
    return SearchCBTNodeParent(tree.Fnode,Cnode);
}

CBTNode CBTGetChildLeft(CBTTree tree,CBTNode Cnode)
{
    if(Cnode != NULL) return Cnode->left;
    printf("\nERROR !!! ... NODE DOES NOT EXIST !!!\n");
    printf("UNABLE TO FIND NODE'S LEFT CHILD !!!\n");
    return NULL;
}

CBTNode CBTGetChildRight(CBTTree tree,CBTNode Cnode)
{
    if(Cnode != NULL) return Cnode->right;
    printf("\nERROR !!! ... NODE DOES NOT EXIST !!!\n");
    printf("UNABLE TO FIND NODE'S RIGHT CHILD !!!\n");
    return NULL;
}

int CBTIsNil(CBTNode Cnode)
{
    if((Cnode == NULL)||(Cnode->item == VNULL)) return TRUE;
    return FALSE;
}

CBTItem CBTGetItem(CBTTree tree,CBTNode Cnode)
{
    /**/if(CBTIsNil(Cnode)){
        printf("\nERROR !!! ... NODE IS NIL OR DOES NOT EXIST!!!\n");
        printf("UNABLE TO GET NODE'S ITEM !!!\n");
        return VNULL;
    }
    /**/
    return Cnode->item;
    printf("\n...ALL_GOOD...\n");
}

void CBTInsertNode(CBTNode node,CBTItem item)
{
    /**/if(node->left == NULL){
        node->left = malloc(sizeof(CBTN));
        node->left->left = NULL;
        node->left->right = NULL;
        node->left->item = item;
        return;
    }
    /**/
    node->right = malloc(sizeof(CBTN));
    node->right->left = NULL;
    node->right->right = NULL;
    node->right->item = item;
}

void CBTPrintLevel(CBTNode Cnode,int height)
{
    if(Cnode == NULL) return;
    /**/if(height == 0) {
        printf("%d  ",Cnode->item);
        return;
    }
    /**/
    CBTPrintLevel(Cnode->left,height-1);
    CBTPrintLevel(Cnode->right,height-1);
}

void CBTPrint(CBTTree tree)
{
    /**/if(tree.Fnode == NULL){
        printf("\nERROR !!! ... TREE DOES NOT EXIST !!!\n");
        printf("UNABLE TO PRINT THE TREE !!!\n");
        return;
    }
    /**/
    int height = CBTHeight(tree);
    int Levels = height-1;
    printf("\nCurrent Tree :\n");
    /**/while(height-- != 0){
        CBTPrintLevel(tree.Fnode,Levels-height);
        printf("\n");
    }
    /**/
    printf("______________________________\n");
}

void CBTRemove(CBTTree tree,CBTNode node)
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
    /**/if(CBTGetRoot(tree) == node) {
        free(node);
        return;
    }
    /**/
    CBTNode RMN = SearchCBTNodeParent(tree.Fnode,node);
    /**/if(RMN->left == node){
        RMN->left = NULL;
        free(node);
        return;
    }
    /**/
    RMN->right = NULL;
    free(node);
}

void CBTChange(CBTTree tree,CBTNode node,CBTItem item)
{
    /**/if(node == NULL){
        printf("\nERROR !!! ... NODE DOES NOT EXIST\n");
        printf("UNABLE TO CHANGE NODE'S ITEM\n");
        return;
    }
    /**/
    node->item = item;
}

void DeleteTree(CBTTree tree,CBTNode Cnode)
{
    if(Cnode->left != NULL) DeleteTree(tree,Cnode->left);
    if(Cnode->right != NULL) DeleteTree(tree,Cnode->right);
    if((Cnode->left == NULL)&&(Cnode->right == NULL)) CBTRemove(tree,Cnode);
}

void CBTDestroy(CBTTree *tree)
{
    /**/if(tree->Fnode == NULL){
        return;
    }
    /**/
    DeleteTree(*tree,tree->Fnode);
    tree->Fnode = NULL;
}

void Visit(CBTItem item)
{
    printf("%3d",item);
}
void CBTPreOrder(CBTNode Cnode,void (*Visit)(int item))
{
    Visit(Cnode->item);
    if(Cnode->left != NULL) CBTPreOrder(Cnode->left,Visit);
    if(Cnode->right != NULL) CBTPreOrder(Cnode->right,Visit);
}

void CBTInOrder(CBTNode Cnode,void (*Visit)(int item))
{
    if(Cnode->left != NULL) CBTInOrder(Cnode->left,Visit);
    Visit(Cnode->item);
    if(Cnode->right != NULL) CBTInOrder(Cnode->right,Visit);
}

void CBTPostOrder(CBTNode Cnode,void (*Visit)(int item))
{
    if(Cnode->left != NULL) CBTPostOrder(Cnode->left,Visit);
    if(Cnode->right != NULL) CBTPostOrder(Cnode->right,Visit);
    Visit(Cnode->item);
}

void PrintOrder(CBTTree tree)
{
    printf("\nPrint Pre Order :\n");
    CBTPreOrder(tree.Fnode,Visit);
    printf("\nPrint In Order :\n");
    CBTInOrder(tree.Fnode,Visit);
    printf("\nPrint Post Order :\n");
    CBTPostOrder(tree.Fnode,Visit);
    printf("\n");
}

CBTNode GetLast(CBTNode Cnode,int height)
{
    CBTNode found = NULL;
    if(Cnode->right != NULL) found = GetLast(Cnode->right,height-1);
    if((Cnode->left != NULL)&&(found == NULL)) found = GetLast(Cnode->left,height-1);
    if(height == 0) return Cnode;
    if(found != NULL) return found;
    return NULL;
}

CBTNode CBTGetLast(CBTTree tree)
{
    int height = CBTHeight(tree);
    return GetLast(tree.Fnode,height-1);
}

CBTNode GetNext(CBTNode Cnode,CBTNode Lnode_P,CBTNode found,int height)
{
    if(Cnode == Lnode_P) return Lnode_P;
    if(Cnode->left != NULL) found = GetNext(Cnode->left,Lnode_P,found,height-1);
    if((Cnode->right != NULL)&&((found == NULL)||(found == Lnode_P))) found = GetNext(Cnode->right,Lnode_P,found,height-1);
    if((height-1 == 0)&&(found == Lnode_P)) return Cnode;
    return found;
}

CBTNode GetFirstOfLastLine(CBTNode Cnode)
{
    CBTNode found;
    if(Cnode->left != NULL) found = GetFirstOfLastLine(Cnode->left);
    if(Cnode->left == NULL) return Cnode;
    if(found != NULL) return found;
    return NULL;
}

int IsLastOfLine(CBTNode Cnode,CBTNode Lnode)
{
    int last = 0;
    if(Cnode->right != NULL) last = IsLastOfLine(Cnode->right,Lnode);
    if((Cnode == Lnode)||(last == 1)) return 1;
    return 0;
}

void CBTInsertLast(CBTTree tree,CBTItem item)
{
    /**/if(tree.Fnode->item == VNULL){
        tree.Fnode->item = item;
        return;
    }
    /**/
    int height = CBTHeight(tree);
    CBTNode LST = GetLast(tree.Fnode,height-1);
    /**/if(LST == tree.Fnode){
        CBTInsertNode(LST,item);
        return;
    }
    /**/
    CBTNode LST_P = CBTGetParent(tree,LST);
    /**/if((LST_P->left != NULL)&&(LST_P->right == NULL)){
        CBTInsertNode(LST_P,item);
        return ;
    }
    /**/
    /**/if(IsLastOfLine(tree.Fnode,LST)){
        CBTInsertNode(GetFirstOfLastLine(tree.Fnode),item);
        return;
    }
    /**/
    CBTNode Next = GetNext(tree.Fnode,LST_P,NULL,height-1);
    CBTInsertNode(Next,item);
}

void CBTRemoveLast(CBTTree tree)
{
    /**/if((tree.Fnode == NULL)||(CBTSize(tree) == 0)){
        printf("\nERROR !!! ... TREE IS EMPTY OR DOES NOT EXIST !!!\n");
        return;
    }
    /**/
    CBTNode LST = CBTGetLast(tree);
    CBTRemove(tree,LST);
}

