#pragma once
#include "Ex_5_Types.h"

void DeleteLast(stp beginL);
void free_L(stp listl);
void addL(stp current,char item[20]);
stp Create();
void InsertLast(stp beginL,char item[20]);
void Print(stp beginL,WordS word);
int compare(const void *A,const void *B);
WordS Nword(WordS Cword,int wh,int to);
void Similar(WordS Fwords,WordS *library);
int Find_F_size(char *file);
WordS *ReadFile(char *file);
void Print_LiB(WordS *LiB);
