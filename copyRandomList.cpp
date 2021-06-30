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

//方法一: hashtable
/*Node* copyRandomList(Node* head) {
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
}*/

//方法二: 從舊有node變形複製
Node* copyRandomList(Node* head) {
    //每個節點後面複製前一個節點
    // A-> A'-> B-> B'-> C-> C'
    Node *curr = head;
    while (curr)
    {
        Node *temp = curr->next;
        curr->next = new Node(curr->val);
        curr->next->next = temp;
        curr = curr->next->next;
    }

    //建立關聯-random
    curr = head;
    while (curr)
    {
        if(curr->random){
            curr->next->random = curr->random->next;
        }
        curr = curr->next->next;
    }
    //重建關聯-next
    Node* ans = head->next;
    curr = head;
    Node* newCurr = head->next;
    while(curr){
        curr->next = curr->next->next;
        if(newCurr->next)
            newCurr->next = newCurr->next->next;
        curr = curr->next;
        newCurr = newCurr->next;
    }
    return ans;
}
