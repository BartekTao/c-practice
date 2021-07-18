#include <iostream>
#include <vector>
#include <set>

using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode * a = headA;
    ListNode * b = headB;
    while(a != b){
        a = !a ? headB : a->next;
        b = !b ? headA : b->next;
    }
    return a;
}

/*
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    set<ListNode*> set;
    while(headA){
        set.insert(headA);
        headA = headA->next;
    }
    while(headB){
        if(set.count(headB) != 0){
            return headB;
        }
        headB = headB->next;
    }
    return nullptr;
}
*/