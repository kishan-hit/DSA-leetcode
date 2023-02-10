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
class BSTIterator{
public:
    stack<TreeNode*> st;
    bool reverse = true;
    void pushAll(TreeNode* root){
        while(root){
            st.push(root);
            if(reverse)
                root = root->right;
            else
                root = root->left;
        }
    }
    BSTIterator(TreeNode* root,bool isReverse){
        reverse = isReverse;
        pushAll(root);
    }
    int next(){
        TreeNode* temp = st.top();
        st.pop();
        if(reverse)
            pushAll(temp->left);
        else
            pushAll(temp->right);
        return temp->val;
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root)
            return false;
        BSTIterator l(root,false);
        BSTIterator r(root,true);
        int i = l.next(),j = r.next();
        while(i<j){
            if((i+j)==k)
                return true;
            else if((i+j)<k)
                i = l.next();
            else
                j = r.next();
        }
        return false;
    }
};