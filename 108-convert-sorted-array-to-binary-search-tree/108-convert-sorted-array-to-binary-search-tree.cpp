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
    TreeNode* fun(vector<int>& nums, int start, int end){
        if(end<=start) 
            return NULL; 
        int midIdx=(end+start)/2;
        TreeNode* root=new TreeNode(nums[midIdx]);
        root->left=fun(nums, start, midIdx);
        root->right=fun(nums, midIdx+1,end);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return fun(nums,0,nums.size());
    }
};