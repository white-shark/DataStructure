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
//	for(int i=0;i<MaxSize;i++){
//		L.data[i]=rand()%10;
//	}
//	L.length=MaxSize;
	for(int i=0;i<MaxSize;i++){
		if(i%2==0){
			L.data[i]=i;
		}
		else{
			L.data[i]=i+1;
		}
	}
	L.length=MaxSize;
}
//乱序线性表 
bool Del_Same_1(SqList &L){
	if(L.length<=0){
		return false;
	}
	for(int i=1;i<L.length;i++){
		for(int j=0;j<i;j++){
			if(L.data[j]==L.data[i]){
				for(int k=i+1;k<L.length;k++){
					L.data[k-1]=L.data[k];
				}
				L.length--;
			}
		}
	}
}
//有序线性表 
bool Del_Same_2(SqList &L){
	if(L.length<=0){
		return false;
	}
	int i,j;
	for(i=0,j=1;j<L.length;j++){
		if(L.data[i]!=L.data[j]){
			++i;
			L.data[i]=L.data[j];
		}
	}
	L.length=i+1;
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
	
	printf("------------\n");
	Del_Same_1(L);
	for(int i=0;i<L.length;i++){
		printf("data[%d]=%d\n",i,L.data[i]);
	}
	
	printf("------------\n");
	Del_Same_2(K);
	for(int i=0;i<K.length;i++){
		printf("data[%d]=%d\n",i,K.data[i]);
	}
	
	return 0;
}
