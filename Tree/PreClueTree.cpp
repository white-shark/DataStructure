//
//  PreClueTree.cpp
//  test
//
//  Created by WhiteShark on 2020/11/9.
//  Copyright © 2020 WhiteShark. All rights reserved.
//先序线索化

#include<stdio.h>
#include<stdlib.h>

typedef struct ThreadNode{
    int data;
    struct ThreadNode *lchild,*rchild;
    int ltag,rtag;
}ThreadNode,* ThreadTree;

ThreadNode *pre = NULL;

void visit(ThreadNode *q){
    if(q->lchild == NULL){
        q->lchild = pre;
        q->ltag = 1;
    }
    if(pre != NULL && pre->rchild == NULL){
        pre->rchild = q;
        pre->rtag = 1;
    }
    pre = q;
}

void PreThread(ThreadTree T){
    if(T != NULL){
        visit(T);
        if (T->ltag == 0) {
            PreThread(T->lchild);
        }
        PreThread(T->rchild);
    }
}

void CreatPreThread(ThreadTree T){
    pre = NULL;
    if(T != NULL){
        PreThread(T);
        if(pre->rchild == NULL){
            pre->rtag = 1;
        }
    }
}

//王道教材版
void PreThread1(ThreadTree p,ThreadTree &pre){
    if (p!=NULL) {
        if (p->lchild == NULL) {
            p->lchild = pre;
            p->ltag = 1;
        }
        if(pre != NULL && pre->rchild == NULL){
            pre->rchild = p;
            pre->rtag = 1;
        }
        pre = p;
        if (p->ltag == 0) {
            PreThread1(p->lchild,pre);
        }
        PreThread1(p->rchild,pre);
    }
}

void CreatPreThread1(ThreadTree T){
    ThreadTree pre = NULL;
    if (T != NULL) {
        PreThread1(T,pre);
        if (pre->rchild == NULL) {
            pre->rtag = 1;
        }
    }
}

