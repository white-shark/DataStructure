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

void MergeList(LinkList &L,LinkList &K,LinkList &M){
    LNode *p=L->next;
    LNode *q=K->next;
    LNode *r=M;
    while (p!=NULL && q!=NULL) {
        LNode *z=(LNode *)malloc(sizeof(LNode));
        if (p->data<=q->data) {
            z->next=r->next;
            z->data=p->data;
            r->next=z;
            p=p->next;
            printf("a:%d\n",z->data);
        }
        else{
            z->next=r->next;
            z->data=q->data;
            r->next=z;
            q=q->next;
            printf("a:%d\n",z->data);
        }
    }
    if (p==NULL) {
        while (q!=NULL) {
            LNode *z=(LNode *)malloc(sizeof(LNode));
            z->next=r->next;
            z->data=q->data;
            r->next=z;
            q=q->next;
            printf("a:%d\n",z->data);
            
        }
    }
    else{
        while (p!=NULL) {
            LNode *z=(LNode *)malloc(sizeof(LNode));
            z->next=r->next;
            z->data=p->data;
            r->next=z;
            p=p->next;
            printf("a:%d\n",z->data);
        }
    }
    free(p);
    free(q);
    free(r);
    
    
}


int main() {
    LinkList L;
    LinkList K;
    LinkList M;
    InitList(L);
    InitList(K);
    InitList(M);
    ListInsert(L, 1, 7);
    ListInsert(L, 2, 10);
    ListInsert(L, 3, 13);
    ListInsert(L, 4, 19);
    ListInsert(L, 5, 28);
    ListInsert(K, 1, 9);
    ListInsert(K, 2, 11);
    ListInsert(K, 3, 16);
    ListInsert(K, 4, 27);
    MergeList(L, K, M);
    LNode *p;
    p=M->next;
    for (int i=0; i<9; i++) {
        printf("bb:%d\n",p->data);
        p=p->next;
    }
    
    return 0;
}
