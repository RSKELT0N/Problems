/*
110. Balanced Binary Tree

Given a binary tree, determine if it is height-balanced (A height-balanced binary tree is a binary tree in which the depth of the two subtrees of every node never differs by more than one).
*/

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
    bool valid = true;
    int solve(TreeNode * root)
    {
        if(root == nullptr) return 0;

        int left = solve(root->left);
        int right = solve(root->right);

        if(std::abs(left - right) > 1)
            valid = false;

        return 1 + std::max(left, right);
    }

    bool isBalanced(TreeNode * root)
    {
        if(root == nullptr)
            return true;

        solve(root);
        return valid;
    }
};
