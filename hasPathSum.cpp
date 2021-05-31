#include <iostream>
#include <vector>

using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool pathSum(TreeNode* root, int sum, int targetSum){
    if(!root) return false;
    root->val = root->val + sum;
    //判斷為最後節點
    if(!root->left && !root->right){
        if(root->val == targetSum)  return true;
    }
    return pathSum(root->left, root->val, targetSum) ||
            pathSum(root->right, root->val, targetSum);
}

bool hasPathSum(TreeNode* root, int targetSum) {
    return pathSum(root, 0, targetSum);
}

