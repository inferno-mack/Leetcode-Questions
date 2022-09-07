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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        //(root, vertical, level)
        //(vertical,level,values)
        map<int,map<int,multiset<int>>> nodes;
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        queue<pair<TreeNode*, pair<int,int>>> q;
        q.push({root,{0,0}}); //(node,{vertical,level})
        while(!q.empty()){
            auto p=q.front();
            q.pop();
            TreeNode* node=p.first;
            int vertical=p.second.first;
            int level=p.second.second;
            
            nodes[vertical][level].insert(node->val);
            if(node->left)
                q.push({node->left,{vertical-1,level+1}});
            if(node->right)
                q.push({node->right,{vertical+1,level+1}});
        }
        
        for(auto x:nodes){
            vector<int> temp;
            for(auto y:x.second){
                temp.insert(temp.end(),y.second.begin(),y.second.end());
            }
            ans.push_back(temp);
        }
        return ans;
    }
};