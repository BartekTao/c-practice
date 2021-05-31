#include <iostream>
#include <vector>

using namespace std;

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

bool isSymmetric(TreeNode* root) {
    if(!root->left && !root->right) return true;

    return rootLeft(root->left) == rootRight(root->right);
}