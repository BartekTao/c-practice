#include <iostream>
#include <vector>
#include <treeNode.h>
#include <map>

using namespace std;

int rootIndex;
map<int, int> idx_map;
TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    rootIndex = postorder.size()-1;
    int idx = 0;
    for(auto& val : inorder){
        idx_map[val] = idx++;
    }
    return helper(0, rootIndex, inorder, postorder);
}

TreeNode* helper(int leftNode, int rightNode, vector<int>& inorder, vector<int>& postorder){
    if(leftNode > rightNode) return nullptr;

    TreeNode* root = new TreeNode(postorder[rootIndex]);
    int inRootIndex = idx_map[postorder[rootIndex]];
    rootIndex--;
    root->right = helper(inRootIndex+1, rightNode, inorder, postorder);
    root->left = helper(leftNode, inRootIndex-1, inorder, postorder);

    return root;
}