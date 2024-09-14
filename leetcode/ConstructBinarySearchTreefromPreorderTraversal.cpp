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
    //PreOrder: [8,5,1,7,10,12]
    //InOrder: [1,5,7,[8],10,12]
    //Root: [8]
    //Left: [1,5,7]
    //Right: [10,12]
    TreeNode* solve(TreeNode* root, int data) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        if(root == NULL) {
            root = new TreeNode(data);
            return root;
        }
        
        if(root->val <= data) {
            root->right = solve(root->right,data);
        } else if(root->val > data) {
            root->left = solve(root->left,data);
        }
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = NULL;
        for(int i = 0; i < (int) preorder.size(); i++) {
            root = solve(root,preorder[i]);
        }
        return root;
    }
};
