/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    map<TreeNode*, TreeNode*> mp;
    void parent(TreeNode* root){
        if(root == NULL) return;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            if(node->left){
                mp[node->left]=node;
                q.push(node->left);
            }
            if(node->right){
                mp[node->right]=node;
                q.push(node->right);
            }
        }
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        if(k == 0){
            ans.push_back(target->val);
            return ans;
        }
        map<TreeNode*, bool> m;
        if(root == NULL) return ans;
        if(target == NULL) return ans;
        
        parent(root);
        vector<vector<int>> res;
        queue<TreeNode*> q;
        q.push(target);
        m[target]=true;
        while(!q.empty()){
            int n=q.size();
            vector<int> level;
            while(n--){
                TreeNode* node=q.front();
                q.pop();
                if(node->left and !m[node->left]){
                    level.push_back(node->left->val);
                    q.push(node->left);
                    m[node->left]=true;
                }
                if(node->right and !m[node->right]){
                    level.push_back(node->right->val);
                    q.push(node->right);
                    m[node->right]=true;
                }
                if(mp[node] and !m[mp[node]]){
                    level.push_back(mp[node]->val);
                    q.push(mp[node]);
                    m[mp[node]]=true;
                }
            }
            res.push_back(level);
        }
        if(res.size()<k) return {};
        return res[k-1];
    }
};