typedef int BHItem;
typedef int BHPriority;
typedef struct nd* BHNode;
typedef struct nd{
    BHItem item;
    BHPriority priority;
    BHNode parent;
    BHNode left;
    BHNode right;
}BHN;
typedef struct head{
    int Nnum;
    BHNode Fnode;
} Heap;

