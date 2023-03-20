#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Ex_5.h"
#define L_FILE "words"

void DeleteLast(stp beginL)
{
    /**/while(beginL->next->next != NULL){
        beginL = beginL->next;
    }
    /**/
    free(beginL->next);
    beginL->next = NULL;
}

void free_L(stp listl)
{
    /**/while(listl->next != NULL){
        DeleteLast(listl);
    }
    /**/
}

void addL(stp current,char item[20])
{
    /**/if(strcmp(current->air,"NULL") == 0){
        strcpy(current->air,item);
    }
    else {
        stp temp = malloc(sizeof(str));
        temp->next = current->next;
        current->next = malloc(sizeof(str));
        current->next->next = temp->next;
        strcpy(current->next->air,item);
    }
    /**/
}

stp Create()
{
    stp newl = malloc(sizeof(str));
    newl->next = NULL;
    strcpy(newl->air,"NULL");
    return newl;
}

void InsertLast(stp beginL,char item[20])
{
    /**/while(beginL->next != NULL){
        beginL = beginL->next;
    }
    /**/
    addL(beginL,item);
}

void Print(stp beginL,WordS word)
{
    printf("\nSimilar words of \"%s\":\n  %s ",word,beginL->air);
    beginL = beginL->next;
    /**/while(beginL != NULL){
        printf(", %s ",beginL->air);
        beginL = beginL->next;
    }
    /**/
    printf("\n");
}

int compare(const void *A,const void *B)
{
    const char **WA = (const char**)A;
    const char **WB = (const char**)B;
    return strcmp(*WA,*WB);
}

WordS Nword(WordS Cword,int wh,int to)
{
    Cword[wh] = 'a'+to;
    return Cword;
}

void Similar(WordS Fwords,WordS *library)
{
    stp SwordL = Create();
    int i = 0;
    WordS CNword = malloc(sizeof(WordS));
    /**/while(Fwords[i] != '\0'){
        strcpy(CNword,Fwords);
        int n = 0;
       /**/while(n != 23){
           if(Fwords[i] == ('a'+n)) n++;
           CNword = Nword(CNword,i,n);
           if(bsearch(&CNword,library,Vsize,sizeof(WordS),compare) != NULL) InsertLast(SwordL,CNword);
           n++;
       }
       /**/
       i++;
    }
    /**/
    Print(SwordL,Fwords);
    free_L(SwordL);
}

int Find_F_size(char *file)
{
    FILE *fM = fopen(file, "r");
    /**/if(fM == NULL){
        printf("FILE \"%s\" wasn't found !!!\n",file);
        exit(2);
    }
    /**/
    int counter = 0;
    char word[20];
    /**/while(fscanf(fM,"%s",word)!=EOF){
        counter++;
    }
    /**/
    fclose(fM);
    return counter;
}

WordS *ReadFile(char *file)
{
    Vsize = Find_F_size(file);
    FILE *fM = fopen(file, "r");
    /**/if(fM == NULL){
        printf("FILE \"%s\" wasn't found !!!\n",file);
        exit(1);
    }
    /**/
    WordS *LiB = malloc(Vsize*sizeof(WordS));
    int i = 0;
    char word[20];
    /**/while((fscanf(fM,"%s",word)) != EOF){
        /**/if(i < Vsize) {
            LiB[i] = malloc(sizeof(WordS));
            strcpy(LiB[i],word);
        }
        /**/
        i++;
    }
    /**/
    fclose(fM);
    return LiB;
}

void Print_LiB(WordS *LiB)
{
    int i;
    printf("File %s:\n\n",L_FILE);
    /**/for(i = 0 ; i < Vsize ; i++){
        printf("   %s\n",LiB[i]);
    }
    /**/
}
