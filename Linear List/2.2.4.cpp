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
	for(int i=0;i<MaxSize;i++){
		L.data[i]=i;
	}
	L.length=MaxSize;
}

//bool Del_s_t_1(SqList &L,int s,int t){
//	if(s>=t || L.length<=0){
//		return false;
//	}
//	int k=0;
//	for(int i=0;i<L.length;i++){
//		if(L.data[i]<s||L.data[i]>t){
//			L.data[k]=L.data[i];
//			k++;
//		}
//	}
//	L.length=k;
//	return true;
//}


bool Del_s_t_2(SqList &L,int s,int t){
	int i,j;
	if(s>=t || L.length==0){
		return false;
	}
	for(i=0;i<L.length&&L.data[i]<s;i++);
	if(i>=L.length){
		return false;
	}
	for(j=i;j<L.length&&L.data[j]<=t;j++);
	for(;j<L.length;i++,j++){
		L.data[i]=L.data[j];
	}
	L.length=i;
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
	printf("1\n");
	Del_s_t_1(L,2,6);
	for(int i=0;i<L.length;i++){
		printf("data[%d]=%d\n",i,L.data[i]);
	}
	printf("success\n");
	Del_s_t_2(K,2,6);

	for(int i=0;i<K.length;i++){
		printf("data[%d]=%d\n",i,K.data[i]);
	}
	return 0;
}


