//
//  MinStack.h
//  CTutorial
//
//  Created by techcul_iOS on 2018/10/26.
//  Copyright © 2018 techcul. All rights reserved.
//

#ifndef MinStack_h
#define MinStack_h

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
// 155
typedef struct {
    int* top;
    int* base;
} MinStack;

/** initialize your data structure here. */
MinStack* minStackCreate(int maxSize);

void minStackPush(MinStack* obj, int x);

void minStackPop(MinStack* obj);

int minStackTop(MinStack* obj);

int minStackGetMin(MinStack* obj);

void minStackFree(MinStack* obj);

void minStackPlayExample();
    
#endif /* MinStack_h */
