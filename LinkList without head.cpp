#include<stdio.h>
#include<stdlib.h>
//不带头结点 
typedef struct LNode{
	int data;
	struct LNode *next;
}LNode,*LinkList;

bool InitList(LinkList &L){
	L=NULL;
	return true;
}
 
bool Empty(LinkList L){
	return (L==NULL);
}

bool ListInsert(LinkList &L,int i,int e){
	if(i<1){
		return false;
	}
	if(i==1){
		LNode *s = (LNode *)malloc(sizeof(LNode));
		s->data=e;
		s->next=L;
		L=s;
	}
	LNode *p;
	int j=1;
	p=L;
	while(p!=NULL && j<i-1){
		p=p->next;
		j++;
	}
	if(p==NULL){
		return false;
	}
	LNode *s = (LNode *)malloc(sizeof(LNode));
	s->data=e;
	s->next=p->next;
	p-next=s;
	return true;
}

bool InsetNextNode(LNode *p,int e){
	if(p==NULL){
		return false;
	}
	LNode *s = (LNode *)malloc(sizeof(LNode));
	if(s==NULL){
		return false;
	}
	s->data = e;
	s->next = p->next;
	p->next=s;
	return true;
}

//在指定节点前插入节点（简单）：方法一 偷天换日 
bool InsertPriorNode(LNode *p,int e){
	if(p==NULL){
		return false;
	}
	LNode *s = (LNode *)malloc(sizeof(LNode));
	if(s==NULL){
		return false;
	}
	s->next=p->next;
	p->next=s;
	s->data=p->data;
	p->data-e;
	return true;
}
//在指定节点前插入节点（复杂）：方法二 遍历 
bool InsertPriorNode2(LinkList &L,LNode *p,int e){
	LNode *c=L;
	while(c->next!=p){
		c=c->next;
	}
	LNode *s = (LNode *)malloc(sizeof(LNode));
	s->data=e;
	s->next=p;
	c->next=s;
}

int main(){
	LinkList L;
	InitList(L);
}