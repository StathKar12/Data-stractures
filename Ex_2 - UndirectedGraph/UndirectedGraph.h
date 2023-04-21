#include "UndirectedGraph_Types.h"
#include <limits.h>

UGGraph UGCreate(int Size);
int UGSize(UGGraph graph);
UGGraph UGUpgradeGraph(UGGraph graph);
int UGHashF(UGGraphPtr graph,UGVertex peak);
UGVList SearchForVertex(UGVList List,UGVertex peak);
UGEList SearchForEdge(UGEList Cedge,UGVertex peak);
void InsertVertex(UGVList *Cnode,UGVertex peak);
void InsertEdge(UGEList *Cedge,UGVList ToV);
void UGAddVertex(UGGraphPtr graph,UGVertex peak);
void PrintEdges(UGEList Cedge);
void PrintVertices(UGVList Cvert);
void UGPrint(UGGraph graph);
void RemoveVertex(UGVList *Cvertex,UGVList Rvertex);
void UGRemoveVertex(UGGraph graph,UGVertex peak);
void FreeEdges(UGEList Cedge);
void UGDestroyNode(UGVList Cnode);
void UGDestroy(UGGraph graph);
void UGAddEdge(UGGraph graph,UGVertex Vertex1,UGVertex Vertex2);
void RemoveEdge(UGEList *Cedge,UGEList Redge);
void UGRemoveEdge(UGGraph graph,UGVertex Vertex1,UGVertex Vertex2);
void FillADJ(UGVList *ADJList,UGEList Cedge);
UGVList UGGetAdjacent(UGGraph graph,UGVertex Vertex);
void AdjacentPrint(UGVList Cvert,UGVertex Vertex);
void ShortestPrint(UGVList Cvert,UGVertex Vertex1,UGVertex Vertex2);
UGVList UGShortestPath(UGGraph graph,UGVertex Vertex1,UGVertex Vertex2);
