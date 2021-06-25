#include <iostream>

using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


ListNode *detectCycle(ListNode *head) {
    //2N速
    ListNode *fast = head;
    //N速
    ListNode *slow = head;

    //找到交點
    while(fast && fast->next){
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow) break;
    }
    if(!fast || !fast->next) return {};
    slow = head;
    while(slow != fast){
        fast = fast->next;
        slow = slow->next;
    }

    return fast;
}