//
//  MyStack.h
//  CTutorial
//
//  Created by techcul_iOS on 2018/10/30.
//  Copyright © 2018 techcul. All rights reserved.
//

#ifndef MyStack_h
#define MyStack_h

#include <stdio.h>
#include "stdlib.h"
#include "string.h"
#include "limits.h"
#include "stdbool.h"

typedef struct {
    int* nums;
    int size;
    int maxSize;
} MyStack;

/** Initialize your data structure here. */
MyStack* myStackCreate(int maxSize);
/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) ;
/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj);
/** Get the top element. */
int myStackTop(MyStack* obj);
/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj);
void myStackFree(MyStack* obj);

void myStackPlayExample();
#endif /* MyStack_h */
