#include <stdio.h>

#include <stdlib.h>

#include <stdbool.h>

typedef struct node {

  int data;

  struct node *next, *prev;

} node, *linklist;

//初始化链表

node* initList()

{

  node* h=(linklist)malloc(sizeof(node));

  h->data=0;

  h->next=NULL;

  h->prev=NULL;

  return h;

}

// 头插入

void insertHead(linklist &l,int e)

{

  node* p=(linklist)malloc(sizeof(node));

  p->data=e;

  p->next = l->next;

  if (l->next != NULL) {

    l->next->prev = p;

  }

  p->prev = l;

  l->next = p;

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

// 尾插入

void insertTail(linklist &l,int e)

{

  node* p=getTail(l);

  node* tail=(linklist)malloc(sizeof(node));

  tail->data=e;

  p->next=tail;

  tail->prev=p;

  tail->next=NULL;

}

// 在位置i插入节点

bool insertNode(linklist &l, int i, int e)

{

  if (i < 1)

    return false;

  

  node *p = l;

  int j = 0;

  while (p != NULL && j < i - 1) {

​    p = p->next;

​    j++;

  }

  if (p == NULL)

    return false;

  

  node* q=(linklist)malloc(sizeof(node));

  q->data=e;

  q->prev=p;

  q->next=p->next;

  p->next->next=q;

  p->next=q;

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

  q->next->prev=p;

  free(q);

  return true;

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

// 打印双向链表

void printList(linklist &l) {

  node* p = l->next;

  while (p != NULL) {

    printf("%d ", p->data);

    p = p->next;

  }

  printf("\n");

}

int main()

{

  node* l=initList();

  insertHead(l,3);

  printList(l);

  return 0;

}