#include<stdio.h>
#include<stdlib.h>

typedef struct LNode{
	int data;
	struct LNode *next;
}LNode,*LinkList;

bool InitList(LinkList &L){
	L = (LNode *)malloc(sizeof(LNode));
	if(L==NULL){
		return false;
	}
	L->next = L;
	return true;
}

bool Empty(LinkList L){
	if(L->next ==L){
		return true;
	}
	else{
		return false;
	}
}

bool isTail(LinkList L,LNode *p){
	if(p->next == L){
		return true;
	}
	else{
		return false;
	}
	
}

int main(){
	LinkList L;
	InitList(L);
	printf("%d\n",Empty(L));
	//printf("%d\n",isTail(L));
}