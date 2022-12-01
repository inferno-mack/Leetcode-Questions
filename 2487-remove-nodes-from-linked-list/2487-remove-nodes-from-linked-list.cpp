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
    ListNode* reverseNodes(ListNode* node){
        ListNode* newNode=NULL;
        while(node!=NULL){
            ListNode* next=node->next;
            node->next=newNode;
            newNode=node;
            node=next;
        }
        return newNode;
    }
    
    ListNode* removeNodes(ListNode* head) {
        if(!head) return NULL;
        
        head = reverseNodes(head);
        
        ListNode* newH = new ListNode(INT_MIN);
        newH->next = head;
        ListNode* temp = newH;
        
        while(temp->next){
            if(temp->next->val < temp->val){
                temp->next = temp->next->next;
            }else{
                temp = temp->next;
            }
        }
        
        head = reverseNodes(newH->next);
        
        return head;
    }
};