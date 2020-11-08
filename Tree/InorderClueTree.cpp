//
//  InorderClueTree.cpp
//  test
//
//  Created by WhiteShark on 2020/11/8.
//  Copyright © 2020 WhiteShark. All rights reserved.
//

#include<stdio.h>
#include<stdlib.h>

typedef struct ThreadNode{
    int data;
    struct ThreadNode *lchild,*rchild;
    int ltag,rtag;
}ThreadNode,* ThreadTree;

ThreadNode *pre = NULL;

void visit(ThreadNode *q){
    if (q->lchild==NULL) {
        q->lchild=pre;
        q->ltag=1;
    }
    if (pre!=NULL && pre->rchild==NULL) {
        pre->rchild=q;
        pre->rtag=1;
    }
    pre=q;
}

void InThread(ThreadTree T){
    if (T!=NULL) {
        InThread(T->lchild);
        visit(T);
        InThread(T->rchild);
    } 
}

void CreatInThread(ThreadTree T){
    pre = NULL;
    if(T!=NULL){
        InThread(T);
        if (pre->rchild == NULL) {
            pre->rtag = 1;
        }
    }
}

//王道教材版
void InThread1(ThreadTree p,ThreadTree &pre){
    if (p!=NULL) {
        InThread1(p->lchild,pre);
        if (p->lchild==NULL) {
            p->lchild = pre;
            p->ltag = 1;
        }
        if (pre != NULL && pre->rchild == NULL) {
            pre->rchild = p;
            pre->rtag = 1;
        }
        pre = p;
        InThread1(p->rchild,pre);
    }
}

void CreateInThread1(ThreadTree T){
    ThreadTree pre1 = NULL;
    if (T!=NULL) {
        InThread1(T, pre1);
        pre1->rchild = NULL;
        pre1->rtag = 1;
    }
}

