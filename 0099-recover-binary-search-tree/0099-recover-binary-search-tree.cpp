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
    TreeNode *first,*middle,*last,*prev;
    void inOrder(TreeNode* root){
        if(!root)
            return;
        inOrder(root->left);
        if(prev && (prev->val > root->val)){
            if(!first){
                first = prev;
                middle = root;
            }
            else
                last = root;
        }
        prev = root;
        inOrder(root->right);
    }
    void recoverTree(TreeNode* root) {
        first = middle = last = NULL;
        prev = new TreeNode(INT_MIN);
        inOrder(root);
        if(last)
            swap(first->val,last->val);
        else
            swap(first->val,middle->val);
    }
};