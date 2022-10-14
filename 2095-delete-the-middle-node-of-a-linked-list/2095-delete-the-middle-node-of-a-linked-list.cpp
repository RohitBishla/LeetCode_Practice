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
    void mid(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* before = slow;
        while(fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            before = slow;
            slow = slow->next;
        }
        before->next = before->next->next;
        return;
    }
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head == NULL || head->next == NULL) return NULL;
        mid(head);
        return head;
    }
};