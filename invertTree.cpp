//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* helper(TreeNode* root) {
    TreeNode* ans = root;
    ans->right = helper(root->left);
    ans->left = helper(root->right);
}

TreeNode* invertTree(TreeNode* root) {
    if(!root) return nullptr;
    TreeNode* ans = new TreeNode(root->val);
    ans->right = invertTree(root->left);
    ans->left = invertTree(root->right);
    return ans;
}