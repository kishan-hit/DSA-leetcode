class Solution {
public:
    int maxDivScore(vector<int>& nums, vector<int>& divisors) {
        int maxi=0,mini=INT_MAX;
        for(int i=0;i<divisors.size();i++){
            int cnt=0;
            for(int j=0;j<nums.size();j++){
                if(nums[j]%divisors[i] ==0)
                    ++cnt;
            }
            if(cnt==maxi){
                maxi = cnt;
                mini = min(mini,divisors[i]);
            }
            else if(cnt>maxi){
                maxi = cnt;
                mini = divisors[i];
            }
        }
        return mini;
    }
};