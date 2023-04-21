#pragma once
typedef enum {false,true} Boolean;
typedef char*  UGVertex;
typedef struct Vpoint*   UGVList;
typedef struct edge* UGEList;

//Edge_NODE
typedef struct edge{
	UGEList nextedge;
	UGVList EdgeV;
} Edge;

//UG_NODE
typedef struct Vpoint{
	UGEList firstedge;
    UGVList nextvertex;
    UGVertex   peak ;
} V_node;

//UG
typedef struct UGpoint*   UGGraph;
typedef struct UGpoint{
    int   Node_Size;
    int   UG_Size  ;
    UGVList firstvertex;
}UGnode;
typedef UGGraph* UGGraphPtr;
