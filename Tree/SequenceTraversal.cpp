//
//  SequenceTraversal.cpp
//  test
//
//  Created by WhiteShark on 2020/11/2.
//  Copyright © 2020 WhiteShark. All rights reserved.
//

#include<stdio.h>
#include<stdlib.h>

typedef struct BiTNode{
    int data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

typedef struct LinkNode {
    BiTree data;
    struct LinkNode *next;
}LinkNode;
typedef struct {
    LinkNode *front;        //头指针
    LinkNode *rear;         //尾指针
}LinkQueue;
//初始化
void InitQueue(LinkQueue Q){
    Q.front = Q.rear = (LinkNode*)malloc(sizeof(LinkNode));
    Q.front -> next = NULL;
}

//判空
bool IsEmpty(LinkQueue Q){
    if(Q.front == Q.rear){
        return true;
    }
    else {
        return false;
    }
}

//元素入队（带头节点）
void EnQueue(LinkQueue &Q,BiTree T){
    LinkNode *s = (LinkNode*)malloc(sizeof(LinkNode));
    s -> data = T;
    s -> next = NULL;
    Q.rear -> next = s;
    Q.rear = s;
}

//元素出队（带头节点）
bool DeQueue(LinkQueue &Q,BiTree &x){
    if (Q.front == Q.rear) {
        return false;
    }
    LinkNode *p = Q.front -> next;
    x = p -> data;
    Q.front -> next = p -> next;
    if (Q.rear == p) {
        Q.rear = Q.front;
    }
    free(p);
    return true;
}

void visit(BiTree T){
    printf("%d/n",T->data);
}

void LevelOrder(BiTree T){
    LinkQueue Q;
    InitQueue(Q);
    BiTree p;
    EnQueue(Q, T);
    while (!IsEmpty(Q)) {
        DeQueue(Q, p);
        visit(p);
        if (p->lchild !=NULL) {
            EnQueue(Q, p->lchild);
        }
        if (p->rchild!=NULL) {
            EnQueue(Q, p->rchild);
        }
    }
    
    
}
