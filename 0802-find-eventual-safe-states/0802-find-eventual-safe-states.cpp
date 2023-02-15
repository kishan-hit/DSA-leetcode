class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> revGraph(n);
        vector<int> in(n);
        for(int i=0;i<n;i++){
            for(auto it:graph[i]){
                revGraph[it].push_back(i);
                in[i]++;
            }
        }
        queue<int> q;
        for(int i=0;i<n;i++)
            if(in[i]==0)
                q.push(i);
        vector<int> v;
        while(!q.empty()){
            int src = q.front();
            q.pop();
            v.push_back(src);
            for(auto it:revGraph[src]){
                in[it]--;
                if(in[it]==0)
                    q.push(it);
            }
        }
        sort(v.begin(),v.end());
        return v;
    }
};