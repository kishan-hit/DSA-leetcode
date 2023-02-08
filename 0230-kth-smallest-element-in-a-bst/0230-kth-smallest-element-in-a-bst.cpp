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
    int res;
    void fun(TreeNode* root,int &k){
        stack<TreeNode*> st;
        while(true){
            if(root){
                st.push(root);
                root = root->left;
            }
            else{
                if(st.empty())
                    break;
                root = st.top();
                st.pop();
                --k;
                if(k==0){
                    res = root->val;
                    return;
                }
                root = root->right;
            }
        }
    }
    int kthSmallest(TreeNode* root, int k) {
        fun(root,k);
        return res;
    }
};