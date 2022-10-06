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
    bool fun(TreeNode* root,int targetSum){
        if(root==NULL)
            return false;
        targetSum -= root->val;
        if(targetSum == 0 && !root->left && !root->right)
            return true;
        return fun(root->left,targetSum) || fun(root->right,targetSum);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return fun(root,targetSum);
    }
};