#include"list.h"

//判断链表是否为空，空则返回1,非空则返回0
int IsEmpty(List L)
{
    return L->Next == NULL;
}

//生成链表的一个新的结点
List NewNode(ElementType X)
{
    List L = NULL;
    L = (struct SingleLink*)malloc(sizeof(struct SingleLink));
    L->Element = X;
    L->Next = NULL;
    return L;
}

//在链表后追加元素
void Append(List L, ElementType X)
{
    List P;
    P = L;
    List L1 = NewNode(X);
    if (P->Next == NULL)
    {
        P->Next = L1;
    }
    else
    {
        while (P->Next != NULL)
        {
            P = P->Next;
        }
        P->Next = L1;
    }
}

//删除并返回链表的最后一个数据
ElementType* Pop(List L)
{
    ElementType* PopElement = NULL;
    PopElement = (ElementType*)malloc(sizeof(ElementType));
    List P = L;
    if (P == NULL)
        return PopElement;
    if (P->Next == NULL)
    {
        PopElement = &(P->Element);
        P = NULL;
        return PopElement;
    }
    while (P)
    {
        if (P->Next->Next != NULL)
            P = P->Next;
        else
        {
            PopElement = &(P->Next->Element);
            P->Next = NULL;
            return PopElement;
        }
    }
    return PopElement;
}

//打印链表
void PrintList(List L)
{
    List P;
    P = L;
    printf("Header->");
    P = P->Next;
    while (P != NULL)
    {
        printf("%d->", P->Element);
        P = P->Next;
    }
    printf("NULL");
    putchar('\n');
}

//清空链表
void ClearList(List L)
{
    List P, Tmp;
    P = L->Next;
    L->Next = NULL;
    while (P != NULL)
    {
        Tmp = P->Next;
        free(P);
        P = Tmp;
    }
}

//将一个数组转换为链表
List ArrayToList(ElementType Array[], int NumSize)
{
    int n = NumSize;
    List L = NewNode(0);
    for (int i = 0; i < n; i++)
    {
        Append(L, Array[i]);
    }
    return L;
}

//反转链表
List ReverseList(List L)
{
    List rL = NULL;
    List pre = NULL;
    L = L->Next;
    while (L != NULL)
    {
        List ne = L->Next;
        if (ne == NULL)
        {
            rL = L;
        }
        L->Next = pre;
        pre = L;
        L = ne;
    }
    List head = NewNode(0);
    head->Next = rL;
    rL = head;
    return rL;
}

//删除链表指定元素
void Delete(List L, ElementType X)
{
    List* dL = &(L->Next);
    List temp = NULL;
    for (; *dL; dL = &((*dL)->Next))
    {
        if ((*dL)->Element == X)
        {
            temp = *dL;
            *dL = (*dL)->Next;
            free(temp);
            break;
        }
    }
}

//交换链表元素
void swap(ElementType* a, ElementType* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

//按某个特定值将链表切分成大于或者小于它的两部分
List Partion(List Left, List Right)
{
    if (Left == Right || Left->Next == Right)
        return Left;
    int pivot = Left->Element;
    List p1 = Left, p2 = Left->Next;
    while (p2 != Right)
    {
        if (p2->Element < pivot)
        {
            p1 = p1->Next;
            swap(&p1->Element, &p2->Element);
        }
        p2 = p2->Next;
    }
    swap(&p1->Element, &Left->Element);
    return p1;
    free(p2);
}

//快速排序
void QuickSort(List Left, List Right)
{
    if (Left == Right || Left->Next == Right)
        return;
    List Mid = Partion(Left, Right);
    QuickSort(Left, Mid);
    QuickSort(Mid->Next, Right);
}

//链表排序
List SortList(List L)
{
    List P = L->Next;
    if (P == NULL || P->Next == NULL)
        return L;
    QuickSort(P, NULL);
    L->Next = P;
    return L;
}
