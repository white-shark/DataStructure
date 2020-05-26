#include <stdio.h>
#define MaxSize 10
typedef struct{
	int data[MaxSize];
	int length;
}SqList;

//初始化 
void InitList(SqList &L){
	for(int i=0;i<MaxSize;i++){
		L.data[i]=0;
	}
	L.length=0;
}

//插入 
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

//删除 
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

//按位查找
int GetElem(SqList L,int i){
	return L.data[i-1]; 
} 

//按值查找
int GetElemByValue(SqList L,int e){
	for(int i=0;i<L.length;i++){
		if(L.data[i]==e){
			return i+1;
		}
	}
	return 0;
} 


int main(){
	//定义线性表初始化并插入一些初始值 
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
	//插入数据 
	ListInsert(L,2,5);
	for(int i=0;i<L.length;i++){
		printf("data[%d]=%d\n",i,L.data[i]);
	}
	printf("\n");
	//删除数据
	 int e=-1;
	 if(ListDelete(L,3,e)){
 		printf("已经删除第三个元素，元素值为：%d\n",e);
 	} 
 	else{
	 	printf("位序i不合法!\n");
	 }
 	for(int i=0;i<L.length;i++){
		printf("data[%d]=%d\n",i,L.data[i]);
	}
	printf("\n");
	
	//按位查找
	printf("第二个元素为：%d\n",GetElem(L,2)); 
	
	//按值查找 
	printf("值为5的第一个元素在第%d位\n",GetElemByValue(L,5));
	
	return 0;
}