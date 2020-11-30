//
//  Prim.cpp
//  test
//
//  Created by WhiteShark on 2020/11/27.
//  Copyright © 2020 WhiteShark. All rights reserved.
//

#include<stdio.h>
#include<stdlib.h>

#define MaxSize 5
int visited[MaxSize] = {0};

typedef char DataType;              //顶点的数据类型
typedef struct {                    //定义邻接矩阵的存储结构
    DataType vertex[MaxSize];       //存放顶点的一维数组
    int edge[MaxSize][MaxSize];     //存放边的二维数组
    int vertexNum,edgeNum;          //图的顶点数与边数
}MGraph;


int MinEdge(int lowcast[],int v){
    int min = 100;
    int j = 0;
    for (int i = 1; i < v; i++) {
        if (lowcast[i] < min && lowcast[i] != 0) {
            min = lowcast[i];
            j = i;
        }
    }
    return j;
}

void Prim(MGraph *G,DataType a[],int v){
    int i,j,k;
    int adjvex[MaxSize];
    int lowcast[MaxSize];
    for (i = 0; i < G -> vertexNum; i++) {
        lowcast[i] = G -> edge[v][i];
        adjvex[i] = v;
    }
    for (int z = 0; z < MaxSize; z++) {
        printf("lowcast:%d ",lowcast[z]);
    }
    printf("\n");
    
    lowcast[v] = 0;
    for (k = 1; k < G -> vertexNum; k++) {
        j = MinEdge(lowcast,G -> vertexNum);
        printf("(%c,%c)%d\n",a[j],a[adjvex[j]],lowcast[j]);
        lowcast[j] = 0;
        
        for (int z = 0; z < MaxSize; z++) {
            printf("lowcast:%d ",lowcast[z]);
        }
        printf("\n");
        
        for (i = 0; i < G -> vertexNum; i++) {
            if (G -> edge[i][j] < lowcast[i] && G -> edge[i][j] != 0) {
                lowcast[i] = G -> edge[i][j];
                adjvex[i] = j;
            }
            else if (G -> edge[i][j] > lowcast[i]){
                int flag = 0;
                for (int o=0; o < MaxSize; o++) {
                    if (i == adjvex[o]) {
                        flag = 1;
                    }
                }
                if (flag == 0) {
                    lowcast[i] = G -> edge[i][j];
                    adjvex[i] = j;
                }
            }
        }
        
        for (int z = 0; z < MaxSize; z++) {
            printf("lowcast:%d ",lowcast[z]);
        }
        printf("\n");
        
        
    }
}


//创建邻接矩阵
void CreatGraph(MGraph *G,DataType a[],int n, int e){
    int i,j,k;
    int l;
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
        printf("请输入权值：");
        scanf("%d",&l);
        G -> edge[i][j] = l;
        G -> edge[j][i] = l;
    }

}

int main(){
    DataType ch[] = {'A','B','C','D','E'};
    MGraph MG;
    CreatGraph(&MG, ch, 5, 8);
    for (int i = 0; i < MG.vertexNum; i++) {
        for (int j = 0; j <MG.vertexNum; j++) {
            printf("%d ",MG.edge[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    Prim(&MG,ch, 0);
    
    
    return 0;
}
