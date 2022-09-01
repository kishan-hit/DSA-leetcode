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
    int cnt=0;
    void dfs(TreeNode* root,int maxi){
        if(root){
            if(root->val>=maxi)
                ++cnt;
            dfs(root->left,max(root->val,maxi));
            dfs(root->right,max(root->val,maxi));
        }
    }
    int goodNodes(TreeNode* root) {
         dfs(root,INT_MIN);
        return cnt;
    }
};