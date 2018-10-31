//
//  ListNode.h
//  CTutorial
//
//  Created by techcul_iOS on 2018/10/26.
//  Copyright © 2018 techcul. All rights reserved.
//

#ifndef ListNode_h
#define ListNode_h

#include <stdio.h>
#include <stdlib.h>
#include "stdbool.h"

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB);

// 203
struct ListNode* removeElements(struct ListNode* head, int val);
// 2
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2);

// 234
bool isListNodePalindrome(struct ListNode* head);
// 876
struct ListNode* middleNode(struct ListNode* head);


void listNodePlayExample();
#endif /* ListNode_h */
