/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB==NULL)
            return NULL;
        int len1=0, len2=0;
        ListNode* temp=headA;
        while(temp->next){
            len1++;
            temp=temp->next;
        }
        temp=headB;
        while(temp->next){
            len2++;
            temp=temp->next;
        }
        
        if(len1<=len2){
            int d=len2-len1;
            int count=0;
            ListNode* a=headA;
            ListNode* b=headB;
            while(b->next and count!=d){
                b=b->next;
                count++;
            }
            
            while(a!=NULL and b!=NULL){
                if(a==b) return a;
                a=a->next;
                b=b->next;
            }
        }
        else{
            int d=len1-len2;
            int count=0;
            ListNode* a=headA;
            ListNode* b=headB;
            while(a->next and count!=d){
                a=a->next;
                count++;
            }
            
            while(b!=NULL and a!=NULL){
                if(a==b) return a;
                a=a->next;
                b=b->next;
            }
        }
        return NULL;
    }
};