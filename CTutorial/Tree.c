//
//  Tree.c
//  CTutorial
//
//  Created by techcul_iOS on 2018/10/24.
//  Copyright © 2018 techcul. All rights reserved.
//

#include "Tree.h"

bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    if(p==NULL && q==NULL){
        return 1;
    }else if(p==NULL || q==NULL){
        return 0;
    }else{
        if (p->val == q->val){
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        }else{
            return 0;
        }
    }
}

void putTreeInList(struct TreeNode* root, int list[10][10], int *sizes, int index, int *size){
    if (root != NULL) {
        list[index][sizes[index]] = root->val;
        if (*size <= index) {
            (*size)++;
        }
        sizes[index]++;
        putTreeInList(root->left, list, sizes, index + 1, size);
        putTreeInList(root->right, list, sizes, index + 1, size);
    }
    
}
int** levelOrderBottom(struct TreeNode* root, int** columnSizes, int* returnSize) {
    int ascList[10][10];
    int** descList;
    int sizes[10];
    int size=0;
    for (int i=0; i<10; i++) {
        sizes[i] = 0;
    }
    putTreeInList(root, ascList, sizes, 0, &size);
    
    returnSize = &size;
    descList = (int **)malloc(size * sizeof(int *));
    columnSizes = (int **)malloc(size * sizeof(int *));
    int i=size-1,j;
    int currectSize, *currectList;
    for (; i>=0; i--) {
        currectSize = sizes[i];
        currectList = (int *)malloc(currectSize * sizeof(int));
        for (j=0; j<currectSize; j++) {
            currectList[j] = ascList[i][j];
        }
        columnSizes[size-i-1] = currectSize;
        descList[size-i-1] = &currectList;
    }
    return descList;
}
int maxDepth(struct TreeNode* root){
    if (root == NULL) {
        return 0;
    }
    return maxDepth(root->left) > maxDepth(root->right) ? maxDepth(root->left)+1 : maxDepth(root->right)+1;
}
bool isBalanced(struct TreeNode* root){
    if (root == NULL) {
        return 1;
    }else{
        int x=0;
        if (root->left !=NULL && root->right != NULL){
            return isBalanced(root->left) && isBalanced(root->right);
        }else if (root->left !=NULL || root->right != NULL){
            x = maxDepth(root->left) - maxDepth(root->right);
            if (x < 2 && x > -2) {
                return 1;
            }else{
                return 0;
            }
        }else{
            return 1;
        }
    }
}
int minDepth(struct TreeNode* root) {
    int l,r;
    if (root == NULL) {
        return 0;
    }
    if (root->left == NULL){
        return minDepth(root->right) + 1;
    }
    if (root->right == NULL){
        return minDepth(root->left) + 1;
    }
    l = minDepth(root->left) + 1;
    r = minDepth(root->right) + 1;
    return  l < r ? l : r;
}
bool hasPathSum(struct TreeNode* root, int sum) {
    if (root == NULL) {
        return false;
    }
    if (root->left == NULL && root->right == NULL) {
        return root->val == sum;
    }else if(root->left == NULL){
        return hasPathSum(root->right, sum - root->val);
    }else if(root->right == NULL){
        return hasPathSum(root->left, sum - root->val);
    }else{
        return hasPathSum(root->right, sum - root->val) && hasPathSum(root->left, sum - root->val);
    }
}

bool isMirror(struct TreeNode* left, struct TreeNode* right) {
    if (left == NULL || right == NULL) {
        return left == NULL && right == NULL;
    }
    if (left->val != right->val) {
        return false;
    }
    return isMirror(left->left, right->right) && isMirror(left->right, right->left);
}
bool isSymmetric(struct TreeNode* root) {
    if (root == NULL) {
        return false;
    }
    return isMirror(root->left, root->right);
}
void addToPath(struct TreeNode* node, char*** array, int** returnSize, int *size, char * temp){
    
}
//char** binaryTreePaths(struct TreeNode* root, int* returnSize) {
//    int size=0;
//    char** result;
//    
//    if (root) {
//        size++;
//        returnSize = (int *)realloc(returnSize, size * sizeof(int));
//        returnSize[size-1] = 1;
//        result = (char **)realloc(result, size * sizeof(int *));
//        result[size-1] = (char *)realloc(result[size-1], returnSize[size-1] * sizeof(char *));
//        result[size-1][returnSize[size-1]] =
//    }
//}
void pathOneNode(struct TreeNode* root, int* count,int sum,int total) {
    total += root->val;
    if (total == sum) {
        (*count)++;
    }
    if (root->left) {
        pathOneNode(root->left, count, sum, total);
    }
    if (root->right) {
        pathOneNode(root->right, count, sum, total);
    }
    
}
void pathTraverse(struct TreeNode* root, int* count,int sum) {
    if (root) {
        pathOneNode(root, count, sum, 0);
        if (root->left) {
            pathTraverse(root->left, count, sum);
        }
        if (root->right) {
            pathTraverse(root->right, count, sum);
        }
    }
}
int pathSum(struct TreeNode* root, int sum) {
    int result=0;
    pathTraverse(root, &result, sum);
    return result;
}
int max(int a, int b){
    return a > b ? a : b;
}
int maxDistance(struct TreeNode* root){
    if (!root) {
        return 0;
    }
    int distanceRoot = maxDepth(root->left) + maxDepth(root->right);
    int distanceLeft = maxDistance(root->left);
    int distanceRight = maxDistance(root->right);
    return max(max(distanceLeft, distanceRight),distanceRoot);
}
int diameterOfBinaryTree(struct TreeNode* root) {
    return maxDistance(root);
}





void treePlayExample(){
    
    struct TreeNode n3,n9,n20,n15,n7;
    n3.val = 3;
    n3.left = &n9;
    n3.right = &n20;
    
    n9.val = 9;
    n9.left = NULL;
    n9.right = NULL;
    
    n20.val = 20;
    n20.left = &n15;
    n20.right = &n7;
    
    n15.val = 15;
    n15.left = NULL;
    n15.right = NULL;
    
    n7.val = 7;
    n7.left = NULL;
    n7.right = NULL;
}
