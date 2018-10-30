//
//  ListNode.c
//  CTutorial
//
//  Created by techcul_iOS on 2018/10/26.
//  Copyright © 2018 techcul. All rights reserved.
//

#include "ListNode.h"

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode* pA = headA;
    struct ListNode* pB = headB;
    while (pA) {
        while (pB) {
            if (pA == pB) {
                return pA;
            }
            pB = pB->next;
        }
        pA = pA->next;
    }
    return NULL;
}

struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode* p=NULL;
    while (head) {
        if (head->val==val) {
            head=head->next;
        }else{
            p=head;
            break;
        }
    }
    if (p) {
        while (head->next != NULL) {
            if (head->next->val == val) {
                head->next = head->next->next;
            }else{
                head = head->next;
            }
        }
    }
    return p;
}
struct ListNode* removeElements2(struct ListNode* head, int val) {
    if (!head) {
        return head;
    }
    struct ListNode* newHead = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* p=NULL;
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    while (head) {
        if (head->val==val) {
            head=head->next;
        }else{
            newHead->val = head->val;
            p=newHead;
            break;
        }
    }
    if (p) {
        while (head->next != NULL) {
            if (head->next->val == val) {
                head->next = head->next->next;
            }else{
                head = head->next;
                newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
                newNode->val = head->val;
                newNode->next = NULL;
                p->next = newNode;
                p = newNode;
            }
        }
    }
    return newHead;
}
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    if (!l1 || !l2) {
        return NULL;
    }
    struct ListNode* result;
    result = malloc(sizeof(struct ListNode));
    struct ListNode* p = NULL;
    struct ListNode* newNode;
    int shouldP = 0;
    while (l1 && l2) {
        if (!p) {
            result->val = l1->val + l2->val;
            result->next = NULL;
            if (result->val>=10) {
                result->val -= 10;
                shouldP = 1;
            }
            p = result;
        }else{
            newNode = malloc(sizeof(struct ListNode));
            newNode->val = l1->val + l2->val;
            newNode->next = NULL;
            if (shouldP) {
                newNode->val += 1;
            }
            if (newNode->val>=10) {
                newNode->val -= 10;
                shouldP = 1;
            }else{
                shouldP = 0;
            }
            p->next = newNode;
            p = newNode;
        }
        l1 = l1->next;
        l2 = l2->next;
    }
    struct ListNode* l=NULL;
    if (l1 || l2) {
        
        if (l1) {
            l = l1;
        }
        if (l2) {
            l = l2;
        }
        while (l) {
            newNode = malloc(sizeof(struct ListNode));
            newNode->val = l->val;
            newNode->next = NULL;
            if (shouldP) {
                newNode->val += 1;
            }
            if (newNode->val>=10) {
                newNode->val -= 10;
                shouldP = 1;
            }else{
                shouldP = 0;
            }
            p->next = newNode;
            p = newNode;
            l = l->next;
        }
    }
    if (shouldP) {
        newNode = malloc(sizeof(struct ListNode));
        newNode->val = 1;
        newNode->next = NULL;
        p->next = newNode;
        p = newNode;
    }
    return result;
}




void listNodePlayExample(){
    struct ListNode n1;
    struct ListNode n2;
    struct ListNode n3;
    struct ListNode n4;
    struct ListNode n5;
    struct ListNode n6;
    struct ListNode n7;
    n1.val = 0;
    n2.val = 2;
    n3.val = 6;
    n4.val = 1;
    n5.val = 4;
    n6.val = 5;
    n7.val = 6;
    n1.next = NULL;
    n2.next = &n3;
    n3.next = NULL;
    n4.next = NULL;
    n5.next = &n6;
    n6.next = NULL;
    //    n7.next = NULL;
    //
    struct ListNode *n = addTwoNumbers(&n1, &n4);
    while (n!=NULL) {
        printf("%d\n", n->val);
        n = n->next;
    }
}
