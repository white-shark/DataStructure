//
//  SequwntialTree.cpp
//  test
//
//  Created by WhiteShark on 2020/10/31.
//  Copyright © 2020 WhiteShark. All rights reserved.
//

// i的左孩子 2i
// i的右孩子 2i+1
// i的父节点 i/2
// i所在的层次 log2 (n+1) 或 log2 n +1

#include<stdio.h>
#include<stdlib.h>

#define MaxSize 10

struct TreeNode {
    int data;
    bool isEmpty;
};

void initTree(TreeNode *t){
    for (int i=0;i<MaxSize;i++) {
        t[i].isEmpty = true;
    }
    
}

int main(){
    TreeNode t[100];
    initTree(t);
    
    
}
