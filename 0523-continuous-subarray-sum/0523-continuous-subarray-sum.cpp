class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int sum=0;
        unordered_map<int,int> m;
        m[0] = -1;
        for(int i=0;i<nums.size();i++){
            sum = (sum + nums[i])%k;
            if(m.find(sum)!=m.end()){
                if(i-m[sum]>=2)
                    return true;
            }
            else
                m[sum] = i;
        }
        return false;
    }
};