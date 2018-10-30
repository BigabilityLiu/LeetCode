//
//  MyQueue.c
//  CTutorial
//
//  Created by techcul_iOS on 2018/10/30.
//  Copyright © 2018 techcul. All rights reserved.
//

#include "MyQueue.h"

/** Initialize your data structure here. */
MyQueue* myQueueCreate(int maxSize) {
    MyQueue *q;
    q = (MyQueue*)malloc(sizeof(MyQueue));
    if (!q) {
        exit(0);
    }
    int *nums;
    nums = (int *)malloc(sizeof(int) * maxSize);
    if (!nums) {
        exit(0);
    }
    q->nums = nums;
    q->maxSize = maxSize;
    q->start=0;
    q->end=0;
    q->size=0;
    return q;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {
    if (obj->size == obj->maxSize) {
        exit(0);
    }
    *(obj->nums + obj->end++) = x;
    if (obj->end == obj->maxSize-1) {
        obj->end = 0;
    }
    obj->size++;
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {
    if (obj->size == 0) {
        exit(0);
    }
    int result = *(obj->nums + obj->start++);
    if (obj->start == obj->maxSize-1) {
        obj->start = 0;
    }
    obj->size--;
    return result;
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) {
    if (obj->size == 0) {
        exit(0);
    }
    return *(obj->nums + obj->start);
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj) {
    return obj->size == 0;
}

void myQueueFree(MyQueue* obj) {
    free(obj->nums);
    free(obj);
}

void myQueuePlayExample(){
    MyQueue* obj = myQueueCreate(5);
    myQueuePush(obj, 1);
    int param_2 = myQueuePop(obj);
    int param_3 = myQueuePeek(obj);
    bool param_4 = myQueueEmpty(obj);
    myQueueFree(obj);
}
