//
// Created by zhangyangshuo on 2020/12/26.
//

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};
static inline int maximum(int a , int b){
    return a > b ? a : b;
}


int dfs(struct TreeNode* root, int* max){
    if (root == NULL) {
        return 0;
    }

    /* In case of negative node value */
    int l = maximum(dfs(root->left, max), 0);
    int r = maximum(dfs(root->right, max), 0);

    int sum = root->val + l + r;
    if (sum > *max) {
        *max = sum;
    }

    /* The return value does not equal the sum value
     * since we need to return path through the root node
     */
    return root->val + maximum(l, r);
}

int maxPathSum(struct TreeNode* root){
    int max = INT_MIN;
    dfs(root, &max);
    return max;
}

int main(void)
{
    printf("%s\n","开始");


    struct TreeNode root;
    struct TreeNode node1;
    struct TreeNode node2;
    struct TreeNode node3;
    struct TreeNode node4;
    struct TreeNode node5;
    root.val = 1;
    node1.val = 2;
    node2.val = 3;
    node3.val = 4;
    node4.val = 5;
    node5.val = 6;

    root.left = &node1;
    root.right = &node2;
    node1.left = &node3;
    node3.left = NULL;
    node3.right = NULL;
    node1.right = &node4;
    node4.left = NULL;
    node4.right = NULL;
    node2.left = NULL;
    node2.right = &node5;
    node5.left = NULL;
    node5.right = NULL;

    printf("%d\n", maxPathSum(&root));
    return 0;
}