#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};

TreeNode *ans;
TreeNode *pre;
void helper(TreeNode* pRootOfTree) {
    //inorder取得TreeNode
    if(!pRootOfTree) return;
    Convert(pRootOfTree->left);
    //add
    TreeNode *temp = new TreeNode(pRootOfTree->val);
    
    if(pre){
        temp->left = pre;
        pre->right = temp;
    }else{
        ans = temp;
    }
    pre = temp;
    
    Convert(pRootOfTree->right);
}

TreeNode * Convert(TreeNode* pRootOfTree) {

    helper(pRootOfTree);

    return ans;
}