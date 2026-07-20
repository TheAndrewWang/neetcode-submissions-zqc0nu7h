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
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* nextNode = slow->next;
        slow->next = nullptr;
        
        while (nextNode != nullptr) {
            ListNode* dummy = nextNode->next;
            nextNode->next = slow;
            slow = nextNode;
            nextNode = dummy;
        }

        ListNode* first = head;
        ListNode* second = slow;
        while(second != nullptr) {
            ListNode* dummyFirst = first->next;
            ListNode* dummySecond = second->next;
            first->next = second;
            if(second == dummyFirst) {
                break;
            }
            second->next = dummyFirst;
            first = dummyFirst;
            second = dummySecond;
        }
    }
};
