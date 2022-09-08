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
    void traversal(TreeNode* node, set<int> &res){
        res.insert(node->val);
        if(node->left) traversal(node->left, res);
        if(node->right) traversal(node->right, res);
    }
    
    bool isUnivalTree(TreeNode* root) {
        set<int> ans;
        traversal(root, ans);
        if(ans.size()==1) return true;
        return false;
    }
};