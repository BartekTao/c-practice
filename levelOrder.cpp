#include <vector>
#include <queue>

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



vector<vector<int>> levelOrder(TreeNode* root) {
    queue<TreeNode*> queue;
    vector<vector<int>> res;

    if(!root) return {};
    queue.push(root);

    int j = queue.size();
    vector<int> r;
    while(!queue.empty()){
        TreeNode* temp = queue.front();
        r.push_back(temp->val);
        
        if(temp->left){
            queue.push(temp->left);
        }
        if(temp->right){
            queue.push(temp->right);
        }

        queue.pop();
        --j;
        if(j == 0){
            res.push_back(r);
            r.erase(r.begin(), r.end());
            j = queue.size();
        };
    }
    return res;
}