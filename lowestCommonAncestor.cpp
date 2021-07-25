
//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root->val > p->val && root->val > q->val){
        return lowestCommonAncestor(root->left, p, q);
    }
    else if(root->val < p->val && root->val < q->val){
        return lowestCommonAncestor(root->right, p, q);
    }else {
        return root;
    }
}

/*
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(!root) return {};
    if(root == p || root == q){
        return root;
    }
    TreeNode *ans1 = lowestCommonAncestor(root->left, p, q);
    TreeNode *ans2 = lowestCommonAncestor(root->right, p, q);
    if(!ans1 && !ans2){
        return {};
    }else if(ans1 && ans2){
        return root;
    }else{
        return ans1 ? ans1 : ans2;
    }
}
*/