#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "HashTable.h"
#include "UndirectedGraph.h"

int UGPDef = 26;

UGGraph UGCreate(int Size)
{
    UGGraph graph = malloc(Size*sizeof(UGnode));
    /**/for(int i = 0; i<Size ;i++){
        graph[i].firstvertex = NULL;
        graph[i].Node_Size = 0;
        graph[i].UG_Size = Size;
    }
    /**/
    return graph;
}

int UGSize(UGGraph graph)
{
    int Size = graph[0].UG_Size;
    int counter = 0;
    /**/for(int i = 0; i<Size ;i++){
        counter += graph[i].Node_Size;
    }
    /**/
    return counter;
}

UGGraph UGUpgradeGraph(UGGraph graph)
{
    int Size = graph[0].UG_Size;
    UGGraph Newgraph = UGCreate(Size*2);
    UGVList Cnode;
    UGEList Cedge;
    /**/for(int i = 0; i<Size ;i++){
        Cnode = graph[i].firstvertex;
        /**/while(Cnode != NULL){
            UGAddVertex(&Newgraph,Cnode->peak);
            Cnode = Cnode->nextvertex;
        /**/}
    /**/}
    /**/for(int i = 0; i<Size ;i++){
        Cnode = graph[i].firstvertex;
        /**/while(Cnode != NULL){
            Cedge = Cnode->firstedge;
            /**/while(Cedge != NULL){
                UGAddEdge(Newgraph,Cnode->peak,Cedge->EdgeV->peak);
                Cedge = Cedge->nextedge;
            /**/}
            Cnode = Cnode->nextvertex;
        /**/}
    /**/}
    free(graph);
    return Newgraph;
}

int UGHashF(UGGraphPtr graph,UGVertex peak)
{
    int Size = (*graph)->UG_Size;
    int Gsize = UGSize(*graph);
    /**/if(Gsize/Size >= 1){
        *graph = UGUpgradeGraph(*graph);
    }
    /**/
    int dir = 0;
    int i = 0;
    /**/while(peak[i] != '\0'){
        dir += peak[i++];
    }
    /**/
    return dir%(*graph)->UG_Size;
}

UGVList SearchForVertex(UGVList List,UGVertex peak)
{
    /**/while(List != NULL){
        /**/if(strcmp(peak,List->peak) == 0){
            return List;
        }
        /**/
        List = List->nextvertex;
    }
    /**/
    return NULL;
}

UGEList SearchForEdge(UGEList Cedge,UGVertex peak)
{
    /**/while(Cedge != NULL){
        /**/if(strcmp(peak,Cedge->EdgeV->peak) == 0){
            return Cedge;
        }
        /**/
        Cedge = Cedge->nextedge;
    }
    /**/
    return NULL;
}

void InsertVertex(UGVList *UGnode,UGVertex peak)
{
    /**/if(*UGnode != NULL){
        UGVList temp = *UGnode ;
        *UGnode = malloc(sizeof(V_node));
        (*UGnode)->peak = peak;
        (*UGnode)->nextvertex = temp;
        (*UGnode)->firstedge = NULL;
        return;
    }
    /**/
    *UGnode = malloc(sizeof(V_node));
    (*UGnode)->peak = peak;
    (*UGnode)->nextvertex = NULL;
    (*UGnode)->firstedge = NULL;
}

void InsertEdge(UGEList *Cedge,UGVList ToV)
{
    /**/if(*Cedge != NULL){
        UGEList temp = *Cedge;
        *Cedge = malloc(sizeof(Edge));
        (*Cedge)->EdgeV = ToV;
        (*Cedge)->nextedge = temp;
        return;
    }
    /**/
    *Cedge = malloc(sizeof(Edge));
    (*Cedge)->EdgeV = ToV;
    (*Cedge)->nextedge = NULL;
}

void UGAddVertex(UGGraphPtr graph,UGVertex peak)
{
    int dir = UGHashF(graph,peak);
    UGVList KOwner = SearchForVertex(graph[0][dir].firstvertex,peak);
    /**/if(KOwner == NULL) {
        InsertVertex(&(graph[0][dir].firstvertex),peak);
        (graph[0][dir].Node_Size)++;
    }
    /**/
}

void PrintEdges(UGEList Cedge)
{
    /**/if(Cedge == NULL){
        printf("  No Edges...");
        return;
    }
    /**/
    printf("  Edges: ");
    /**/while(Cedge != NULL){
        printf("%s ",Cedge->EdgeV->peak);
        Cedge = Cedge->nextedge;
    }
    /**/
}

void PrintVertices(UGVList Cvert)
{
    /**/while(Cvert != NULL){
        printf("    %s",Cvert->peak);
        PrintEdges(Cvert->firstedge);
        printf("\n");
        Cvert = Cvert->nextvertex;
    }
    /**/
}

void UGPrint(UGGraph graph)
{
    int Size = graph[0].UG_Size;
    printf("\n");
    int count_empty = 0;
    /**/for(int i = 0; i<Size ;i++){
        /**/if(graph[i].firstvertex == NULL){
            count_empty++;
        } else {
            printf("Node %d:  \n",i);
            PrintVertices(graph[i].firstvertex);
            printf("End of Node %d\n",i);
        }
        /**/
    }
    /**/
    printf("The Graph has %d empty Nodes...\n",count_empty);
}

void RemoveVertex(UGVList *Cvertex,UGVList Rvertex)
{
    /**/if(*Cvertex == Rvertex) {
        *Cvertex = (*Cvertex)->nextvertex;
        free(Rvertex);
        return;
    }
    /**/
    if((*Cvertex)->nextvertex != Rvertex) RemoveVertex(&((*Cvertex)->nextvertex),Rvertex);
    /**/if((*Cvertex)->nextvertex == Rvertex){
        (*Cvertex)->nextvertex = Rvertex->nextvertex;
        free(Rvertex);
    }
    /**/
}

void UGRemoveVertex(UGGraph graph,UGVertex peak)
{
    int dir = UGHashF(&graph,peak) ;
    UGVList KOwner = SearchForVertex(graph[dir].firstvertex,peak);
    if(KOwner == NULL) return;
    RemoveVertex(&(graph[dir].firstvertex),KOwner);
    (graph[dir].Node_Size)--;
}

void FreeEdges(UGEList Cedge)
{
    if((Cedge != NULL)&&(Cedge->nextedge != NULL)) FreeEdges(Cedge->nextedge);
    if(Cedge == NULL) return;
    free(Cedge);
}

void UGDestroyUGnode(UGVList CUGnode)
{
    if((CUGnode != NULL)&&(CUGnode->nextvertex != NULL)) UGDestroyUGnode(CUGnode->nextvertex);
    if(CUGnode == NULL) return;
    free(CUGnode);
}

void UGDestroy(UGGraph graph)
{
    int Size = graph[0].UG_Size;
    /**/for(int i = 0; i<Size ;i++){
        UGDestroyUGnode(graph[i].firstvertex);
    }
    /**/
    free(graph);
}

void UGAddEdge(UGGraph graph,UGVertex Vertex1,UGVertex Vertex2)
{
    UGVList V1Ptr = SearchForVertex(graph[UGHashF(&graph,Vertex1)].firstvertex,Vertex1);
    UGVList V2Ptr = SearchForVertex(graph[UGHashF(&graph,Vertex2)].firstvertex,Vertex2);
    /**/if((V1Ptr == NULL)||(V2Ptr == NULL)){
        printf("\nERROR !!! UNRECOGNIZED VERTEX ... !!!\n");
        return ;
    }
    /**/
    InsertEdge(&(V1Ptr->firstedge),V2Ptr);
    InsertEdge(&(V2Ptr->firstedge),V1Ptr);
}

void RemoveEdge(UGEList *Cedge,UGEList Redge)
{
    /**/if(*Cedge == Redge) {
        *Cedge = (*Cedge)->nextedge;
        free(Redge);
        return;
    }
    /**/
    if((*Cedge)->nextedge != Redge) RemoveEdge(&((*Cedge)->nextedge),Redge);
    /**/if((*Cedge)->nextedge == Redge){
        (*Cedge)->nextedge = Redge->nextedge;
        free(Redge);
    }
    /**/
}

void UGRemoveEdge(UGGraph graph,UGVertex Vertex1,UGVertex Vertex2)
{
    UGVList V1Ptr = SearchForVertex(graph[UGHashF(&graph,Vertex1)].firstvertex,Vertex1);
    UGVList V2Ptr = SearchForVertex(graph[UGHashF(&graph,Vertex2)].firstvertex,Vertex2);
    /**/if((V1Ptr == NULL)||(V2Ptr == NULL)){
        printf("\nERROR !!! UNRECOGNIZED VERTEX ... !!!\n");
        return ;
    }
    /**/
    UGEList E1Ptr = SearchForEdge(V1Ptr->firstedge,Vertex2);
    UGEList E2Ptr = SearchForEdge(V2Ptr->firstedge,Vertex1);
    if((E1Ptr == NULL)&&(E2Ptr == NULL)) return;
    RemoveEdge(&(V1Ptr->firstedge),E1Ptr);    RemoveEdge(&(V2Ptr->firstedge),E2Ptr);
}

void FillADJ(UGVList *ADJList,UGEList Cedge)
{
    /**/while(Cedge != NULL){
        InsertVertex(ADJList,Cedge->EdgeV->peak);
        Cedge = Cedge->nextedge;
    }
    /**/
}

UGVList UGGetAdjacent(UGGraph graph,UGVertex Vertex)
{
    UGVList ADJList = NULL;
    UGVList VPtr = SearchForVertex(graph[UGHashF(&graph,Vertex)].firstvertex,Vertex);
    /**/if(VPtr == NULL){
        printf("\nERROR !!! VERTEX WASN'T FOUND ... !!!\n");
        return NULL;
    }
    /**/
    FillADJ(&ADJList,VPtr->firstedge);
    return ADJList;
}

void AdjacentPrint(UGVList Cvert,UGVertex Vertex)
{
    printf("\nAdjacent List of Vertex %s : \n    ",Vertex);
    /**/while(Cvert != NULL){
        printf("%s ",Cvert->peak);
        Cvert = Cvert->nextvertex;
    }
    /**/
    printf("\nEnd of Adjacent List...\n");
}

void ShortestPrint(UGVList Cvert,UGVertex Vertex1,UGVertex Vertex2)
{
    printf("\nShortest Path List of Vertex %s to Vertex %s: \n    ",Vertex1,Vertex2);
    /**/while(Cvert != NULL){
        printf("%s ",Cvert->peak);
        Cvert = Cvert->nextvertex;
        if(Cvert != NULL) printf("-> ");
    }
    /**/
    printf("\nEnd of Shortest Path List...\n");
}

UGVertex Get_U(HTHash dist,HTHash W)
{
    HTIList DistCnode,WCnode;
    int Size = dist[0].HT_Size;
    UGVertex MinV;
    int min = INT_MAX;
    /**/for(int i = 0; i<Size ;i++){
        DistCnode = dist[i].item_L;
        WCnode = W[i].item_L;
        /**/while((DistCnode != NULL)&&(WCnode != NULL)){
            /**/if((CMP_int(WCnode->item,0) == 1)&&(CMP_int(DistCnode->item,min) == 0)){
                MinV = WCnode->key;
                min = Get_Int(DistCnode->item);
            /**/}
            WCnode = WCnode->next;
            DistCnode = DistCnode->next;
        /**/}

    /**/}
    return MinV;
}

UGVList GetShortPath(HTHash prev,UGVertex src,HTItem dest)
{
    UGVList S_List = NULL;
    InsertVertex(&S_List,dest);
    /**/while(strcmp(dest,src) != 0){
        printf("\n%s = %s \n",dest,src);
        if(HTGet(prev,dest,&dest)) InsertVertex(&S_List,dest);
    /**/}
    return S_List;
}

UGVList UGShortestPath(UGGraph graph,UGVertex Vertex1,UGVertex Vertex2)
{
    int alt;
    UGVList Cvertex;
    int size = graph[0].UG_Size;
    UGVertex src  = Vertex1;
    UGVertex dest = Vertex2;
    HTHash W = HTCreate(size);
    HTHash dist = HTCreate(size) ;
    HTHash prev = HTCreate(size) ;
    /**/for(int i = 0; i<size ;i++){
        Cvertex = graph[i].firstvertex;
        /**/while(Cvertex != NULL){
            HTInsert(&dist,Cvertex->peak,PtrOfInt(INT_MAX));
            HTInsert(&W,Cvertex->peak,PtrOfInt(0));
            HTInsert(&prev,Cvertex->peak,"NULL");
            Cvertex = Cvertex->nextvertex;
        /**/}
    /**/}
    HTInsert(&dist,Vertex1,PtrOfInt(0));
    UGVertex u;
    HTItemPtr temp = malloc(sizeof(HTItem));
    /**/while(true){
        u = Get_U(dist,W);
        HTInsert(&W,u,PtrOfInt(1));
        if(strcmp(u,dest) == 0) break;
        UGVList u_Adj = UGGetAdjacent(graph,u);
        /**/while(u_Adj != NULL){
            /**/if((HTGet(W,u_Adj->peak,temp))&&(CMP_int(*temp,1) == 1)){
                u_Adj = u_Adj->nextvertex;
                continue;
            /**/}
                if(HTGet(dist,u,temp)) alt = Get_Int(*temp) + 1;
                /**/if((HTGet(dist,u_Adj->peak,temp))&&(CMP_int(*temp,alt) >= 1)){
                    HTInsert(&dist,u_Adj->peak,PtrOfInt(alt));
                    HTInsert(&prev,u_Adj->peak,u);
                /**/}
            u_Adj = u_Adj->nextvertex;
        /**/}
    /**/}
    if((HTGet(dist,dest,temp))&&(CMP_int(*temp,INT_MAX) == 1)) return NULL;
    HTPrint(dist,print_INT);
    HTPrint(W,print_INT);
    HTPrint(prev,print_CHAR);
    UGVList Short_Path = GetShortPath(prev,src,dest);
    return Short_Path;
}
