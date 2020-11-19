//
//  ParentRepresentation.cpp
//  test
//
//  Created by WhiteShark on 2020/11/10.
//  Copyright © 2020 WhiteShark. All rights reserved.
//

#include<stdio.h>
#include<stdlib.h>

#define Max_Tree_Size 100

typedef struct {
    int data;
    int parent;
}PTNode;
typedef struct {
    PTNode nodes[Max_Tree_Size];
    int n;
}PTree;
