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

void R_print(LinkList &L){
    if (L->next != NULL) {
        R_print(L->next);
    }
    printf("%d\n",L->data);
}


int main() {
    LinkList L;
    InitList(L);
    ListInsert(L, 1, 5);
    ListInsert(L, 2, 2);
    ListInsert(L, 3, 3);
    ListInsert(L, 4, 5);
    ListInsert(L, 5, 6);
    R_print(L);
    return 0;
}
