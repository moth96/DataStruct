#ifndef __LIST_H__
#define __LIST_H__

#include<stdlib.h>
#include<stdio.h>

//宏定义
typedef int ElementType;
typedef struct SingleLink* PtrToNode;
typedef PtrToNode List;

//函数名
int IsEmpty(List L);
List NewNode(ElementType Element);
void Append(List L, ElementType Element);
void PrintList(List L);
void ClearList(List L);
List ArrayToList(ElementType Array[], int NumSize);
List ReverseList(List L);
void Delete(List L, ElementType X);
ElementType* Pop(List L);
List SortList(List L);

struct SingleLink
{
    ElementType Element;
    List Next;
};

#endif                  /* __LIST_H__ */#pragma once
