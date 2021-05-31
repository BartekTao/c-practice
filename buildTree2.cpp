#include <iostream>
#include <vector>
#include <map>

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
map<int, int> idx_val;
int root_idx;

TreeNode* helper(int left_idx, int right_idx, vector<int>& preorder, vector<int>& inorder){
    if(left_idx > right_idx) return nullptr;
    int rootVal = preorder[root_idx];
    TreeNode* root = new TreeNode(rootVal);
    int inRootIdx = idx_val[rootVal];
    root_idx++;
    root->left = helper(left_idx, inRootIdx - 1, preorder, inorder);
    root->right = helper(inRootIdx + 1, right_idx, preorder, inorder);
    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    root_idx = 0;
    int id = 0;
    for(int val : inorder){
        idx_val[val] = id;
        id++;
    }
    return helper(root_idx, preorder.size()-1, preorder, inorder);
}

