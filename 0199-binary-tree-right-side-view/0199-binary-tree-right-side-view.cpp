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
    vector<int> rightSideView(TreeNode* root) {
        if(!root)
            return {};
        queue<pair<TreeNode*,int>> q;
        map<int,int> mp;
        q.push({root,0});
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            mp[it.second] = it.first->val;
            if(it.first->left)
                q.push({it.first->left,it.second+1});
            if(it.first->right)
                q.push({it.first->right,it.second+1});
        }
        vector<int> v;
        for(auto it:mp)
            v.push_back(it.second);
        return v;
    }
};