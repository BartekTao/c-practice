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

bool isSymmetric(TreeNode* root) {
    if(!root->left && !root->right) return true;

    return rootLeft(root->left) == rootRight(root->right);
}

vector<int> leftRes;
vector<int> rootLeft(TreeNode* root) {
    if(!root) {
        leftRes.push_back(NULL);
        return {};
    };
    leftRes.push_back(root->val);
    rootLeft(root->left);
    rootLeft(root->right);
    return leftRes;
}

vector<int> rightRes;
vector<int> rootRight(TreeNode* root) {
    if(!root) {
        rightRes.push_back(NULL);
        return {};
    }
    rightRes.push_back(root->val);
    rootRight(root->right);
    rootRight(root->left);
    return rightRes;
}
