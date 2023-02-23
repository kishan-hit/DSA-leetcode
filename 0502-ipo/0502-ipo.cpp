class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<int> pq;
        vector<pair<int,int>> v;
        for(int i=0;i<profits.size();i++){
            v.push_back({capital[i],profits[i]});
        }
        sort(v.begin(),v.end());
        if(k>v.size())
            k = v.size();
        int j=0;
        while(k--){
            for(int i=j;i<v.size();i++){
                if(w>=v[i].first){
                    pq.push(v[i].second);
                    ++j;
                }
                else
                    break;
            }
            if(!pq.empty()){
                w += pq.top();
                pq.pop();
            }
        }
        return w;
    }
};