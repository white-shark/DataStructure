//
//  AdjacencyList.cpp
//  test
//
//  Created by WhiteShark on 2020/11/23.
//  Copyright © 2020 WhiteShark. All rights reserved.
//

#include<stdio.h>
#include<stdlib.h>

#define MaxSize 10
int visited[MaxSize] = {0};

typedef char DataType;
typedef struct EdgeNode{
    int adjvex;
    struct EdgeNode *next;
}EdgeNode;

typedef struct {
    DataType vertex;
    EdgeNode *first;
}VertexNode;

typedef struct {
    VertexNode adjlist[MaxSize];
    int vertexNum,edgeNum;
}ALGraph;

void CreatGraph(ALGraph *G,DataType a[],int n,int e){
    int i,j,k;
    EdgeNode *s = NULL;
    G -> vertexNum = n;
    G -> edgeNum = e;
    for (i = 0; i < G -> vertexNum; i++) {
        G -> adjlist[i].vertex = a[i];
        G -> adjlist[i].first = NULL;
    }
    for (k = 0; k < G -> edgeNum; k++) {
        printf("请输入顶点编号：");
        scanf("%d%d",&i,&j);
        s = (EdgeNode *)malloc(sizeof(EdgeNode));
        s -> adjvex = j;
        s -> next = G -> adjlist[i].first;
        G -> adjlist[i].first = s;
    }
    
}

void DesTroyGraph(ALGraph *G ){
    EdgeNode *p = NULL;
    EdgeNode *q = NULL;
    for (int i =0; i < G -> vertexNum; i++) {
        p = q = G -> adjlist[i].first;
        while (p != NULL) {
            p = p -> next;
            free(q);
            q = p;
        }
    }
}

void DFTraverse(ALGraph *G,int v){
    EdgeNode *p = NULL;
    int j;
    printf("%c",G -> adjlist[v].vertex);
    visited[v] = 1;
    p = G -> adjlist[v].first;
    while (p != NULL) {
        j = p->adjvex;
        if (visited[j] == 0) {
            DFTraverse(G, j);
        }
        p = p -> next;
    }
}

void BFTraverse(ALGraph *G,int v){
    EdgeNode *p = NULL;
    int Q[MaxSize];
    int front = -1;
    int rear = -1;
    int j;
    printf("%c",G -> adjlist[v].vertex);
    visited[v] = 1;
    Q[++rear] = v;
    while (front != rear) {
        v=Q[++front];
        p = G -> adjlist[v].first;
        while (p != NULL) {
            j = p -> adjvex;
            if (visited[j] == 0) {
                printf("%c",G -> adjlist[j].vertex);
                visited[j] = 1;
                Q[++rear] = j;
            }
            p = p -> next;
        }
    }
}



int main(){
    char ch[] = {'A','B','C','D','E'};
    int i;
    ALGraph ALG;
    CreatGraph(&ALG, ch, 5, 6);
    for (i = 0; i < MaxSize; i++) {
        visited[i] = 0;
    }
    printf("深度优先遍历：");
    DFTraverse(&ALG, 0);
    printf("\n");
    for (i = 0; i < MaxSize; i++) {
        visited[i] = 0;
    }
    printf("广度优先遍历：");
    BFTraverse(&ALG, 0);
    DesTroyGraph(&ALG);
    printf("\n");
    return 0;
}
