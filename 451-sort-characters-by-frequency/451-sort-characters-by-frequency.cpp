class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        priority_queue<pair<int,char>> pq;
        for(auto it:s)
            mp[it]++;
        for(auto it:mp)
            pq.push({it.second,it.first});
        string st;
        while(pq.size()){
            auto it = pq.top();
            for(int i=0;i<it.first;i++)
                st += it.second;
            pq.pop();
        }
        return st;
    }
};