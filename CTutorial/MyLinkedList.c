//
//  MyLinkedList.c
//  CTutorial
//
//  Created by techcul_iOS on 2018/10/31.
//  Copyright © 2018 techcul. All rights reserved.
//

#include "MyLinkedList.h"
 
MyLinkedList* myLinkedListCreate() {
    MyLinkedList* l;
    l = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    if (!l) exit(0);
    l->length = 0;
    l->head = NULL;
    return l;
}

int myLinkedListGet(MyLinkedList* obj, int index) {
    if (index>=obj->length) {
        return -1;
    }
    struct ListNode* p = obj->head;
    for (int i=0; i<index; i++) {
        p = p->next;
    }
    return p->val;
}

void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    struct ListNode* new;
    new = (struct ListNode*)malloc(sizeof(struct ListNode));
    new->next = NULL;
    if (!new) exit(0);
    new->val = val;
    
    if (obj->length>0) {
        new->next = obj->head;
    }
    obj->head = new;
    obj->length++;
}

void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    struct ListNode* new;
    new = (struct ListNode*)malloc(sizeof(struct ListNode));
    if (!new) exit(0);
    new->val = val;
    new->next = NULL;
    
    if (obj->length>0) {
        struct ListNode* p = obj->head;
        while (p->next) {
            p = p->next;
        }
        p->next = new;
    }else{
        obj->head = new;
    }
    obj->length++;
}

void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    if (index>obj->length) {
        return;
    }
    struct ListNode* new;
    new = (struct ListNode*)malloc(sizeof(struct ListNode));
    if (!new) exit(0);
    new->val = val;
    new->next = NULL;
    if (index==0) {
        if (obj->length==0) {
            new->next = NULL;
            obj->head = new;
        }else{
            new->next = obj->head;
            obj->head = new;
        }
    }else{
        struct ListNode* p = obj->head;
        while(--index > 0){
            p = p->next;
        }
        new->next = p->next;
        p->next = new;
    }
    obj->length++;
}


void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    if (index>obj->length-1) {
        return;
    }
    struct ListNode* p = obj->head;
    if (index==0) {
        if (obj->length == 1) {
            obj->head = NULL;
        }else{
            obj->head = p->next;
            free(p);
        }
    }else{
        while(--index > 0){
            p = p->next;
        }
        struct ListNode* deleNode = p->next;
        p->next = deleNode->next;
        free(deleNode);
    }
    obj->length--;
}

void myLinkedListFree(MyLinkedList* obj) {
    struct ListNode* p = obj->head;
    struct ListNode* now = p;
    while(p){
        now = p;
        p=p->next;
        free(now);
    }
    free(obj);
}



void myLiskedListPlayExample(){
    struct MyLinkedList* obj = myLinkedListCreate();
    int param_1 = myLinkedListGet(obj, 0);
    myLinkedListAddAtHead(obj, 1);
    myLinkedListAddAtTail(obj, 3);
    myLinkedListAddAtIndex(obj, 1, 2);
    myLinkedListDeleteAtIndex(obj, 1);
    myLinkedListFree(obj);
}
