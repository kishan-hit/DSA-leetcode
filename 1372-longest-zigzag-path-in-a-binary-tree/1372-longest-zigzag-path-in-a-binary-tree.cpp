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
    int longestZigZag(TreeNode* root) {
        if(!root)
            return 0;
        queue<pair<pair<TreeNode*,char>,int>> q;
        if(root->left)
            q.push({{root->left,'l'},1});
        if(root->right)
            q.push({{root->right,'r'},1});
        int res=0;
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            TreeNode* node = it.first.first;
            char ch = it.first.second;
            int len = it.second;
            res = max(res,len);
            if(node->left){
                if(ch=='l')
                    q.push({{node->left,'l'},1});
                else
                    q.push({{node->left,'l'},len+1});
            }
            if(node->right){
                if(ch=='r')
                    q.push({{node->right,'r'},1});
                else
                    q.push({{node->right,'r'},len+1});
            }
        }
        return res;
    }
};