#include <stdio.h>
#include <stdlib.h>
typedef struct LNode{
    int data;
    struct LNode *next;
}LNode,*LinkList;

bool InitList(LinkList &L){
    L=NULL;
    return true;
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
    p->next=s;
    return true;
}

void Del_x_recursion(LinkList &L,int x){
    if(L==NULL)
        return;
    if(L->data != x){
        Del_x_recursion(L->next,x);
        return;
    }
    LNode *p;
    p=L;
    L=L->next;
    free(p);
    Del_x_recursion(L, x);
}

int main() {
    LinkList L;
    InitList(L);
    ListInsert(L, 1, 5);
    ListInsert(L, 2, 2);
    ListInsert(L, 3, 3);
    ListInsert(L, 4, 5);
    ListInsert(L, 5, 6);
    Del_x_recursion(L,5);
    return 0;
}
