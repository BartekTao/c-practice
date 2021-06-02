#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> levelQueue;
        levelQueue.push(root);

        int l = levelQueue.size();
        while(!levelQueue.empty()){
            Node* temp = levelQueue.front();

            if(temp->left)
                levelQueue.push(temp->left);
            if(temp->right)
                levelQueue.push(temp->right);

            l--;
            levelQueue.pop();
            if(l == 0){
                temp->next = NULL;
                l = levelQueue.size();
            }else{
                temp->next = levelQueue.front();
            }
        }
        return root;
    }
};