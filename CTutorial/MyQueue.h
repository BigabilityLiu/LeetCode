//
//  MyQueue.h
//  CTutorial
//
//  Created by techcul_iOS on 2018/10/30.
//  Copyright © 2018 techcul. All rights reserved.
//

#ifndef MyQueue_h
#define MyQueue_h

#include <stdio.h>
#include "stdlib.h"
#include "string.h"
#include "limits.h"
#include "stdbool.h"

typedef struct {
    int* nums;
    int start;
    int end;
    int maxSize;
    int size;
} MyQueue;

/** Initialize your data structure here. */
MyQueue* myQueueCreate(int maxSize);
/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x);
/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj);
/** Get the front element. */
int myQueuePeek(MyQueue* obj) ;
/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj);
void myQueueFree(MyQueue* obj);


void myQueuePlayExample();
#endif /* MyQueue_h */
