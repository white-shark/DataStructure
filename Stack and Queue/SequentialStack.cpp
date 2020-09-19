#include<stdio.h>
#include<stdlib.h>

#define MaxSize 50
typedef struct {
    int data[MaxSize];
    int top;
}SqStack;

//初始化
void InitStack(SqStack &S){
    S.top=-1;
}

//栈判空
bool StackEmpty(SqStack S){
    if(S.top == -1){
        return true;
    }
    else{
        return false;
    }
}

//进栈
bool Push(SqStack &S,int x){
    if (S.top == MaxSize-1) {
        return false;
    }
    S.top = S.top + 1;
    S.data[S.top] = x;
    return true;
}

//出栈
bool Pop(SqStack &S,int &x){
    if(S.top == -1){
        return false;
    }
    x = S.data[S.top];
    S.top = S.top - 1;
    return true;
}

//读取栈顶元素
bool GetTop(SqStack &S,int &x){
    if(S.top == -1){
        return false;
    }
    x=S.data[S.top];
    return true;
}

int main(){
    int res = 0;
    SqStack S;
    InitStack(S);
    printf("%d\n",StackEmpty(S));
    Push(S, 5);
    GetTop(S, res);
    printf("栈顶元素：%d\n",res);
    Push(S, 6);
    GetTop(S, res);
    printf("栈顶元素：%d\n",res);
    Pop(S, res);
    printf("%d出栈\n",res);
    GetTop(S, res);
    printf("栈顶元素：%d\n",res);
}

