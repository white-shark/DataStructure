//
//  AdjacencyMatrix.cpp
//  test
//
//  Created by WhiteShark on 2020/11/22.
//  Copyright © 2020 WhiteShark. All rights reserved.
//

#include <stdio.h>
#include<stdlib.h>

#define MaxSize 10
int visited[MaxSize] = {0};

typedef char DataType;              //顶点的数据类型
typedef struct {                    //定义邻接矩阵的存储结构
    DataType vertex[MaxSize];       //存放顶点的一维数组
    int edge[MaxSize][MaxSize];     //存放边的二维数组
    int vertexNum,edgeNum;          //图的顶点数与边数
}MGraph;

//创建邻接矩阵
void CreatGraph(MGraph *G,DataType a[],int n, int e){
    int i,j,k;
    G -> vertexNum = n;
    G -> edgeNum = e;
    for (i = 0; i < G -> vertexNum; i++) {        //储存顶点信息
        G->vertex[i] = a[i];
    }
    for (i = 0; i < G -> vertexNum; i++) {        //初始化邻接矩阵
        for (j=0; j < G -> vertexNum; j++) {
            G -> edge[i][j]=0;
        }
    }
    for (k = 0; k< G-> edgeNum; k++) {          //输入边依附的顶点编号
        printf("请输入顶点编号：");
        scanf("%d%d",&i,&j);
        G -> edge[i][j] = 1;
        G -> edge[j][i] = 1;
    }

}
//深度优先遍历
void DFraverse(MGraph *G,int v){
    printf("%c",G -> vertex[v]);
    visited[v] = 1;
    for (int j = 0; j < G-> vertexNum; j++) {
        if (G -> edge[v][j] == 1 && visited[j] == 0) {
            DFraverse(G, j);
        }
    }
}

void DFTaverse(MGraph *G){
    for (int i = 0; i < G -> vertexNum; i++) {
        visited[i] = 0;
    }
    for(int i = 0;i < G -> vertexNum;i++){
        if (visited[i] != 1) {
            DFraverse(G, i);
        }
    }
}

//广度优先遍历
void BFraverse(MGraph *G,int v){
    int i,j;
    int Q[MaxSize];
    int front = -1;
    int rear = -1;
    printf("%c",G -> vertex[v]);
    visited[v] = 1;
    Q[++rear] = v;
    while (front != rear) {
        i = Q[++front];
        for (j = 0; j < G->vertexNum; j++) {
            if(G -> edge[i][j] == 1 && visited[j] == 0){
                printf("%c",G -> vertex[j]);
                visited[j] = 1;
                Q[++rear] = j;
            }
        }
    }
}

void BFTaverse(MGraph *G){
    for (int i = 0; i < G -> vertexNum; i++) {
        visited[i] = 0;
    }
    for (int i = 0; i < G -> vertexNum; i++) {
        if (visited[i] != 1) {
            BFraverse(G, i);
        }
    }
}

int main(){
    int i;
    DataType ch[] = {'A','B','C','D','E','F'};
    MGraph MG;
    CreatGraph(&MG, ch, 6, 6);
    for (i = 0; i < MaxSize; i++) {
        visited[i]=0;
    }
    printf("深度优先遍历序列是：");
//    DFraverse(&MG, 0);
    DFTaverse(&MG);
    printf("\n");
    for (i = 0; i < MaxSize; i++) {
        visited[i]=0;
    }
    printf("广度优先遍历序列：");
//    BFraverse(&MG, 0);
    BFTaverse(&MG);
    printf("\n");
    printf("end");
    return 0;
}

