class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i=0,j=0,mini=INT_MAX;
        while(j<nums.size()){
            target -= nums[j];
            while(target==0){
                mini = min(mini,(j-i+1));
                target += nums[i];
                ++i;
            }
            while(target<0){
                mini = min(mini,(j-i+1));
                target += nums[i];
                ++i;
                if(target==0)
                    mini = min(mini,(j-i+1));
            }
            ++j;
        }
        if(mini==INT_MAX)
            return 0;
        return mini;
    }
};