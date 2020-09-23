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
    vector<int> values;
    void solve(TreeNode* root) {
        values.push_back(root->val);
        if(root->left)
            solve(root->left);
        if(root->right)
            solve(root->right);
    }
    void sort(vector<int> &values) {
        int r = 1;
        while (r > 0) {
            r = 0;
            for (int i = 0; i < values.size() - 1; i++)
            if (values[i] > values[i + 1]) {
                swap(values[i], values[i + 1]);
                r++;
            }
        }
    }
    int kthSmallest(TreeNode* root, int k) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        solve(root);
        sort(values);
        for(auto a : values)
            cout << a << " " << endl;
        return values[k-1];
    }
};
