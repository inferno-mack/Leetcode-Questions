/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        vector<pair<int,pair<int,int>>> ans;
        queue<pair<TreeNode*,TreeNode*>> q;
        q.push({root,root});
        int level=0;
        while(q.size()){
            int n=q.size();
            level++;
            while(n--){
                auto parent=q.front().first;
                auto node=q.front().second;
                q.pop();
                ans.push_back({parent->val,{node->val,level}});
                if(node->left) q.push({node,node->left});
                if(node->right) q.push({node,node->right});
            }
        }
        
        int l1,l2,p1,p2;
        for(int i=0;i<ans.size();i++){
            int par=ans[i].first;
            int nod=ans[i].second.first;
            int lev=ans[i].second.second;
            if(nod==x){
                p1=par;
                l1=lev;
            }
            
            if(nod==y){
                p2=par;
                l2=lev;
            }
        }
        
        if(l1==l2 and p1!=p2)
            return true;
        return false;
    }
};