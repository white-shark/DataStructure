#include<stdio.h>
#include<stdlib.h>

//顺序队列
#define MaxSize 50
typedef struct {
    int data[MaxSize];
    int front;
    int rear;
}SqQueue;
//循环队列

//初始化
void InitQueue(SqQueue &Q){
    Q.rear = 0;
    Q.front = 0;
}

bool isEmpty(SqQueue Q){
    if(Q.rear == Q.front){
        return true;
    }
    else{
        return false;
    }
}

//入队
bool EnQueue(SqQueue &Q,int data){
    if ((Q.rear + 1) % MaxSize == Q.front) {        //队列已满
        return false;
    }
    Q.data[Q.rear] = data;
    Q.rear = (Q.rear + 1) % MaxSize;                //队尾指针+1取模
    return true;
}
//出队
bool DeQueue(SqQueue &Q,int &data){
    if (Q.rear == Q.front) {                        //队列为空
        return false;
    }
    data = Q.data[Q.front];
    Q.front = (Q.front + 1) % MaxSize;
    return true;
}

int main(){
    SqQueue Q;
    InitQueue(Q);
    printf("%d\n",isEmpty(Q));
    EnQueue(Q, 5);
    EnQueue(Q, 6);
    int x;
    DeQueue(Q, x);
    printf("%d\n",x);
    DeQueue(Q, x);
    printf("%d\n",x);
}
