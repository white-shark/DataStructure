#include<stdio.h>
#include<stdlib.h>

#define MaxSize 10
typedef struct {
	int data[10];
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

bool Del_s_t_1(SqList &L,int s,int t){
	if(s>=t || L.length<=0){
		return false;
	}
	int k=0;
	for(int i=0;i<L.length;i++){
		if(L.data[i]<s||L.data[i]>t){
			L.data[k]=L.data[i];
			k++;
		}
	}
	L.length=k;
	return true;
}


int main(){
	SqList L;
	InitList(L);
	stochastic(L);
	SqList K=L;
	for(int i=0;i<L.length;i++){
		printf("data[%d]=%d\n",i,L.data[i]);
	}
	printf("%d\n",Del_s_t_1(L,2,6));
	
	for(int i=0;i<L.length;i++){
		printf("data[%d]=%d\n",i,L.data[i]);
	}
	
	return 0;
}


