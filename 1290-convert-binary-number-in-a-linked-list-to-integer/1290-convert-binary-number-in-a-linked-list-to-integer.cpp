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
    int getDecimalValue(ListNode* head) {
        
        if(head==NULL) return 0;
        ListNode* node=NULL;
        while(head)
        {
            ListNode* next=head->next;
            head->next=node;
            node=head;
            head=next;
        }
        
        int ans=0,i=0;
        while(node)
        {
            ans+=((node->val)*pow(2,i));
            i++;
            node=node->next;
        }
        
        return ans;
    }
};