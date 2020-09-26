#include<stdio.h>
#include<stdlib.h>

typedef struct LNode{
    int data;
    struct LNode *next;
}LNode,*LinkStack;

//栈初始化
bool InitStack(LinkStack &S){
    S = (LNode *)malloc(sizeof(LNode));
    if(S==NULL){
        return false;
    }
    S->next=NULL;
    return true;
}
//栈判空
bool Empty(LinkStack L){
    if(L->next==NULL){
        return true;
    }
    else {
        return false;
    }
}

//入栈
bool EnStack(LNode *p,int e){
    LNode *s = (LNode *)malloc(sizeof(LNode));
    if (s == NULL) {
        return false;
    }
    s -> data = e;
    s -> next = p->next;
    p -> next = s;
    return true;
}
//出栈
bool DeStack(LinkStack &S,int &x){
    LNode *p = S -> next;
    x = p -> data;
    S -> next = p -> next;
    free(p);
    return true;
}
