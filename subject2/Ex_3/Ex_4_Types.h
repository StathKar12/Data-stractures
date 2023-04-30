typedef int CBTItem;
typedef struct nd* CBTNode;
typedef struct nd{
    CBTItem item;
    CBTNode left;
    CBTNode right;
}CBTN;
typedef struct head{
    int Nnum;
    CBTNode Fnode;
} CBTTree;
