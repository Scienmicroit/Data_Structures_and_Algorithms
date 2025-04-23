#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int data;
    struct node *next;
} node, *linklist;

// 初始化链表
bool initList(linklist &l) {
    l = (linklist)malloc(sizeof(node));
    if (l == NULL)
        return false;
    l->next = NULL;
    return true;
}

// 头插入
void insertHead(linklist &l, int e) {
    node *s = (node *)malloc(sizeof(node));
    s->data = e;
    s->next = l->next;
    l->next = s;
}

// 尾插入
node* insertTail(node *tail, int e) {
    node *p = (node *)malloc(sizeof(node));
    p->next = NULL;
    p->data = e;
    tail->next = p;
    return p; // 返回新的尾节点
}

// 获取尾节点
node* getTail(linklist &l) {
    if (l == NULL)
        return NULL;
    
    node *p = l;
    while (p->next != NULL) {
        p = p->next;
    }
    return p;
}

// 在位置i插入节点
bool insertNode(linklist &l, int i, int e) {
    if (i < 1)
        return false;
    
    node *p = l;
    int j = 0;
    while (p != NULL && j < i - 1) {
        p = p->next;
        j++;
    }

    if (p == NULL)
        return false;
    
    node *newNode = (node *)malloc(sizeof(node));
    if (newNode == NULL)
        return false;
    
    newNode->data = e;
    newNode->next = p->next;
    p->next = newNode;
    return true;
}

// 删除节点
bool deleteNode(linklist &l, int i) {
    if (i < 1)
        return false;
    
    node *p = l;
    int j = 0;
    while (p != NULL && j < i - 1) {
        p = p->next;
        j++;
    }

    if (p == NULL || p->next == NULL)
        return false;
    
    node *q = p->next;
    p->next = q->next;
    free(q);
    return true;
}

// 打印链表
void printList(linklist &l) {
    node *p = l->next;  // 跳过头节点
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

// 获取链表长度（包括头节点）
int getLength(linklist &l) {
    node *p = l;
    int len = 0;
    while (p != NULL) {
        p = p->next;
        len++;
    }
    return len;
}

// 释放链表（不包括头节点）
void releaseList(linklist &l) {
    node *p = l->next;
    node *q;
    while (p != NULL) {
        q = p->next;
        free(p);
        p = q;
    }
    l->next = NULL;
}

// 释放整个链表（包括头节点）
void destroyList(linklist &l) {
    releaseList(l);
    free(l);
    l = NULL;
}

// 利用双指针查找链表倒数第k个节点   双指针应用较为广泛
int findNodeFS(linklist &l,int k){
    node* f=l->next;
    node* s=l->next;
    for(int i=0;i<k;i++)
    {
        f=f->next;
    }
    while(f!=NULL)
    {
        f=f->next;
        s=s->next;
    }
    return s->data;
}

// 反转链表  三指针
node* reverseList(linklist &l)
{
    node* first=NULL;
    node* second=l->next;
    node* third;
    while(second!=NULL)
    {
        third=second->next;
        second->next=first;
        first=second;
        second=third;
    }
    linklist h=(linklist)malloc(sizeof(node));// 创建新的头节点
    h->next=first;
    return h;
}

int main() {
    linklist l;
    if (!initList(l)) {
        printf("初始化链表失败\n");
        return 1;
    }

    insertNode(l, 1, 1);  // 在位置1插入1
    insertNode(l, 2, 2);  // 在位置2插入2
    
    node *tail = getTail(l);
    if (tail != NULL) {
        tail = insertTail(tail, 3); // 更新尾指针
    }

    printList(l);  // 输出链表内容
    
    node* h=reverseList(l);// 反转链表

    printList(h);  // 输出链表内容

    destroyList(h); // 释放整个链表

    return 0;
}