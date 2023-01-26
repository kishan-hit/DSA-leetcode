class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> v(n,1e9);
        v[src] = 0;
        for(int i=0;i<=k;i++){
            vector<int> vec(v);
            for(auto e:flights)
                vec[e[1]] = min(vec[e[1]],v[e[0]]+e[2]);
            v = vec;
        }
        return v[dst] == 1e9 ? -1 : v[dst];
    }
};