#include<stdio.h>
#include<stdlib.h>
#define InitSize 10
typedef struct{
	int *data;
	int MaxSize;
	int length;
}SqList;

void InitList(SqList &L){
	L.data=(int *)malloc(InitSize*sizeof(int));
	L.length=0;
	L.MaxSize=InitSize; 
}

void IncreaseSize(SqList &L,int len){
	int *p = L.data;
	L.data=(int *)malloc((L.MaxSize+len)*sizeof(int));
	for(int i=0;i<L.length;i++){
		L.data[i]=p[i];
	}
	L.MaxSize=L.MaxSize+len;
	free(p);
}

int main(){
	SqList L;
	InitList(L);
	L.data[0]=2;
	L.data[2]=1;
	L.data[5]=5;
	L.length=5;
	IncreaseSize(L,5);
	for(int i=0;i<L.length;i++){
		printf("data[%d]=%d\n",i,L.data[i]);
	}
	return 0;
}