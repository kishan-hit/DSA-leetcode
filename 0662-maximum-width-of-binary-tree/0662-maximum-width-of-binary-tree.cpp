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
    int widthOfBinaryTree(TreeNode* root) {
        long long res=0;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        while(!q.empty()){
            int n = q.size();
            int mini = q.front().second;
            long long f_ind,l_ind;
            for(int i=0;i<n;i++){
                long long cur_ind = q.front().second - mini;
                auto it = q.front().first;
                q.pop();
                if(i==0)    
                    f_ind = cur_ind;
                if(i==n-1)
                    l_ind = cur_ind;
                if(it->left)
                    q.push({it->left,(long long)(2*cur_ind+1)});
                if(it->right)
                    q.push({it->right,(long long)(2*cur_ind+2)});
            }
            res = max(res,(l_ind-f_ind+1));
        }
        return res;
    }
};