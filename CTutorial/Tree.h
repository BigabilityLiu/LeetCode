//
//  Tree.h
//  CTutorial
//
//  Created by techcul_iOS on 2018/10/24.
//  Copyright © 2018 techcul. All rights reserved.
//

#ifndef Tree_h
#define Tree_h

#include <stdio.h>
#include "stdbool.h"
#include "stdlib.h"
#include <math.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
struct TreeNode* initTree(int *list);
void asPrintTree(struct TreeNode* tree);
// 100
bool isSameTree(struct TreeNode* p, struct TreeNode* q);
// 107
int** levelOrderBottom(struct TreeNode* root, int** columnSizes, int* returnSize);
// 110
bool isBalanced(struct TreeNode* root);
// 101
bool isSymmetric(struct TreeNode* root);

// 257
char** binaryTreePaths(struct TreeNode* root, int* returnSize);
// 437
int pathSum(struct TreeNode* root, int sum);

void treePlayExample();
#endif /* Tree_h */
