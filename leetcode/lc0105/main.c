//
// Created by zhangyangshuo on 2021/1/4.
//

#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};
struct TreeNode* helper(int* preorder, int preStart, int preEnd , int* inorder, int inStart,int inEnd){
    if(preStart>preEnd || inStart > inEnd ){
        return NULL;
    }
    struct TreeNode *root = malloc(sizeof(*root));
    root->val = preorder[preStart];

    //中序遍历的根节点位置
    int inRoot = inStart;
    while(preorder[preStart]!=inorder[inRoot]){
        inRoot++;
    }
    //左侧的长度
    int len = inRoot - inStart;
    root->left = helper(preorder, preStart+1, preStart + len  , inorder, inStart, inRoot-1);
    root->right = helper(preorder,preStart+len+1,preEnd,inorder,inRoot+1,inEnd);

    return root;
}
struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize){
    return helper(preorder,0,preorderSize-1, inorder,0,inorderSize-1);
}

static void print(struct TreeNode *node)
{
    if (node == NULL) {
        printf("# ");
        return;
    }
    printf("%d ", node->val);
    print(node->left);
    print(node->right);
}

int main(void ){
    int preorder[] = {3,9,20,15,7};
    int inorder[] = {9,3,15,20,7};

    struct TreeNode* root = buildTree(preorder, sizeof(preorder) / sizeof(*preorder),inorder, sizeof(inorder) / sizeof(*inorder));
    print(root);


}