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
    int deepestLeavesSum(TreeNode* root) {
        if(root == nullptr)
            return 0;
        
        queue<TreeNode* > q;
        int sum;
        q.push(root);
        
        while(!q.empty()){
            
            int n = q.size();
            sum = 0; // re-initizlize each time until we get to the last level
            
            while(n--){
                TreeNode* temp = q.front();
                q.pop();
                
                sum += temp->val;
                
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
                
            }
            
        }
        
        return sum;
    }
};