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
    void dfs(TreeNode* root,int dis,int level,map<int,multiset<pair<int,int>>>&m){
        if(root==NULL)
            return;
        if(root->left)
            dfs(root->left,dis-1,level+1,m);
        m[dis].insert({level,root->val});
        if(root->right)
            dfs(root->right,dis+1,level+1,m);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,multiset<pair<int,int>>> m;
        vector<vector<int>> vec;
        dfs(root,0,0,m);
        for(auto it1:m){
            vector<int> v;
            for(auto it2:it1.second){
                v.push_back(it2.second);
            }
            vec.push_back(v);
        }
        return vec;
    }
};