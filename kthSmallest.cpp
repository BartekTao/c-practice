#include <vector>
#include <algorithm>

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

int rkthSmallestAns = -1;
int rkthSmallestCount = 0;
void rkthSmallest(TreeNode* root, int k){
    if(!root) return;
    rkthSmallest(root->left, k);
    rkthSmallestCount++;
    if(rkthSmallestCount == k){
        rkthSmallestAns = root->val;
    }
    rkthSmallest(root->right, k);
}
int kthSmallest(TreeNode* root, int k) {
    rkthSmallest(root, k);
    return rkthSmallestAns;
}