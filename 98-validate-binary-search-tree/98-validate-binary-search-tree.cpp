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
    bool inorder(TreeNode* root, TreeNode*& prev)
{
	/* Perform inorder traversal and keep track of previous node */
	if (root) {
		if (!inorder(root->left, prev))
			return false;
		/* If inorder is not sorted then return false */
		if (prev != NULL && root->val <= prev->val)
			return false;
		prev = root;
		return inorder(root->right, prev);
	}
	return true;
}
bool isValidBST(TreeNode* root)
{
	TreeNode* prev = NULL;
	return inorder(root, prev);
}

};