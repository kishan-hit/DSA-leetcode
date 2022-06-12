class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int,int> m;
        int i=0,j=0;
        int sum=0,maxi=0;
        while(j<nums.size()){
            m[nums[j]]++;
            sum += nums[j];
            while(m[nums[j]]>1){
                m[nums[i]]--;
                sum -= nums[i];
                if(m[nums[i]]==0)
                    m.erase(nums[i]);
                ++i;
            }
            maxi = max(maxi,sum);
            ++j;
        }
        return maxi;
    }
};