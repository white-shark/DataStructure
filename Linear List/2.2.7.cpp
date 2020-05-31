#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define MaxSize 30

typedef struct {
	int data[30];
	int length;
}SqList;

void InitList(SqList &L){
	for(int i=0;i<MaxSize;i++){
		L.data[i]=0;
	}
	L.length=0;
}

void stochastic(SqList &L,SqList &K){
	for(int i=0;i<MaxSize;i++){
		if(i%2==0){
			L.data[L.length]=i;
			L.length++;
		}
		else if(i%3==0){
			K.data[K.length]=i;
			K.length++;
		}
	}
//	L.data[0]=1;
//	L.data[1]=5;
//	L.data[2]=9;
//	L.data[3]=15;
//	L.length=4;
//	K.data[0]=2;
//	K.data[1]=3;
//	K.data[2]=10;
//	K.data[3]=14;
//	K.length=4;
}

bool Merge(SqList A,SqList B,SqList &C){
	if(A.length+B.length>C.length){
		return false;
	}
	int i=0,k=0,j=0;
	while(i<A.length && j<B.length){
		if(A.data[i]<=B.data[j]){
			C.data[k]=A.data[i];
			k++;
			i++;
		}
		else {
			C.data[k]=B.data[j];
			k++;
			j++;
		}	
	}
	while(i<A.length){
		C.data[k]=A.data[i];
		k++;
		i++;
	}
	while(j<B.length){
		C.data[k]=B.data[j];
		k++;
		j++;
	}
	C.length=k;
	return true;
}

bool Merge2(SqList A,SqList B,SqList &C){
	if(A.length+B.length>C.length){
		return false;
	}
	int i=0,j=0,k=0;
	for(k=0;k<C.length;k++){
		if(i<A.length && j<B.length){
			if(A.data[i]<=B.data[j]){
				C.data[k]=A.data[i];
				i++;
			}
			else{
				C.data[k]=B.data[j];
				j++;
			}
		}
		else{
			if(i>=A.length){
				C.data[k]=B.data[j];
				j++;
			}
			else {
				C.data[k]=A.data[i];
				i++;
			}
		}
	}
	return true;
}

int main(){
	SqList L;
	SqList K;
	SqList C;
	InitList(L);
	InitList(K);
	InitList(C);
	stochastic(L,K);
	for(int i=0;i<L.length;i++){
		printf("data[%d]=%d\n",i,L.data[i]);
	}
	printf("--------\n");
	for(int i=0;i<K.length;i++){
		printf("data[%d]=%d\n",i,K.data[i]);
	}
	C.length=L.length+K.length;
	printf("1:%d\n",Merge(L,K,C));
	printf("--------\n");
	for(int i=0;i<C.length;i++){
		printf("data[%d]=%d\n",i,C.data[i]);
	}
	InitList(C);
	C.length=L.length+K.length;
	printf("2:%d\n",Merge2(L,K,C));
	printf("--------\n");
	for(int i=0;i<C.length;i++){
		printf("data[%d]=%d\n",i,C.data[i]);
	}
	return 0;
}
