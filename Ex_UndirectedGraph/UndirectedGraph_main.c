#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "UndirectedGraph.h"

int main(void)
{
    UGGraph graph = UGCreate(16);
    UGAddVertex(&graph,"AAA");
    UGAddVertex(&graph,"AAb");
    UGAddVertex(&graph,"AAc");
    UGAddVertex(&graph,"AAd");
    UGAddVertex(&graph,"AAg");
    UGAddVertex(&graph,"AAf");
    UGAddVertex(&graph,"bAA");
    UGAddVertex(&graph,"bAb");
    UGAddVertex(&graph,"bAc");
    UGAddVertex(&graph,"bAd");
    UGAddVertex(&graph,"bAg");
    UGAddVertex(&graph,"bAf");
    UGAddVertex(&graph,"DAA");
    UGAddVertex(&graph,"DAb");
    UGAddVertex(&graph,"DAc");
    UGAddVertex(&graph,"DAd");
    UGAddVertex(&graph,"DAg");
    UGAddVertex(&graph,"DAf");
    UGAddEdge(graph,"AAA","bAb");
    UGAddEdge(graph,"AAA","DAf");
    UGAddEdge(graph,"DAf","DAA");
    UGAddEdge(graph,"DAb","bAb");
    UGAddEdge(graph,"DAf","DAb");
    UGAddVertex(&graph,"ABA");
    UGAddVertex(&graph,"ABb");
    UGAddVertex(&graph,"ABc");
    UGAddVertex(&graph,"ABd");
    UGAddVertex(&graph,"ABg");
    UGAddVertex(&graph,"ABf");
    UGVList ADJ = UGGetAdjacent(graph,"AAA");
    AdjacentPrint(ADJ,"AAA");
    UGVList ADJ3 = UGGetAdjacent(graph,"DAA");
    AdjacentPrint(ADJ3,"DAA");
    UGVList ADJ4 = UGGetAdjacent(graph,"DAc");
    AdjacentPrint(ADJ4,"DAc");
    UGPrint(graph);
    UGRemoveVertex(graph,"bAd");
    UGRemoveEdge(graph,"AAA","DAf");
    UGVList ADJ2 = UGGetAdjacent(graph,"AAA");
    AdjacentPrint(ADJ2,"AAA");
    UGPrint(graph);
    UGVList Short_Path = UGShortestPath(graph,"AAA","DAA");
    ShortestPrint(Short_Path,"AAA","DAA");
    UGDestroy(graph);
    return 0;
}
