class Solution {
public:
    class UnionFind{
        public:
            vector<int> parent;
            vector<int> rank;
            int cnt=0;
            UnionFind(int n){
                cnt = n;
                rank.resize(n+1);
                for(int i=0;i<=n;i++){    
                    parent.push_back(i);
                    rank[i] = 0;
                }
            }
            int find(int x){
                if(parent[x]==x) 
                    return x;
                return parent[x] = find(parent[x]);   
            }
            bool Union(int x,int y){
                int X = find(x);
                int Y = find(y);
                if(X==Y) 
                    return true;   
                if(rank[X]<rank[Y])
                    swap(X,Y);
                parent[Y] = X;
                if(rank[X]==rank[Y])
                    rank[X]++;
                cnt--;
                return false;
            }
            int getCount(){
                return cnt;
            }
    };
    int findMST(int n,vector<vector<int>>&edges,int ex,int in){
        UnionFind uf(n);
        priority_queue< vector<int>,vector<vector<int>>,greater<vector<int>>> minpq; 
        int ans = 0,edges_count = 0;
        for(int i=0;i<edges.size();i++){
            if(i==ex){
                continue;
            }
            if(i==in){
                ans+=edges[i][2];
                edges_count++;
                uf.Union(edges[i][0],edges[i][1]);
                continue;
            }
            minpq.push({edges[i][2],edges[i][0],edges[i][1]});
        }
        while(minpq.size()>0){  
            if(edges_count==(n-1)){
                break;
            }     
            auto topa = minpq.top();
            minpq.pop();
            if(!uf.Union(topa[1], topa[2])){
                ans  = ans + topa[0];
                edges_count++;
            }
        }
        if(uf.getCount()!=1){  
            return INT_MAX;
        }
        return ans;   
    }
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        int mst = findMST(n,edges,-1,-1);
        vector<int>critical = {};
        for(int i=0;i<edges.size();i++){
            int newmst = findMST(n,edges,i,-1);
            if(newmst>mst){
                critical.push_back(i);
            }
        }
        vector<int>pseudocritical = {};
        for(int i = 0;i<edges.size();i++){
            if(find(critical.begin(),critical.end(),i)!=critical.end()) 
                continue;
            int newmst = findMST(n,edges,-1,i);
            if(newmst==mst){
                pseudocritical.push_back(i);
            }
        }
        return {critical,pseudocritical};
    }
};