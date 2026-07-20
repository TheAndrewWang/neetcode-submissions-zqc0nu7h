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
    int getSize(ListNode* head) {
        int length = 0;
        while (head != nullptr) {
            head = head->next;
            length++;
        }
        return length;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = head;
        ListNode* prev = head;
        for (int i = 0; i < (getSize(head) - n); i++) {
            dummy = dummy->next;
        }
        for (int i = 0; i < (getSize(head) - n - 1); i++) {
            prev = prev->next;
        }
        if (dummy == prev) {
            return dummy->next;
        }
        prev->next = dummy->next;

        return head;
    }
};
