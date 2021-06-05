#include <vector>
#include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

unordered_map<int, vector<TreeNode*>> ansMap;

vector<TreeNode*> allPossibleFBT(int n) {
    vector<TreeNode*> res;
    if(n%2 == 0) return res;
    if(!ansMap.count(n)){
        if(n == 1){
            res.push_back(new TreeNode(0));
            ansMap[n] = res;
            return res;
        }else{
            for(int i = 1; i<n; i=i+2){
                vector<TreeNode*> leftList = allPossibleFBT(i);
                vector<TreeNode*> rightList = allPossibleFBT(n-i-1);
                for(auto left : leftList){
                    for(auto right : rightList){
                        res.push_back(new TreeNode(0, left, right));
                    }
                }
            }
            ansMap[n] = res;
            return res;
        }    
    }
    
    return ansMap[n];
}