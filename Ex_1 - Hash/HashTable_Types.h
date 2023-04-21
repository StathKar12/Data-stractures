#define TRUE  1
#define FALSE 0

typedef void* HTItem ;
typedef HTItem*   HTItemPtr;
typedef char*     HKey   ;

//HASH_NODE
typedef struct Lpoint*   HTIList;
typedef struct Lpoint{
    HTItem item;
    HTIList next;
    HKey   key ;
} node_L;

//HASH
typedef struct point*   HTHash;
typedef struct point{
    int   Size;
    int   HT_Size;
    HTIList item_L;
}node;
typedef HTHash* HTHashPtr;
typedef void (*Print)(HTIList Cnode);
typedef void (*Visit)(HTHash hash,HKey key,HTItem item);
