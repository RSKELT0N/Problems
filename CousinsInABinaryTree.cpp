#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

};

//This code is only for viewing, doesnt actually produce proper output as TreeNode struct hasn't been implemented

int depthX = INT_MAX;
int parentX;
int depthY = INT_MAX;
int parentY;
void solve(TreeNode* root, int x,int y, int depth, int parent) {
    if(root->val == x) {
        depthX = depth;
        parentX = parent;
    }
    if(root->val == y) {
        depthY = depth;
        parentY = parent;
    }

    if(depthX != INT_MAX && depthY != INT_MAX)
        return;

    if(root->left) {
        solve(root->left,x,y,depth+1,root->val);
    }
    if(root->right) {
        solve(root->right, x, y, depth + 1, root->val);
    }
}

bool isCousins(TreeNode* root, int x, int y) {
    solve(root,x,y,0,0);
    if (parentX != parentY && depthX == depthY)
        return true;
    else
        return false;
}

int main() {
    int i;
    string res = "10";
    i = stoi(res);
    cout << i;
    return 0;
}
