//
//  DiGraph.cpp
//  test
//
//  Created by WhiteShark on 2020/12/1.
//  Copyright © 2020 WhiteShark. All rights reserved.
//

#include<stdio.h>
#include<stdlib.h>

#define MaxSize 10
#define ElemType char

//邻接矩阵
typedef struct {
    ElemType vertex[MaxSize];
    int arc[MaxSize][MaxSize];
    int vertexNum;
    int arcNum;
}MGraph;

//邻接表
typedef struct ArcNode{
    int adjvex;
    struct ArcNode *next;
}ArcNode;

typedef struct {
    ElemType vertex;
    ArcNode *firstedge;
}VertexNode;

typedef struct {
    VertexNode adjlist[MaxSize];
    int vertexNum;
    int arcNum;
}ALGraph;


//创建邻接矩阵
void CreatMGraph(MGraph &G,ElemType a[],int n,int e){
    G.vertexNum = n;
    G.arcNum = e;
    int k;
    int l;
    for (int i = 0; i < G.vertexNum; i++) {
        G.vertex[i] = a[i];
    }
    for (int i = 0; i < G.vertexNum; i++) {
        for (int j = 0; j < G.vertexNum; j++) {
            G.arc[i][j] = 0;
        }
    }
    for (k = 0; k< G.arcNum; k++) {          //输入边依附的顶点编号
        printf("请输入顶点编号：");
        scanf("%d%d",&k,&l);
        G.arc[k][l] = 1;
    }
}

//创建邻接表
void CreatALGraph(ALGraph &G,ElemType a[],int n,int e){
    int i;
    int j;
    G.vertexNum = n;
    G.arcNum = e;
    for (int i = 0; i <G.vertexNum; i++) {
        G.adjlist[i].vertex = a[i];
        G.adjlist[i].firstedge = NULL;
    }
    for (int k = 0; k < G.arcNum; k++) {
        ArcNode *s;
        s = (ArcNode*)malloc(sizeof(ArcNode));
        printf("请输入顶点编号：");
        scanf("%d%d",&i,&j);
        s -> adjvex = j;
        s -> next = G.adjlist[i].firstedge;
        G.adjlist[i].firstedge = s;
    }
}


void Ergodic(ALGraph &G,ElemType a[]){
    ArcNode *p;
    for (int i = 0; i < G.vertexNum; i++) {
        p=G.adjlist[i].firstedge;
        printf("%c：",a[i]);
        while (p != NULL) {
            printf("%c",a[p -> adjvex]);
            p = p -> next;
        }
        printf("\n");
    }
}

int main(){
    char ch[] = {'A','B','C','D','E'};
    ALGraph ALG;
    CreatALGraph(ALG, ch, 5, 6);
    Ergodic(ALG,ch);
    
    return 0;
}
