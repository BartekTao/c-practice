#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


// Encodes a tree to a single string.
string serialize(TreeNode* root) {
    
}

//高度
int level = 1;
// Decodes your encoded data to tree.
TreeNode* deserialize(string data) {
    queue<string> dataQueue;
    string tempVal;
    for (int i = 0; i < data.size(); i++){
        if(data[i] == ','){
            dataQueue.push(tempVal);
            tempVal = "";
            continue;
        }
        tempVal+=data[i];
    }
    return deserializeHelper(dataQueue);
}

TreeNode* deserializeHelper(queue<string> dataQueue){
    string rootVal = dataQueue.front();
    dataQueue.pop();
}