//
//  MyLinkedList.h
//  CTutorial
//
//  Created by techcul_iOS on 2018/10/31.
//  Copyright © 2018 techcul. All rights reserved.
//

#ifndef MyLinkedList_h
#define MyLinkedList_h

#include <stdio.h>
#include <stdlib.h>
#include "ListNode.h"
// 707
typedef struct {
    int length;
    struct ListNode* head;
} MyLinkedList;
/** Initialize your data structure here. */
MyLinkedList* myLinkedListCreate();
/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
int myLinkedListGet(MyLinkedList* obj, int index);

/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
void myLinkedListAddAtHead(MyLinkedList* obj, int val);
/** Append a node of value val to the last element of the linked list. */
void myLinkedListAddAtTail(MyLinkedList* obj, int val);
/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val);
/** Delete the index-th node in the linked list, if the index is valid. */
void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index);
void myLinkedListFree(MyLinkedList* obj);

void myLiskedListPlayExample();
#endif /* MyLinkedList_h */
