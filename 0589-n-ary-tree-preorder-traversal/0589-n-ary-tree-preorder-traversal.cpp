/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> preorder(Node* root) {
        if(!root)
            return {};
        vector<int> v;
        stack<Node*> st;
        st.push(root);
        while(!st.empty()){
            auto node = st.top();
            st.pop();
            v.push_back(node->val);
            stack<Node*> temp;
            for(auto it:node->children)
                temp.push(it);
            while(!temp.empty()){
                st.push(temp.top());
                temp.pop();
            }
        }
        return v;
    }
};