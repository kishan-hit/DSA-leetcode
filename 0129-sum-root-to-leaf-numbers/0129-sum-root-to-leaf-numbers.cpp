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
    int sum;
    int sumNumbers(TreeNode *root) {
        if(!root)
            return 0;
        sum=0;
        dfs(root, 0);
        return sum;
    }
    void dfs(TreeNode *&node,int currentSum){
        currentSum=currentSum*10+node->val;
        if(!node->left && !node->right)
            sum+=currentSum;
        if(node->left)
            dfs(node->left,currentSum);
        if(node->right)
            dfs(node->right,currentSum);
    }
};