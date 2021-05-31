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

int rootIndex;
map<int, int> idx_map;

TreeNode* helper(int leftNode, int rightNode, vector<int>& inorder, vector<int>& postorder){
    if(leftNode > rightNode) return nullptr;

    TreeNode* root = new TreeNode(postorder[rootIndex]);
    int inRootIndex = idx_map[postorder[rootIndex]];
    rootIndex--;
    root->right = helper(inRootIndex+1, rightNode, inorder, postorder);
    root->left = helper(leftNode, inRootIndex-1, inorder, postorder);

    return root;
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    rootIndex = postorder.size()-1;
    int idx = 0;
    for(auto& val : inorder){
        idx_map[val] = idx++;
    }
    return helper(0, rootIndex, inorder, postorder);
}