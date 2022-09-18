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
    void reverse(vector<TreeNode*> vec){
        int len=vec.size();
        for(int i=0;i<len/2;i++)
            swap(vec[i]->val, vec[len-i-1]->val);
        return;
    }
    
    TreeNode* reverseOddLevels(TreeNode* root) {
        if(root==NULL) return root;
        
        queue<TreeNode*> q;
        q.push(root);
        bool flag=false;
        while(!q.empty()){
            int len=q.size();
            vector<TreeNode*> temp;
            for(int i=0;i<len;i++){
                TreeNode* node=q.front();
                q.pop();
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
                temp.push_back(node);
            }
            if(flag)
                reverse(temp);
            flag=!flag;
        }
        return root;
    }
};