//
//  BinarySearchTree.cpp
//  test
//
//  Created by WhiteShark on 2020/11/10.
//  Copyright © 2020 WhiteShark. All rights reserved.
//

#include<stdio.h>
#include<stdlib.h>

typedef struct BSTNode{
    int key;
    struct BSTNode *lchild,*rchild;
}BSTNode,*BSTree;

//循环查找
BSTNode *BST_Search(BSTree T,int key){
    while (T != NULL && key != T->key) {
        if (key < T->key) {
            T = T->lchild;
        }
        else{
            T=T->rchild;
        }
    }
    return T;
}
//递归查找
BSTNode *BSTSearch(BSTree T,int key){
    if (T == NULL) {
        return NULL;
    }
    if (key == T->key) {
        return T;
    }
    else if(key < T->key){
        return BSTSearch(T->lchild, key);
    }
    else{
        return BSTSearch(T->rchild, key);
    }
}

//插入
int BST_Insert(BSTree &T,int k){
    if (T==NULL) {
        T=(BSTree)malloc(sizeof(BSTNode));
        T->key = k;
        T->lchild = T->rchild = NULL;
        return 1;
    }
    else if (T->key == k){
        return 0;
    }
    else if (k < T->key){
        return BST_Insert(T->lchild, k);
    }
    else{
        return BST_Insert(T->rchild, k);
    }
}

//构造二叉排序树
void Creat_BST(BSTree &T,int str[],int n){
    T=NULL;
    int i=0;
    while (i<n) {
        BST_Insert(T,str[i]);
        i++;
    }
}
