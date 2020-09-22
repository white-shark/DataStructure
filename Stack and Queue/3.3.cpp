// P71 4

#include<stdio.h>
#include<stdlib.h>

typedef struct LNode{
    char data;
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

bool dc(LinkList L,int n){
    int i=0;
    char s[n/2];
    LNode* p = L->next;
    for (i=0; i < n/2; i++) {
        s[i] = p-> data;
        p = p -> next;
    }
    i --;
    if (n % 2 == 1) {
        p = p -> next;
    }
    while (p != NULL && p -> data == s[i]) {
        i --;
        p = p -> next;
    }
    if (i == -1) {
        return true;
    }
    else{
        return false;
    }
}

int main(){
    LinkList L;
    InitList(L);
    ListInsert(L, 1, 'x');
    ListInsert(L, 2, 'y');
    ListInsert(L, 3, 'z');
    ListInsert(L, 4, 'y');
    ListInsert(L, 5, 'x');
    printf("%d\n",dc(L, 5));
    
}
