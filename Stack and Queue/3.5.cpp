//
//  3.5.cpp
//  test
//
//  Created by WhiteShark on 2020/9/26.
//  Copyright © 2020 WhiteShark. All rights reserved.
//

//P85 2

#include<stdio.h>
#include<stdlib.h>

#define MaxSize 50
//链式队列
typedef struct LinkNode{
    int data;
    LinkNode *next;
}LinkNode;

typedef struct {
    LinkNode *front;
    LinkNode *rear;
}LinkQueue;

//链栈
typedef struct LNode{
    int data;
    struct LNode *next;
}LNode,*LinkStack;


//队列初始化
void Init(LinkQueue &Q){
    Q.front = Q.rear = (LinkNode*)malloc(sizeof(LinkNode));
    Q.front -> next = NULL;
}
//队列判空
bool isEmpty(LinkQueue Q){
    if (Q.front == Q.rear) {
        return true;
    }
    else {
        return false;
    }
    
}
//元素入队（带头节点）
void EnQueue(LinkQueue &Q,int x){
    LinkNode *s = (LinkNode*)malloc(sizeof(LinkNode));
    s -> data = x;
    s -> next = NULL;
    Q.rear -> next = s;
    Q.rear = s;
}
//元素出队（带头节点）
bool DeQueue(LinkQueue &Q,int &x){
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
//栈初始化
bool InitStack(LinkStack &S){
    S = (LNode *)malloc(sizeof(LNode));
    if(S==NULL){
        return false;
    }
    S->next=NULL;
    return true;
}
bool Empty(LinkStack L){
    if(L->next==NULL){
        return true;
    }
    else {
        return false;
    }
}
//入栈
bool EnStack(LNode *p,int e){
    LNode *s = (LNode *)malloc(sizeof(LNode));
    if (s == NULL) {
        return false;
    }
    s -> data = e;
    s -> next = p->next;
    p -> next = s;
    return true;
}
//出栈
bool DeStack(LinkStack &S,int &x){
    LNode *p = S -> next;
    x = p -> data;
    S -> next = p -> next;
    free(p);
    return true;
}

void Inverser(LinkStack &S, LinkQueue &Q){
    int x;
    while (!isEmpty(Q)) {
        DeQueue(Q, x);
        EnStack(S, x);
    }
    while (!Empty(S)) {
        DeStack(S, x);
        EnQueue(Q, x);
    }
}

int main(){
    LinkStack S;
    InitStack(S);
    LinkQueue Q;
    Init(Q);
    EnQueue(Q, 1);
    EnQueue(Q, 2);
    EnQueue(Q, 3);
    EnQueue(Q, 4);
    EnQueue(Q, 5);
    Inverser(S, Q);
    int x;
    while (!isEmpty(Q)) {
        DeQueue(Q, x);
        printf("%d\n",x);
    }
    return 0;
}


