#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "HashTable.h"

void User_Visit(HTHash hash,HKey key,HTItem item)
{
    HTItemPtr pitem = malloc(sizeof(HTItem));
    /**/if(HTGet(hash,key,pitem) == 1){
        printf("\nKey's \"%s\" item value is :",key);
        printf("%d\n",*((int*)(*pitem)));
    }
    /**/
}


///*// INT
int main(void)
{
    printf("Creating a hash:\n");
    HTHash hash = HTCreate(5);
    int size = HTSize(hash);
    printf("\nHash size = %d\n",size);
    printf("\nPrinting the hash...\n");
    printf("\nFilling the hash... \n");
    HTPrint(hash,print_INT);
    int num = 6;
    HTInsert(&hash,"a5",&num);
    int num1 = 8;
    HTInsert(&hash,"d5",&num1);
    int num2 = 11;
    HTInsert(&hash,"c5",&num2);
    int num3 = 17;
    HTInsert(&hash,"v5",&num3);
    int num4 = 26;
    HTInsert(&hash,"b5",&num4);
    int num5 = 50;
    HTInsert(&hash,"g7",&num5);
    printf("\nALL GOOD\n");
    num2 = 34;
    HTInsert(&hash,"c5",&num2);
    int num6 = 68;
    HTInsert(&hash,"4",&num6);
    size = HTSize(hash);
    printf("\nHash size = %d\n",size);
    HTPrint(hash,print_INT);
    printf("\nRemoving the key \"c5\" with item value %d...\n",num2);
    HTRemove(hash,"c5");
    size = HTSize(hash);
    printf("\nHash size = %d\n",size);
    HTPrint(hash,print_INT);
    printf("\nRe-entering the key \"c5\" with item value %d...\n",num2);
    HTInsert(&hash,"c5",&num2);
    size = HTSize(hash);
    printf("\nHash size = %d\n",size);
    HTPrint(hash,print_INT);
    printf("\nSearching key \"g7\" in the hash using HTGet function...\n");
    HTItem pitem ;
    if(HTGet(hash,"g7",&pitem) == 1){
        printf("\nSearch for key \"g7\" is complete... :");
        printf(" item value = %d\n",*((int*)(pitem)));
    } else {
        printf("\nNot found\n");
    }
    printf("\nVisiting all hash entries using HTVisit function...\n");
    HTVisit(hash,User_Visit);
    printf("\nDestroying hash using HTDestroy function...\n");
    HTDestroy(hash);
    return 0;
}
//*/
/*// CHAR
int main(void)
{
    HTHash hash = HTCreate();
    int size = HTSize(hash);
    printf("\nsize = %d\n",size);
    HTInsert(&hash,"a5","a5");
    HTInsert(&hash,"d5","d5");
    HTInsert(&hash,"c5","c5");
    HTInsert(&hash,"v5","v5");
    HTInsert(&hash,"b5","b5");
    HTInsert(&hash,"g7","g7");
    HTPrint(hash,print_CHAR);
    HTInsert(&hash,"c5","c5");
    HTInsert(&hash,"4","4");
    size = HTSize(hash);
    printf("\nsize = %d\n",size);
    HTPrint(hash,print_CHAR);
    printf("\nRemoving the key \"c5\"\n");
    HTRemove(hash,"c5");
    HTPrint(hash,print_CHAR);
    size = HTSize(hash);
    printf("\nsize = %d\n",size);
    HTItemPtr pitem = malloc(sizeof(HTItem));
    if(HTGet(hash,"g7",pitem) == 1){
        printf("\nfound\n");
        printf("\n%s\n",(char *)(*pitem));
    }
    HTDestroy(hash);
    printf("\n...ALL GOOD...\n");
    return 0;
}
*/
/*// DOUBLE
int main(void)
{
    HTHash hash = HTCreate();
    int size = HTSize(hash);
    printf("\nsize = %d\n",size);
    double num = 6.1;
    HTInsert(&hash,"a5",&num);
    double num1 = 8.2;
    HTInsert(&hash,"d5",&num1);
    double num2 = 11.3;
    HTInsert(&hash,"c5",&num2);
    double num3 = 17.4;
    HTInsert(&hash,"v5",&num3);
    double num4 = 26.5;
    HTInsert(&hash,"b5",&num4);
    double num5 = 50.6;
    HTInsert(&hash,"g7",&num5);
    HTPrint(hash,print_DOUBLE);
    double num6 = 34.7;
    HTInsert(&hash,"c5",&num6);
    double num7 = 68.8;
    HTInsert(&hash,"4",&num7);
    size = HTSize(hash);
    printf("\nsize = %d\n",size);
    HTPrint(hash,print_DOUBLE);
    printf("\nRemoving the key \"c5\"\n");
    HTRemove(hash,"c5");
    HTPrint(hash,print_DOUBLE);
    size = HTSize(hash);
    printf("\nsize = %d\n",size);
    HTItemPtr pitem = malloc(sizeof(HTItem));
    if(HTGet(hash,"g7",pitem) == 1){
        printf("\nfound\n");
        printf("\n%lf\n",*((double*)(*pitem)));
    }
    HTDestroy(hash);
    printf("\n...ALL GOOD...\n");
    return 0;
}
*/
/*// FLOAT
int main(void)
{
    HTHash hash = HTCreate();
    int size = HTSize(hash);
    printf("\nsize = %d\n",size);
    float num = 6.1;
    HTInsert(&hash,"a5",&num);
    float num1 = 8.2;
    HTInsert(&hash,"d5",&num1);
    float num2 = 11.3;
    HTInsert(&hash,"c5",&num2);
    float num3 = 17.4;
    HTInsert(&hash,"v5",&num3);
    float num4 = 26.5;
    HTInsert(&hash,"b5",&num4);
    float num5 = 50.6;
    HTInsert(&hash,"g7",&num5);
    HTPrint(hash,print_FLOAT);
    float num6 = 34.7;
    HTInsert(&hash,"c5",&num6);
    float num7 = 68.8;
    HTInsert(&hash,"4",&num7);
    size = HTSize(hash);
    printf("\nsize = %d\n",size);
    HTPrint(hash,print_FLOAT);
    printf("\nRemoving the key \"c5\"\n");
    HTRemove(hash,"c5");
    HTPrint(hash,print_FLOAT);
    size = HTSize(hash);
    printf("\nsize = %d\n",size);
    HTItemPtr pitem = malloc(sizeof(HTItem));
    if(HTGet(hash,"g7",pitem) == 1){
        printf("\nfound\n");
        printf("\n%f\n",*((float*)(*pitem)));
    }
    HTDestroy(hash);
    printf("\n...ALL GOOD...\n");
    return 0;
}
*/
