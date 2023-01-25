class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
            int n=edges.size();
            vector<int> adj[n];
            for(int i=0;i<edges.size();i++){
                if(edges[i]!=-1){
                    adj[i].push_back(edges[i]);
                }
            }
            int temp = 1e9;
            vector<int> v1(n,temp),v2(n,temp);
            queue<int> q;
            q.push(node1);
            v1[node1]=0;
            while(!q.empty()){
                int nq=q.size();
                for(int i=0;i<nq;i++){
                    auto it=q.front();
                    q.pop();
                    for(auto itr:adj[it]){
                        if(v1[itr]==1e9){
                            v1[itr]=v1[it]+1;
                            q.push(itr);
                        }
                    }
                }
            }
            q.push(node2);
            v2[node2]=0;
            while(!q.empty()){
                int nq=q.size();
                for(int i=0;i<nq;i++){
                    auto it=q.front();
                    q.pop();
                    for(auto itr:adj[it]){
                        if(v2[itr]==1e9){
                            v2[itr]=v2[it]+1;
                            q.push(itr);
                        }
                    }
                }
            }
            int maxi=INT_MAX;
            int res=-1;
            for(int i=0;i<n;i++){
                if(v1[i]!=1e9&&v2[i]!=1e9){
                    int max1=max(v1[i],v2[i]);
                    if(maxi>max1){
                        maxi=max1;
                        res=i;
                    }
                }
            }
        return res;
    }
};