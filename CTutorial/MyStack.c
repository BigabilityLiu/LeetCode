//
//  MyStack.c
//  CTutorial
//
//  Created by techcul_iOS on 2018/10/30.
//  Copyright © 2018 techcul. All rights reserved.
//

#include "MyStack.h"

/** Initialize your data structure here. */
MyStack* myStackCreate(int maxSize) {
    MyStack* s;
    s = (MyStack*)malloc(sizeof(MyStack));
    if (!s) exit(0);
    int *nums;
    nums = (int *)malloc(sizeof(int) * maxSize);
    if (!nums) exit(0);
    s->nums = nums;
    s->size = 0;
    s->maxSize = maxSize;
    return s;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
    if (obj->size == obj->maxSize) exit(0);
    *(obj->nums + obj->size++) = x;
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
    if (obj->size == 0) exit(0);
    return *(obj->nums + --obj->size);
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
    if (obj->size == 0) exit(0);
    return *(obj->nums + obj->size - 1);
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
    return obj->size == 0;
}

void myStackFree(MyStack* obj) {
    free(obj->nums);
    free(obj);
}


void myStackPlayExample(){
    MyStack* obj = myStackCreate(5);
    myStackPush(obj, 1);
    myStackPush(obj, 2);
    int param_2 = myStackPop(obj);
    int param_3 = myStackTop(obj);
    bool param_4 = myStackEmpty(obj);
    myStackFree(obj);
}
