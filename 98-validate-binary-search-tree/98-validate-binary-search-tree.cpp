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
    /* Returns the maximum value in root node's subtree */
int bstMax(TreeNode* root)
{
	int mx = root -> val;
	if (root -> left)
		mx = max(mx , bstMax(root -> left)) ;
	if (root -> right)
		mx = max(mx , bstMax(root -> right)) ;
	return mx;
}
/* Returns the minimum value in root node's subtree */
int bstMin(TreeNode* root)
{
	int mn = root -> val;
	if (root -> left)
		mn = min(mn , bstMin(root -> left)) ;
	if (root -> right)
		mn = min(mn , bstMin(root -> right));
	return mn;
}
    
bool isValidBST (TreeNode* root)
{
	if (root == NULL) return true ;
	if (root -> left && root -> right)
	{
		int leftMax = bstMax(root->left);
		int rightMin = bstMin(root->right);
// Return false if root node's value does not follow BST Property 
        if (leftMax > root->val || rightMin < root->val)
		    return false;
	}
	if (root -> left)
	{
		int leftMax = bstMax (root->left);
		if (leftMax >= root->val)
			return false;
	}
	if (root -> right)
	{
		int rightMin = bstMin(root->right);
		if (rightMin <= root->val)
			return false;
	}
// Recursively check if left and right subtrees are BST or not
	bool left = isValidBST (root->left);
	bool right = isValidBST (root->right) ;
	if (left == true && right == true)
		return true;
	else
		return false;
}
};