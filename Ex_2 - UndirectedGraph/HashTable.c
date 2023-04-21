#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "HashTable.h"

int HTPDef= 5;

int* PtrOfInt(int num)
{
    int *numPtr = malloc(sizeof(int));
    *numPtr = num;
    return numPtr;
}

double* PtrOfDouble(double num)
{
    double *numPtr = malloc(sizeof(double));
    *numPtr = num;
    return numPtr;
}

int Get_Int(HTItem item)
{
    return *((int *)item);
}

char *Get_String(HTItem item)
{
    return (char *)item;
}

double Get_Double(HTItem item)
{
    return *((double *)item);
}

int CMP_int(HTItem item,int num)
{
    int INT_item = *((int *)item);
    return (INT_item == num)? 1 :((INT_item > num)? 2 : 0);
}

int CMP_double(HTItem item,double num)
{
    double DOUBLE_item = *((double *)item);
    return (DOUBLE_item == num)? 1 :((DOUBLE_item > num)? 2 : 0);
}

int CMP_string(HTItem item,char *str)
{
    return strcmp((char *)item,str);
}

HTHash HTCreate(int size)
{
    HTHash hash = malloc(size*sizeof(node));
    /**/for(int i = 0; i<size ;i++){
        hash[i].item_L = NULL;
        hash[i].Size = 0;
        hash[i].HT_Size = size;
    }
    /**/
    return hash;
}

int HTSize(HTHash hash)
{
    int Size = hash[0].HT_Size;
    int counter = 0;
    /**/for(int i = 0; i<Size ;i++){
        counter += hash[i].Size;
    }
    /**/
    return counter;
}

HTHash HTUpgradeHash(HTHash hash)
{
    HTIList Cnode ;
    int Size = hash[0].HT_Size;
    HTHash Newhash = HTCreate(Size*2);
    /**/for(int i = 0; i<Size ;i++){
        Cnode = hash[i].item_L;
        /**/while(Cnode != NULL){
            HTInsert(&Newhash,Cnode->key,Cnode->item);
            Cnode = Cnode->next;
        /**/}
    /**/}
    free(hash);
    return Newhash;
}

int HashF(HTHashPtr hash,HKey key)
{
    int Size = (*hash)->HT_Size;
    int HTsize = HTSize(*hash);
    /**/if(HTsize/Size >= 1){
        *hash = HTUpgradeHash(*hash);
    }
    /**/
    int dir = 0;
    int i = 0;
    /**/while(key[i] != '\0'){
        dir += key[i++];
    }
    /**/
    return dir%(*hash)->HT_Size;
}

HTIList SearchForKey(HTIList List,HKey key)
{
    /**/while(List != NULL){
        /**/if(strcmp(key,List->key) == 0){
            return List;
        }
        /**/
        List = List->next;
    }
    /**/
    return NULL;
}

int HTGet(HTHash hash,HKey key,HTItemPtr pitem)
{
    int dir = HashF(&hash,key);
    if(hash[dir].item_L == NULL) return FALSE;
    HTIList KOwner = SearchForKey(hash[dir].item_L,key);
    if(KOwner == NULL) return FALSE;
    *pitem = KOwner->item;
    return TRUE;
}

void InsertNode(HTIList *Cnode,HKey key,HTItem item)
{
    /**/if(*Cnode != NULL){
        HTIList temp = *Cnode;
        *Cnode = malloc(sizeof(node_L));
        (*Cnode)->item = item;
        (*Cnode)->key = key;
        (*Cnode)->next = temp;
        return;
    }
    /**/
    *Cnode = malloc(sizeof(node_L));
    (*Cnode)->item = item;
    (*Cnode)->key = key;
    (*Cnode)->next = NULL;
}

void HTInsert(HTHashPtr hash,HKey key,HTItem item)
{
    int dir = HashF(hash,key);
    HTIList KOwner = SearchForKey((*hash)[dir].item_L,key);
    /**/if(KOwner == NULL) {
        InsertNode(&((*hash)[dir].item_L),key,item);
        ((*hash)[dir].Size)++;
        return;
    }
    /**/
    KOwner->item = item;
}

void print_INT(HTIList Cnode)
{
    /**/while(Cnode != NULL){
        printf("%d  ",*((int *)(Cnode->item)));
        Cnode = Cnode->next;
    }
    /**/
}

void print_CHAR(HTIList Cnode)
{
    /**/while(Cnode != NULL){
        printf("%s  ",(char *)(Cnode->item));
        Cnode = Cnode->next;
    }
    /**/
}

void print_FLOAT(HTIList Cnode)
{
    /**/while(Cnode != NULL){
        printf("%f  ",*((float *)(Cnode->item)));
        Cnode = Cnode->next;
    }
    /**/
}

void print_DOUBLE(HTIList Cnode)
{
    /**/while(Cnode != NULL){
        printf("%lf  ",*((double *)(Cnode->item)));
        Cnode = Cnode->next;
    }
    /**/
}

void HTPrint(HTHash hash,Print PRT)
{
    int Size = hash[0].HT_Size;
    printf("\n");
    int count_empty = 0;
    /**/for(int i = 0; i<Size ;i++){
        /**/if(hash[i].item_L == NULL){
            count_empty++;
        } else {
            printf("%d Node:  ",i);
            PRT(hash[i].item_L);
            printf("\n");
        }
        /**/
    }
    /**/
    printf("The hash has %d empty Nodes...\n",count_empty);
}

void RemoveNode(HTIList *Cnode,HTIList Rnode)
{
    /**/if(*Cnode == Rnode){
         *Cnode = (*Cnode)->next;
         free(Rnode);
         return;
    }
    /**/
    if((*Cnode)->next != Rnode) RemoveNode(&((*Cnode)->next),Rnode);
    /**/if((*Cnode)->next == Rnode){
        (*Cnode)->next = Rnode->next;
        free(Rnode);
    }
    /**/
}

void HTRemove(HTHash hash,HKey key)
{
    int dir = HashF(&hash,key);
    if(hash[dir].item_L == NULL) return;
    HTIList KOwner = SearchForKey(hash[dir].item_L,key);
    if(KOwner == NULL) return;
    RemoveNode(&(hash[dir].item_L),KOwner);
    (hash[dir].Size)--;
}

void DestroyNode(HTIList Cnode)
{
    if((Cnode != NULL)&&(Cnode->next != NULL)) DestroyNode(Cnode->next);
    if(Cnode == NULL) return;
    free(Cnode);
}

void HTDestroy(HTHash hash)
{
    int Size = hash[0].HT_Size;
    /**/for(int i = 0; i<Size ;i++){
        DestroyNode(hash[i].item_L);
    }
    /**/
    free(hash);
}

void Visit_node(HTHash hash,HTIList Cnode,Visit vst)
{
    /**/while(Cnode != NULL){
        vst(hash,Cnode->key,Cnode->item);
        Cnode = Cnode->next;
    }
    /**/
}

void HTVisit(HTHash hash,Visit vst)
{
    int Size = hash[0].HT_Size;
    /**/for(int i = 0; i<Size ;i++){
        Visit_node(hash,hash[i].item_L,vst);
    }
    /**/
}
