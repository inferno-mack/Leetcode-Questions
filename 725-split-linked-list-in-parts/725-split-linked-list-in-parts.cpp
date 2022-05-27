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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans ;
        int n = 0;
        ListNode* t = head;
        while(t){
            n++;
            t = t->next;
        }
        
        t = head;
        int x = n%k;
        int z = 1;
        while(n/k + x and z<=k){
            int p = n/k;
            if(x) p++, x--;
            if(t == NULL){
                ans .push_back(NULL);
                continue;
            }
            ListNode* temp = t;
            int c = 0;
            
            while((++c) < p and t){
                    t = t->next;
            }
            
            ListNode* d = t;
            if(t)
                t = t->next;
            if(d)
            d->next = NULL;
            ans.push_back(temp);
            z++;
        }
        while(z<=k) ans.push_back(NULL),z++;
        
        return ans;
    }
};