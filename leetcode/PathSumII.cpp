/*
113. Path Sum II

Given the root of a binary tree and an integer targetSum, return all root-to-leaf paths where the sum of the node values in the path equals targetSum. Each path should be returned as a list of the node values, not node references.
A root-to-leaf path is a path starting from the root and ending at any leaf node. A leaf is a node with no children.
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
    std::vector<std::vector<int>> res = {};
    void solve(TreeNode * root, int s, int targetSum, std::vector<int> path)
    {
        if(root == nullptr)
            return;

        path.emplace_back(root->val);
        
        if(s + root->val == targetSum && root->left == nullptr && root->right == nullptr)
        {
            res.push_back(path);
            return;
        }

        solve(root->left, s + root->val, targetSum, path);
        solve(root->right, s + root->val, targetSum, path);
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum)
    {
        solve(root, 0, targetSum, {});
        return res;
    }
};
