class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int i=0,j=0,maxi=INT_MIN,sum=0;
        unordered_map<int,int> m;
        while(j<nums.size()){
            m[nums[j]]++;
            sum += nums[j];
            if(m.size()<j-i+1){
                while(m.size()<j-i+1){
                    m[nums[i]]--;
                    sum -= nums[i];
                    if(m[nums[i]]==0)
                        m.erase(nums[i]);
                    i++;
                }
            }
            maxi = max(maxi,sum);
            ++j;
        }
        return maxi;
    }
};