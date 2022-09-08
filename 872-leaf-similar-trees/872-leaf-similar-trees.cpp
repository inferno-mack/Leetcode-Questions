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
    void traversal(TreeNode* node, vector<int> &res){
        if(!node->left and !node->right) 
            res.push_back(node->val);
        if(node->left) traversal(node->left, res);
        if(node->right) traversal(node->right, res);
    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> ans1,ans2;
        traversal(root1, ans1);
        traversal(root2, ans2);
        
        return (ans1==ans2);
    }
};