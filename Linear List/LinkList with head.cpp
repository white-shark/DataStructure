#include<stdio.h>
#include<stdlib.h>
//带头结点 
typedef struct LNode{
	int data;
	struct LNode *next;
}LNode,*LinkList;

bool InitList(LinkList &L){
	L = (LNode *)malloc(sizeof(LNode));
	if(L==NULL){
		return false;
	}
	L->next=NULL;
	return true;
}

bool Empty(LinkList L){
	if(L->next==NULL){
		return true;
	}
	else {
		return false;
	}
}

bool ListInsert(LinkList &L,int i,int e){
	if(i<1){
		return false;
	}
	LNode *p;
	int j=0;
	p=L;
	while(p!=NULL && j<i-1){
		p=p->next;
		j++;
	}
	if(p==NULL){
		return false;
	}
	LNode *s=(LNode *)malloc(sizeof(LNode));
	s->data=e;
	s->next = p->next;
	p->next = s;
	return true;
}

bool InsretNextNode(LNode *p,int e){
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

bool ListDelete(LinkList &L,int i,int &e){
	if(i<1){
		return false;
	}
	LNode *p;
	int j=0;
	p=L;
	while(p!=NULL && j<i-1){
		p=p->next;
		j++;
	}
	if(p==NULL){
		return false;
	}
	if(p->next==NULL){
		return false;
	}
	LNode *q = p->next;
	e=q->data;
	p->next=q->next;
	free(q);
	return true;
}
//删除前驱节点 
bool DeleteNode(LNode *p){
	if(p==NULL){
		return false;
	}
	LNode *q=p->next;
	p->data;
	//p不能是最后一个节点 
	p->data=p->next->data;
	p->next=q->next;
	free(q);
	return true;
}

//按位查找
LNode * getElem(LinkList L,int i){
	if(i<0){
		return NULL;
	}
	LNode *p;
	int j=0;
	p=L;
	while(p!=NULL && j<i){
		p=p->next;
		j++;
	}
	return p;
} 

//按值查找
LNode * LocateElem(LinkList L,int e){
	LNode *p = L->next;
	while(p!=NULL && p->data!=e){
		p=p->next;
	}
	return p;
} 

//求表长
int ListLength (LinkList L){
	int len = 0;
	LNode *p -L;
	while(p->next != NULL){
		p=p->next;
		len++;
	}
	return len;
}

int main(){
	LinkList L;
	InitList(L);
	int len=0;
	bool temp;
	temp=ListInsert(L,1,5);
	if(temp){
		len++;
	}
	temp=ListInsert(L,2,3);
	if(temp){
		len++;
	}
	temp=ListInsert(L,3,10);
	if(temp){
		len++;
	}
	temp=ListInsert(L,4,6);
	if(temp){
		len++;
	}
	printf("链表长度：%d\n",len);
	
}
