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
    
    TreeNode* solve(TreeNode* root) {
        if(root == NULL)
            return NULL;
        
        if(!root->left && !root->right)
            return new TreeNode(root->val);
            
        TreeNode* temp = new TreeNode(root->val);
        temp->left = solve(root->right);
        temp->right = solve(root->left);
        return temp;
        
    }
    
    TreeNode* invertTree(TreeNode* root) {
        return solve(root);
    }
};
