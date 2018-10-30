//
//  utils.c
//  CTutorial
//
//  Created by techcul_iOS on 2018/9/20.
//  Copyright © 2018年 techcul. All rights reserved.
//

#include "utils.h"

int removeElement(int* nums, int numsSize, int val) {
    int result = 0;
    for (int i = 0; i<numsSize; i++) {
        if (nums[i] != val) {
            nums[result++] = nums[i];
        }
    }
    return result;
}

int lengthOfLastWord(char* s) {
    int counter=0,end=0;
    while (s[end] != '\0') {
        if (s[end] == ' ') {
            if (s[end + 1] == '\0') {
                return counter;
            }else if(s[end + 1] != ' ') {
                counter = 0;
            }
        }else{
            counter++;
        }
        end++;
    }
    return counter;
}

int* plusOne(int* digits, int digitsSize, int* returnSize) {
//    returnSize = malloc(sizeof(int));
    *returnSize = digitsSize;
    int *returnArray = malloc((digitsSize) * sizeof(int));
    int stop_plus = 0;
    for (int i=digitsSize-1; i>=0; i--) {
        if (digits[i] == 9) {
            if (stop_plus) {
                returnArray[i] = digits[i];
            }else{
                if (i==0) {
                    *returnSize = digitsSize + 1;
                    returnArray[i] = 1;
                    returnArray = realloc(returnArray, (digitsSize + 1) * sizeof(int));
                    returnArray[digitsSize] = 0;
                }else{
                    returnArray[i] = 0;
                }
            }
        }else{
            if (stop_plus == 0) {
                returnArray[i] = digits[i] + 1;
                stop_plus = 1;
            }else{
                returnArray[i] = digits[i];
            }
        }
    }
    return returnArray;
}
char* addBinary(char* a, char* b) {
    unsigned long alength = strlen(a);
    unsigned long blength = strlen(b);
    // 多申请一个单位储存进位，如果计算后位0在最后删掉
    unsigned long clength = (alength > blength ? alength : blength) + 1;
    // 多申请一个单位储存'\0'
    char *c = malloc(sizeof(char) * (clength+1));
    int shouldUp = 0;
    int a_int,b_int;
    for (unsigned long i=clength-1; i>=0;) {
        if (i >= (clength-alength)) {
            if (a[i - (clength-alength)] == '1') {
                a_int = 1;
            }else{
                a_int = 0;
            }
        }else{
            a_int = 0;
        }
        if (i >= (clength-blength)) {
            if (b[i - (clength-blength)] == '1') {
                b_int = 1;
            }else{
                b_int = 0;
            }
        }else{
            b_int = 0;
        }
        int number = a_int + b_int + shouldUp;
        if (number == 0) {
            c[i] = '0';
            shouldUp = 0;
        }else if (number == 1){
            c[i] = '1';
            shouldUp = 0;
        }else if (number == 2){
            c[i] = '0';
            shouldUp = 1;
        }else{
            c[i] = '1';
            shouldUp = 1;
        }
        if (i>0) {
            i--;
        }else{
            break;
        }
    }
    c[clength] = '\0';
    if (c[0] == '0') {
        c = c + 1;
    }
    return c;
}

int mySqrt(int x) {
    if (x <= 0) {
        return 0;
    }
    unsigned int min=1,max=x,mid=0;
    while (1) {
        if (max - min == 1) return min;
        mid = (max + min) / 2;
        // 防止溢出
        if(INT_MAX / mid < mid){
            max = mid;
        }else{
            if (mid * mid > x) {
                max = mid;
            }else if (mid * mid == x){
                return mid;
            }else{
                min = mid;
            }
        }
    }
    return 0;
}
int climbStairs(int n) {
    if (n==0) {
        return 0;
    }else if (n == 1){
        return 1;
    }else if (n == 2){
        return 2;
    }else{
        return climbStairs(n-1) + climbStairs(n-2);
    }
}
void merge(int* nums1, int m, int* nums2, int n) {
    int nums[m + n],index1=0,index2=0;
    for(int i=0;i<m+n;i++){
        if (index1 == m) {
            nums[i] = nums2[index2];
            index2++;
        }else if(index2 == n){
            nums[i] = nums1[index1];
            index1++;
        }else if(nums1[index1]<=nums2[index2]){
            nums[i] = nums1[index1];
            index1++;
        }else{
            nums[i] = nums2[index2];
            index2++;
        }
    }
    for(int i=0;i<m+n;i++){
        nums1[i] = nums[i];
    }
}
uint32_t reverseBits(uint32_t n) {
    uint32_t result=0,currtNumber=1;
    int a[32];
    int suffixCount=0;
    while (n!=0) {
        a[32 - 1 - suffixCount] = n%2;
        n = n/2;
        suffixCount++;
    }
    for (int i=0; i<32; i++) {
        if (i>0) {
            currtNumber*=2;
        }
        if (i >= 32-suffixCount) {
            result = result + currtNumber*a[i];
        }
    }
    return result;
}
uint32_t reverseBits2(uint32_t n) {
    uint32_t result=0,r=1,i=0;
    while (i<32) {
        r = n & 1;
        n = n >> 1;
        result = result | r;
        if (i!=31) {
            result = result << 1;
        }
        i++;
    }
    return result;
}
int hammingWeight(uint32_t n) {
    int result=0;
    // Method 1
    for (int i=0; i<32; i++) {
        result += (n & 1);
        n = n >> 1;
    }
    // Method 2
//    while (n!=0) {
//        result+=n%2;
//        n = n/2;
//    }
    return result;
}

int** generate(int numRows, int** columnSizes) {
    int** result=NULL;
    result = (int **)malloc(numRows * sizeof(int *));
    *columnSizes = (int *)malloc(numRows * sizeof(int));
    for (int i=0; i<numRows; i++) {
        (*columnSizes)[i] = i + 1;
        result[i] = (int *)malloc(sizeof(int *) * (i+1));
        result[i][0] = 1;
        result[i][i] = 1;
        for (int j=1; j<i; j++) {
            result[i][j] = result[i-1][j-1] + result[i-1][j];
        }
    }
    return result;
}
int* getRow(int rowIndex, int* returnSize) {
    *returnSize = rowIndex + 1;
    int** lists=NULL;
    lists = (int **)malloc((rowIndex + 1) * sizeof(int *));
    for (int i=0; i<*returnSize; i++) {
        lists[i] = (int *)malloc(sizeof(int *) * (i+1));
        lists[i][0] = 1;
        lists[i][i] = 1;
        for (int j=1; j<i; j++) {
            lists[i][j] = lists[i-1][j-1] + lists[i-1][j];
        }
    }
    int* result = lists[rowIndex];
    free(lists);
    return result;
}
int maxProfit(int* prices, int pricesSize) {
    int result = 0,minPrice = INT_MAX;
    for (int i=0; i<pricesSize; i++) {
        if (prices[i] < minPrice) {
            minPrice = prices[i];
        }
        if (prices[i]-minPrice > result) {
            result = prices[i]-minPrice;
        }
    }
    return result;
}
int maxProfit2(int* prices, int pricesSize) {
    int result=0,inPrice=-1;
    for (int i=0; i<pricesSize; i++) {
        if(i==pricesSize-1){
            if (inPrice!=-1) {
                result += prices[i] - inPrice;
            }
        }else{
            if (inPrice==-1){
                if (prices[i+1] > prices[i]) {
                    inPrice = prices[i];
                }
            }else{
                if (prices[i+1] < prices[i]) {
                    result += prices[i] - inPrice;
                    inPrice = -1;
                }
            }
        }
    }
    return result;
}
bool isPalindrome(char* s) {
    unsigned long length = strlen(s);
    if (length==0) {
        return true;
    }
    int list[length];
    int currentIndex=0;
    while (*s != '\0') {
        if ((*s >= 48 && *s <=57) || (*s >= 65 && *s <=90)){
            list[currentIndex++] = (int)*s;
        }
        if (*s >= 97 && *s <=122){
            list[currentIndex++] = (int)*s - 32;
        }
        s++;
    }
    for (int i=0; i<currentIndex/2; i++) {
        if (list[i] != list[currentIndex - 1 - i]){
            return false;
        }
    }
    return true;
}
int trailingZeroes(int n) {
    int result=0,i=1;
    int numOf2=0;
    int numOf5=0;
    unsigned long  number=1;
    while (i<=n) {
        number = number * i++;
        while (number%10==0) {
            result++;
            number/=10;
        }
        while (number%2==0) {
            numOf2++;
            number/=2;
        }
        while (number%5==0) {
            numOf5++;
            number/=5;
        }
        if (numOf2>0 && numOf5>0) {
            if (numOf2>=numOf5) {
                result += numOf5;
                numOf5 -= numOf5;
                numOf2 -= numOf5;
            }else{
                result += numOf2;
                numOf2 -= numOf2;
                numOf5 -= numOf2;
            }
        }
    }
    return result;
}
#define max(a, b) ((a)>(b)?(a):(b))
int rob(int num[], int n) {
    int a = 0;
    int b = 0;
    
    for (int i=0; i<n; i++)
    {
        if (i%2==0)
        {
            a = max(a+num[i], b);
        }
        else
        {
            b = max(a, b+num[i]);
        }
    }
    
    return max(a, b);
}
int ishappyHelper(int n){
    int result=0,num=0;
    while (n!=0) {
        num = n%10;
        n = n/10;
        result+=(num * num);
    }
    return result;
}
bool isHappy(int n) {
    int slow=n;
    int fast=n;
    do {
        slow = ishappyHelper(slow);
        fast = ishappyHelper(fast);
        fast = ishappyHelper(fast);
    }while (slow != fast);
    return slow == 1;
}

NumArray* numArrayCreate(int* nums, int numsSize) {
    NumArray* na = (NumArray*)malloc(sizeof(NumArray));
    int* sums = (int*)malloc(sizeof(int)*(numsSize+1));
    na->size = numsSize;
    na->sums = sums;
    *sums = 0;
    for (int i=1; i<=numsSize; i++) {
        *(sums+i) = *(sums+i-1) + *(nums+i-1);
    }
    return na;
}

int numArraySumRange(NumArray* obj, int i, int j) {
    return *(obj->sums+j+1) - *(obj->sums + i);
}

void numArrayFree(NumArray* obj) {
    free(obj->sums);
    free(obj);
}
int missingNumber(int* nums, int numsSize) {
    int result=0;
    for (int i=0; i<numsSize; i++) {
        result += *(nums + i);
    }
    return (numsSize+1)*numsSize/2 - result;
}
int strToInt(char * s){
    int result=0;
    int isPositive = 1;
    while (*s == '+' || *s == '-') {
        if (*s == '-') {
            isPositive *= -1;
        }
        s++;
    }
    while (*s >='0' && *s<='9') {
        result *= 10;
        result += (*s - '0');
        s++;
    }
    return result*isPositive;
}
int calPoints(char** ops, int opsSize) {
    int result=0;
    int roundScores[opsSize+1];
    int currRound=0;
    char* currOperation;
    for(int i=0; i<opsSize; i++){
        currOperation = *(ops + i);
        if (strcmp(currOperation, "+") == 0) {
            roundScores[currRound] = roundScores[currRound-1] + roundScores[currRound-2];
            result += roundScores[currRound];
            currRound++;
        }
        else if (strcmp(currOperation, "D") == 0) {
            roundScores[currRound] = roundScores[currRound-1]*2;
            result += roundScores[currRound];
            currRound++;
        }
        else if (strcmp(currOperation, "C") == 0) {
            result -= roundScores[currRound-1];
            currRound--;
        }else{
            roundScores[currRound] =  strToInt(currOperation);
            result += roundScores[currRound];
            currRound++;
        }
    }
    return result;
}
bool backspaceCompare(char* S, char* T) {
    int sStart=0;
    int sEnd=0;
    int tStart=0;
    int tEnd=0;
    while (*(S+sEnd) != '\0') {
        if (*(S+sEnd) == '#') {
            sStart--;
        }else{
            *(S+sStart++) = *(S+sEnd);
        }
        if (sStart<0) {
            sStart=0;
        }
        sEnd++;
    }
    while (*(T+tEnd) != '\0') {
        if (*(T+tEnd) == '#') {
            tStart--;
        }else{
            *(T+tStart++) = *(T+tEnd);
        }
        if (tStart<0) {
            tStart=0;
        }
        tEnd++;
    }
    if (sStart != tStart) {
        return false;
    }
    for (int i=0; i<sStart; i++) {
        if (*(S + i) != *(T + i)) {
            return false;
        }
    }
    return true;
}
