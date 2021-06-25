#include <iostream>

using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
ListNode *newHead;
ListNode* reverseList(ListNode* head) {
    helper(head);

    return newHead;
}
ListNode* helper(ListNode* head) {
    if(!head || !head->next){
        newHead = head;
        return head;
    }
    helper(head->next)->next = head;
    head->next = nullptr;
    return head;
}