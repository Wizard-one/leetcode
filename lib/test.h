#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct ListNode* init(int* l,int ns);

void listprint(struct ListNode * l);

struct ListNode {
    int val;
    struct ListNode *next;
};

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};