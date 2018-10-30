//
//  utils.h
//  CTutorial
//
//  Created by techcul_iOS on 2018/9/20.
//  Copyright © 2018年 techcul. All rights reserved.
//

#ifndef utils_h
#define utils_h

#include <stdio.h>
#include "stdlib.h"
#include "string.h"
#include "limits.h"
#include "stdbool.h"

// 27
int removeElement(int* nums, int numsSize, int val);
// 58
extern int lengthOfLastWord(char* s);
// 66
extern int* plusOne(int* digits, int digitsSize, int* returnSize);
//67
char* addBinary(char* a, char* b);
//69
int mySqrt(int x);
// 70
int climbStairs(int n);
// 88
void merge(int* nums1, int m, int* nums2, int n);
//190
uint32_t reverseBits(uint32_t n);
uint32_t reverseBits2(uint32_t n);
// 191
int hammingWeight(uint32_t n);
// 118
int** generate(int numRows, int** columnSizes);
// 119
int* getRow(int rowIndex, int* returnSize);
// 121
int maxProfit(int* prices, int pricesSize);
// 122
int maxProfit2(int* prices, int pricesSize);
// 125
bool isPalindrome(char* s);
// 172
int trailingZeroes(int n);
//
// 198
int rob(int* nums, int numsSize);
// 202
bool isHappy(int n);
// 268
int missingNumber(int* nums, int numsSize);




//303
typedef struct {
    int *sums;
    int size;
} NumArray;
NumArray* numArrayCreate(int* nums, int numsSize);
int numArraySumRange(NumArray* obj, int i, int j);
void numArrayFree(NumArray* obj);

// 682
int calPoints(char** ops, int opsSize);
// 844
bool backspaceCompare(char* S, char* T);
#endif /* utils_h */


