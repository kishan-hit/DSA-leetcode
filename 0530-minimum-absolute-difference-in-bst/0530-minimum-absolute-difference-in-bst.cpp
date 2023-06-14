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
    int prev=INT_MAX;
    int ans=INT_MAX;
    int getMinimumDifference(TreeNode* root) {
        inOrder(root);
        return ans;
    }
    void inOrder(TreeNode* root) {
        if(root->left != NULL)
            inOrder(root->left);
        ans = min(ans,abs(root->val-prev));
        prev = root->val;
        if(root->right != NULL)
            inOrder(root->right);
    }
};