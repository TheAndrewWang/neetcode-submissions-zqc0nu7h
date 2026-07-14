/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* newHead = new ListNode();
        while (head != nullptr) {
            newHead->val = head->val;
            ListNode* nextHead = new ListNode();
            nextHead->next = newHead;
            newHead = nextHead;
            head = head->next;
        } 

        return newHead->next;
    }
};
