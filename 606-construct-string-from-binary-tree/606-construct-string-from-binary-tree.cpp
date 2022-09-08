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
    void helper(TreeNode* node, string &ans){
        if(node->left){
            ans+="(";
            ans+=to_string(node->left->val);
            helper(node->left, ans);
            ans+=")";
        }
        if(node->right){
            if(node->left==NULL) ans+="()";
            ans+="(";
            ans+=to_string(node->right->val);
            helper(node->right, ans);
            ans+=")";
        }
    }
    
    string tree2str(TreeNode* root) {
        string ans="";
        if(root==NULL) return ans;
        ans+=to_string(root->val);
        helper(root, ans);
        return ans;
    }
};