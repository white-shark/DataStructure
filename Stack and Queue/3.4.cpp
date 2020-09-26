//
//  3.4.cpp
//  test
//
//  Created by WhiteShark on 2020/9/24.
//  Copyright © 2020 WhiteShark. All rights reserved.
//

//P85 1
#include<stdio.h>
#include<stdlib.h>

#define MaxSize 50;

//tag = 0 队列为未满
//tag = 1 队列满
typedef struct {
    int data[MaxSize];
    int front;
    int rear;
    int tag;
}SqQueue;

void InitQueue(SqQueue Q){
    Q.front = Q.rear = 0;
    Q.tag = 0;
}

bool isEmpty(SqQueue &Q){
    if (Q.tag == 0 && Q.front == Q.rear) {
        return true;
    }
    else {
        return false;
    }
}
//1
bool EnQueue(SqQueue &Q,int x){
    if (Q.front == Q.rear && Q.tag == 1) {
        return false;
    }
    Q.data[Q.rear] = x;
    Q.rear = (Q.rear +1) % MaxSize;
    Q.tag = 1;
    return true;
}
//1
bool DeQueue(SqQueue &Q,int &x){
    if (Q.front == Q.rear && Q.tag == 0) {
        return false;
    }
    x = Q.data[Q.front];
    Q.front = (Q.front + 1) % MaxSize;
    Q.tag = 0;
    return true;
}





