class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        int sum=0,res=0;
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            int rem = sum%k;
            if(rem<0)
                rem += k;
            if(rem==0)
                ++res;
            if(m.find(rem)!=m.end())
                res += m[rem];
            ++m[rem];
        }
        return res;
    }
};