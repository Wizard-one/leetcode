#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct ListNode* ListInit(int* l,int ns);

void ListPrint(struct ListNode * l);

struct ListNode {
    int val;
    struct ListNode *next;
};

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void HeapSort(int* nums,int numsSize);

void TreeInit(struct TreeNode **T,int *nums,int *idx);

struct TreeNode* TreeInit_prein(int* preorder,int* inorder, int Size);

void TreePrint(struct TreeNode* root);

void printmat(int **mat, int matrixSize, int* matrixColSize);