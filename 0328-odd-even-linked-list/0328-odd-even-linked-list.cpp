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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* odd = head;
        if(head == NULL) return NULL;
        ListNode* even = head->next;
        if(even == NULL) return head;
        
        ListNode* temp = even->next;
        ListNode* evenHead = even;
        even->next = NULL;
        odd->next = NULL;
        int count = 3;
        while(temp != NULL){
            if(count%2 != 0){
                odd->next = temp;
                odd = odd->next;
                temp = temp->next;
                odd->next = NULL;
            }
            else{
                even->next = temp;
                temp = temp->next;
                even = even->next;
                even->next = NULL;
            }
            count++;
        }
        odd->next = evenHead;
        return head;
        
    }
};