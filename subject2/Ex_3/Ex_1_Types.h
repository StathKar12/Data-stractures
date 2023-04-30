typedef int BTItem;
typedef struct nd* BTNode;
typedef struct nd{
    BTItem item;
    BTNode left;
    BTNode right;
}BTN;
typedef struct head{
    int Nnum;
    BTNode Fnode;
} BTTree;
