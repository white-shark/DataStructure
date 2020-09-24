//
//  Chainqueue.cpp
//  test
//
//  Created by WhiteShark on 2020/9/22.
//  Copyright © 2020 WhiteShark. All rights reserved.
//
//链式队列
#include<stdio.h>
#include<stdlib.h>
typedef struct LinkNode {
    int data;
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
void EnQueue(LinkQueue &Q,int x){
    LinkNode *s = (LinkNode*)malloc(sizeof(LinkNode));
    s -> data = x;
    s -> next = NULL;
    Q.rear -> next = s;
    Q.rear = s;
}

//元素入队（不带头节点）
void EnQueue2(LinkQueue &Q,int x){
    LinkNode *s = (LinkNode*)malloc(sizeof(LinkNode));
    s -> data = x;
    s -> next = NULL;
    if (Q.front == NULL) {
        Q.front = s;
        Q.rear = s;
    }
    else{
        Q.rear -> next = s;
        Q.rear = s;
    }
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

//元素出队（不带头节点）
bool DeQueue2(LinkQueue &Q, int &x){
    if (Q.front == Q.rear) {
        return NULL;
    }
    LinkNode *p = Q.front;
    x = p -> data;
    Q.front = p -> next;
    if (Q.rear == p) {
        Q.rear = NULL;
        Q.front = NULL;
    }
    free(p);
    return true;
}

