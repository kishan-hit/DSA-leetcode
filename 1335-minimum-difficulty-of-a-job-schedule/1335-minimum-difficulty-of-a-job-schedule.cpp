class Solution {
public:
    int fun(vector<int>& jobDifficulty,int d,int i,vector<vector<int>>&dp){
        if(d==1){
            int maxi = jobDifficulty[i];
            for(int j=i;j<jobDifficulty.size();j++)
                maxi = max(maxi,jobDifficulty[j]);
            return maxi;
        }
        if(dp[d][i]!=-1)
            return dp[d][i];
        int maxi = INT_MIN;
        int mini = INT_MAX;
        for(int j=i;j<=(jobDifficulty.size()-d);j++){
            maxi = max(maxi,jobDifficulty[j]);
            mini = min(mini,maxi+fun(jobDifficulty,d-1,j+1,dp));
        }
        dp[d][i] = mini;
        return dp[d][i];
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        if(d>jobDifficulty.size())
            return -1;
        int sum=0;
        if(d==jobDifficulty.size()){
            for(auto it:jobDifficulty)
                sum += it;
            return sum;
        }
        vector<vector<int>> dp(d+1,vector<int>(jobDifficulty.size(),-1));
        return fun(jobDifficulty,d,0,dp);
    }
};