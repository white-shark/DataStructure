#include<stdio.h>
#include<stdlib.h>
 typedef struct DNode{
 	int data;
 	struct DNode *prior,*next;
 }DNode,*DLinklist;
 
 bool InitDLinkList(DLinklist &L){
 	L = (DNode *)malloc(sizeof(DNode));
 	if(L == NULL){
	 	return false;
	}
	L->prior = L;
	L->next = L;
	return true;
 }
 
 bool Empty(DLinklist L){
 	if(L->next == L){
	 	return true;
	 }
	 else {
 		return false;
 	}
 }
 
 bool isTail(DLinklist L,DNode *p){
 	if(p->next == L){
	 	return true;
 	}
	else{
		return false;
	}
 }
 
 int main(){
 	DLinklist L;
 	InitDLinkList(L);
	printf("%d\n",Empty(L));
 }