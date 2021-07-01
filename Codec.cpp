#include <iostream>
#include <queue>
#include <string>
#include <sstream>
#include <list>

using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:
    void rserialize(TreeNode* root, string& ans) {
        ans+=root ? to_string(root->val)+"," : "#,";
        if(!root) return;
        rserialize(root->left, ans);
        rserialize(root->right, ans);
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans = "";
        rserialize(root, ans);
        return ans;
    }

    TreeNode* rdeserialize(list<string>& dataArray) {
        if (dataArray.front() == "#") {
            dataArray.erase(dataArray.begin());
            return nullptr;
        }

        TreeNode* root = new TreeNode(stoi(dataArray.front()));
        dataArray.erase(dataArray.begin());
        root->left = rdeserialize(dataArray);
        root->right = rdeserialize(dataArray);
        return root;
    }

    TreeNode* deserialize(string data) {
        list<string> dataArray;
        string str;
        for (auto& ch : data) {
            if (ch == ',') {
                dataArray.push_back(str);
                str.clear();
            } else {
                str.push_back(ch);
            }
        }
        if (!str.empty()) {
            dataArray.push_back(str);
            str.clear();
        }
        return rdeserialize(dataArray);
    }
};