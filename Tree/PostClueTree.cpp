//
//  PostClueTree.cpp
//  test
//
//  Created by WhiteShark on 2020/11/9.
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
    if (q->lchild == NULL) {
        q->lchild = pre;
        q->ltag = 1;
    }
    if (pre != NULL && pre->rchild == NULL) {
        pre->rchild=q;
        pre->rtag = 1;
    }
    pre = q;
}

void PostThread(ThreadTree T){
    if(T != NULL){
        PostThread(T->lchild);
        PostThread(T->rchild);
        visit(T);
    }
    
}

void CreatPostThread(ThreadTree T){
    pre = NULL;
    if(T != NULL){
        PostThread(T);
        if (pre->rchild == NULL) {
            pre->rtag= 1;
        }
    }
}

//王道教材版
void PostThread1(ThreadTree p,ThreadTree &pre){
    if (p != NULL) {
        PostThread1(p->lchild,pre);
        PostThread1(p->rchild,pre);
        if (p->lchild == NULL) {
            p->lchild = pre;
            p->ltag = 1;
        }
        if (pre != NULL && pre->rchild == NULL) {
            pre->rchild = p;
            pre->rtag = 1;
        }
        pre = p;
    }
}

void CreatPostThread1(ThreadTree T){
    ThreadTree pre = NULL;
    if (T != NULL) {
        PostThread1(T,pre);
        if (pre->rchild == NULL) {
            pre->rtag = 1;
        }
    }
}
