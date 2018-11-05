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
        return true;
    }else if(p==NULL || q==NULL){
        return false;
    }else{
        if (p->val == q->val){
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        }else{
            return false;
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
int height(struct TreeNode* root, int* result){
    if (!root) {
        return 0;
    }
    int lheight = height(root->left, result);
    int rheight = height(root->right, result);
    
    if (lheight + rheight > *result) {
        *result = lheight + rheight;
    }
    
    return lheight > rheight ? lheight + 1 : rheight + 1;
}
int diameterOfBinaryTree2(struct TreeNode* root) {
    int result=0;
    height(root, &result);
    return result;
}
void arrayBST(struct TreeNode* root,int** array, int* size) {
    if (!root) {
        return ;
    }
    (*size)++;
    *array = realloc(*array, (*size) * sizeof(int));
    (*array)[*size-1] = root->val;
    arrayBST(root->left, array, size);
    arrayBST(root->right, array, size);
}
void addToBST(struct TreeNode* root,int** array, int size) {
    if (!root) return ;
    int newValue = root->val;
    for (int i=0; i<size; i++) {
        if ((*array)[i] > root->val) {
            newValue += (*array)[i];
        }
    }
    root->val = newValue;
    addToBST(root->left, array, size);
    addToBST(root->right, array, size);
}
struct TreeNode* convertBST(struct TreeNode* root) {
    int size=0;
    int* array;
    arrayBST(root,&array, &size);
    addToBST(root, &array, size);
    return root;
}
void compute_sums (struct TreeNode *root, int *curr_sum) {
    
    if (root == NULL) return;
    
    //We go as far right as we can, so we know that the value on the far
    //right will be greater than all the other values, then we recursively
    //update the curr_sum to add to each node:
    compute_sums (root->right, curr_sum);
    root->val += *curr_sum;
    *curr_sum = root->val;
    //Now we traverse to the left, since everything on the left sub-tree
    //will be less than the value at the root node:
    compute_sums(root->left, curr_sum);
    
}

struct TreeNode * convertBST2(struct TreeNode *root) {
    int curr_sum = 0;
    compute_sums(root, &curr_sum);
    
    return root;
}
int sumNode(struct TreeNode* root, int* total) {
    if (!root) {
        return 0;
    }
    int lSum = sumNode(root->left, total);
    int rSum = sumNode(root->right, total);
    *total += abs(lSum - rSum);
    return lSum + rSum + root->val;
}
int findTilt(struct TreeNode* root) {
    int result=0;
    sumNode(root, &result);
    return result;
}
void isSubTreeTraverse(struct TreeNode* s, struct TreeNode* t, bool* result) {
    if (*result) {
        return;
    }
    if (s->left) {
        isSubTreeTraverse(s->left, t, result);
    }
    if (s->right) {
        isSubTreeTraverse(s->right, t, result);
    }
    if (isSameTree(s, t)){
        *result = true;
        return;
    }
}
bool isSubtree(struct TreeNode* s, struct TreeNode* t) {
    bool result = false;
    isSubTreeTraverse(s, t, &result);
    return result;
}
struct TreeNode* lowestCommonAncestorHelper(struct TreeNode* root, int min, int max){
    if (root->val >= min & root->val <= max){
        return root;
    }
    else if (root->val > min){
        return lowestCommonAncestorHelper(root->left, min, max);
    }
    else {
        return lowestCommonAncestorHelper(root->right, min, max);
    }
}
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if (p->val >= q->val) {
        return lowestCommonAncestorHelper(root, q->val, p->val);
    }else{
        return lowestCommonAncestorHelper(root, p->val, q->val);
    }
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
