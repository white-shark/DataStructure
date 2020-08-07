#include <stdio.h>
#include <stdlib.h>
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

void Del_same(LinkList &L){
    LNode *p=L->next;
    LNode *q;
    
    if (p==NULL) {
        return;
    }
    while (p->next!=NULL) {
        q=p->next;
        if (q->data==p->data) {
            p->next=q->next;
            free(q);
        }
        else{
            p=p->next;
        }
    }
    
}


int main() {
    LinkList L;
    InitList(L);
    ListInsert(L, 1, 7);
    ListInsert(L, 2, 10);
    ListInsert(L, 3, 10);
    ListInsert(L, 4, 21);
    ListInsert(L, 5, 21);
    Del_same(L);
    return 0;
}
