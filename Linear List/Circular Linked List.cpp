#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int data;
    struct node *next;
} node, *linklist;

// 判断链表是否内涵循环链表
int isCycle(linklist &l)
{
    node* f=l;
    node* s=l;
    while(f!=NULL && f->next!=NULL)
    {
        f=f->next->next;
        s=s->next;
        if(f==s)
            return 1;
    }
    return 0;
}

// 寻找链表循环的起点
int find

int main()
{
    return 0;
}