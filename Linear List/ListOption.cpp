#include <stdio.h>
#define MaxSize 10
typedef struct{
	int data[MaxSize];
	int length;
}SqList;

//��ʼ�� 
void InitList(SqList &L){
	for(int i=0;i<MaxSize;i++){
		L.data[i]=0;
	}
	L.length=0;
}

//���� 
bool ListInsert(SqList &L,int i,int e){
	if(i<1||i>L.length+1){
		return false;
	}
	else if(L.length>=MaxSize){
		return false;
	}
	for(int j=L.length;j>=i;j--){
		L.data[j]=L.data[j-1];
	}
	L.data[i-1]=e;
	L.length++;
}

//ɾ�� 
bool ListDelete(SqList &L,int i,int &e){
	if(i<1||i>L.length){
		return false;
	}
	e=L.data[i-1];
	for(int j=i;j<L.length;j++){
		L.data[j-1]=L.data[j];
	}
	L.length--;
	return true;
}

//��λ����
int GetElem(SqList L,int i){
	return L.data[i-1]; 
} 

//��ֵ����
int GetElemByValue(SqList L,int e){
	for(int i=0;i<L.length;i++){
		if(L.data[i]==e){
			return i+1;
		}
	}
	return 0;
} 


int main(){
	//�������Ա��ʼ��������һЩ��ʼֵ 
	SqList L;
	InitList(L);
	L.data[0]=1;
	L.data[1]=2;
	L.data[2]=3;
	L.length=3;
	for(int i=0;i<L.length;i++){
		printf("data[%d]=%d\n",i,L.data[i]);
	}
	printf("\n");
	//�������� 
	ListInsert(L,2,5);
	for(int i=0;i<L.length;i++){
		printf("data[%d]=%d\n",i,L.data[i]);
	}
	printf("\n");
	//ɾ������
	 int e=-1;
	 if(ListDelete(L,3,e)){
 		printf("�Ѿ�ɾ��������Ԫ�أ�Ԫ��ֵΪ��%d\n",e);
 	} 
 	else{
	 	printf("λ��i���Ϸ�!\n");
	 }
 	for(int i=0;i<L.length;i++){
		printf("data[%d]=%d\n",i,L.data[i]);
	}
	printf("\n");
	
	//��λ����
	printf("�ڶ���Ԫ��Ϊ��%d\n",GetElem(L,2)); 
	
	//��ֵ���� 
	printf("ֵΪ5�ĵ�һ��Ԫ���ڵ�%dλ\n",GetElemByValue(L,5));
	
	return 0;
}