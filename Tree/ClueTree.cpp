////
////  ClueTree.cpp
////  test
////
////  Created by WhiteShark on 2020/11/8.
////  Copyright © 2020 WhiteShark. All rights reserved.
////寻找前驱后继
//
//#include<stdio.h>
//#include<stdlib.h>
//
//typedef struct BiTNode{
//    int data;
//    struct BiTNode *lchild,*rchild;
//}BiTNode,*BiTree;
//
//BiTNode *p;
//BiTNode *pre=NULL;
//BiTNode *final=NULL;
//
//void visit(BiTNode *q){
//    if (q==p) {
//        final = pre;
//    }
//    else{
//        pre = q;
//    }
//
//}
//
////中序遍历
//void InOrder(BiTree T){
//    if(T!=NULL){
//        InOrder(T->lchild);
//        visit(T);
//        InOrder(T->rchild);
//    }
//}
