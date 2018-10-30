//
//  MinStack.c
//  CTutorial
//
//  Created by techcul_iOS on 2018/10/26.
//  Copyright © 2018 techcul. All rights reserved.
//

#include "MinStack.h"

MinStack* minStackCreate(int maxSize) {
    MinStack *s;
    s = (MinStack *)malloc(sizeof(MinStack));
    s->base = (int *)malloc(maxSize * sizeof(int));
    if (!s || !s->base) {
        exit(1);
    }
    s->top = s->base;
    return s;
}

void minStackPush(MinStack* obj, int x) {
    *(obj->top++) = x;
}

void minStackPop(MinStack* obj) {
    obj->top--;
}

int minStackTop(MinStack* obj) {
    return *(obj->top-1);
}

int minStackGetMin(MinStack* obj) {
    int result = INT_MAX;
    int *temp = obj->base;
    while (temp != obj->top) {
        if (*temp < result) {
            result = *temp;
        }
        temp++;
    }
    return result;
}

void minStackFree(MinStack* obj) {
    free(obj->base);
    free(obj);
}

void minStackPlayExample(){
    int m;
    MinStack *obj = minStackCreate(10);
    minStackPush(obj, -2);
    minStackPush(obj, 0);
    minStackPush(obj, -3);
    m = minStackGetMin(obj);
    printf("%d\n",m);
    minStackPop(obj);
    m = minStackTop(obj);
    printf("%d\n",m);
    minStackFree(obj);
}
