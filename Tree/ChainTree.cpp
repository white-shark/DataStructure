//
//  ChainTree.cpp
//  test
//
//  Created by WhiteShark on 2020/10/31.
//  Copyright © 2020 WhiteShark. All rights reserved.
//

#include<stdio.h>
#include<stdlib.h>

typedef struct BiTNode{
    int data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;



int main(){
    //插入根节点
    BiTree root = NULL;
    root = (BiTree)malloc(sizeof(BiTNode));
    root->data=1;
    root->lchild=NULL;
    root->rchild=NULL;
    
    //插入新节点
    BiTNode *p = (BiTNode *)malloc(sizeof(BiTNode));
    p->data = 2;
    p->lchild=NULL;
    p->rchild=NULL;
    root->lchild=p;
}
