//
//  AVLTree.cpp
//  test
//
//  Created by WhiteShark on 2020/11/12.
//  Copyright © 2020 WhiteShark. All rights reserved.
//

#include<stdio.h>
#include<stdlib.h>

typedef struct AVLNode{
    int key;
    int balance;
    struct AVLNode *lchild, *rchild;
    
}AVLNode,*AVLTree;


