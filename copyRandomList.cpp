#include <iostream>
#include <unordered_map>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

Node* copyRandomList(Node* head) {
    if(!head) return {};
    unordered_map<Node*, Node*> node_map;
    Node* curr = head;
    while(curr){
        node_map[curr] = new Node(curr->val);
        curr = curr->next;
    }
    curr = head;
    while(curr){
        node_map[curr]->next = node_map[curr->next];
        node_map[curr]->random = node_map[curr->random];
        curr = curr->next;
    }
    return node_map[head];
}