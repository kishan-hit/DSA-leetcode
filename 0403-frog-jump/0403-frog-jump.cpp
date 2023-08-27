class Solution {
public:
    unordered_map<int,int> mp;
    unordered_map<string,int> memo;
    bool fun(int i,int step,int n,vector<int>&v){
        if(mp.find(v[i]+step)==mp.end() || step<=0)
            return false;
        i = mp[v[i]+step];
        string curr = to_string(i) + ';' + to_string(step);
		if(memo.find(curr) != memo.end())
			return memo[curr];
        if(i==(n-1))
            return true;
        bool prev = fun(i,step-1,n,v);
        bool cur = fun(i,step,n,v);
        bool next = fun(i,step+1,n,v);
        memo[curr] = prev || cur || next;
        return memo[curr];    
    }
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        for(int i=0;i<n;i++)
            mp[stones[i]] = i;
        return fun(0,1,n,stones);
    }
};