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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL) return head;
        
        ListNode* node=head;
        // int val = head->val;
        
        while(node)
        {
            if(node->next!=NULL and node->next->val==node->val)
            {
                node->next=node->next->next;
            }
            if(node->next and node->next->val != node->val)
                node = node->next;
            
            else if(node ->next == NULL) node = node->next;
            
        }
        return head;
    }
};