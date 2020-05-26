#include<stdio.h>
#include<stdlib.h>

#define MaxSize 10

typedef struct{
	int data[MaxSize];
	int length;
}SqList;

void InitList(SqList &L){
	for(int i=0;i<MaxSize;i++){
		L.data[i]=0;
	}
	L.length=0;
}

void stochastic(SqList &L){
	for(int i=0;i<MaxSize;i++){
		L.data[i]=rand()%10;
	}
	L.length=MaxSize;
}

void Del_Min(SqList &L,int x){
	int k=0;
	for(int i=0;i<L.length;i++){
		if(L.data[i]!=x){
			L.data[k]=L.data[i];
			k++;
		}
	}
	L.length=k;
	printf("Success\n");
}



int main(){
	SqList L;
	InitList(L);
	stochastic(L);
	for(int i=0;i<L.length;i++){
		printf("data[%d]=%d\n",i,L.data[i]);
	}
	Del_Min(L,4);
	for(int i=0;i<L.length;i++){
		printf("data[%d]=%d\n",i,L.data[i]);
	}
	
}
