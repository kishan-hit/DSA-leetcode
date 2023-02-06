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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> vec;
        if(!root)
            return vec;
        queue<TreeNode*> q;
        int f=1;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            vector<int> v(n);
            for(int i=0;i<n;i++){
                auto it = q.front();
                q.pop();
                int ind = f==1?i:(n-i-1);
                v[ind] = it->val;
                if(it->left)
                    q.push(it->left);
                if(it->right)
                    q.push(it->right);
            }
            vec.push_back(v);
            f = !f;
        }
        return vec;
    }
};