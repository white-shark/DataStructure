//
// Created by 72778 on 2020/5/22.
//
#include<stdio.h>
#include<stdlib.h>

typedef struct DNode{
    int data;
    struct DNode *prior;
    struct DNode *next;
}DNode,*DLinklist;

bool InitDLinkList(DLinklist &L){
    L=(DNode *)malloc(sizeof(DNode));
    if(L==false){
        return false;
    }
    L->prior = NULL;
    L->next = NULL;
    return true;
}

bool InsertNextDNode(DNode *p,DNode *s){	//在p节点之后插s入节点
    if(p==NULL || s==NULL){
        return false;
    }
    s->next = p->next;
    if(p->next !=NULL){
        p->next->prior=s;
    }
    s->prior = p;
    p->next = s;
    return true;
}

bool DeleteNextNode(DNode *p){
    if(p==NULL){
        return false;
    }
    DNode *q = p->next;
    if(q==NULL){
        return false;
    }
    p->next = q->next;
    if(q->next!=NULL){
        q->next->prior=p;
    }
    free(q);
    return true;
}

DLinklist FindDNode(DNode *p){
    while(p->prior != NULL){
        p=p->prior;
    }
    return p;
}

int main(){
    DLinklist L;
    InitDLinkList(L);
}
