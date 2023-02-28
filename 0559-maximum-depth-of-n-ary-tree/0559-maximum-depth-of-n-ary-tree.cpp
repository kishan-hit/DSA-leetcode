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
    int maxDepth(Node* root) {
        if(root==NULL)
            return 0;
        queue<Node*> q;
        int res=0;
        q.push(root);
        while(!q.empty()){
            ++res;
            int n = q.size();
            for(int i=0;i<n;i++){
                auto it = q.front();
                q.pop();
                for(auto i:it->children){
                    if(i)
                        q.push(i);
                }
            }
        }
        return res;
    }
};