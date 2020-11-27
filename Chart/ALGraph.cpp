//
//  ALGraph.cpp
//  test
//
//  Created by WhiteShark on 2020/11/21.
//  Copyright © 2020 WhiteShark. All rights reserved.
//
//邻接表法
#include<stdio.h>
#include<stdlib.h>

#define MaxVertexNum 100

typedef struct ArcNode{
    int adjvex;
    struct ArcNode *next;
}ArcNode;

typedef struct VNode{
    int data;
    ArcNode *first;
}VNode,AdjList[MaxVertexNum];

typedef struct {
    AdjList vertices;
    int vexnum,arcnum;
}ALGraph;



int main(){
    return 0;
}

