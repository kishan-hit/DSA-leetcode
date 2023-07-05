class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int i=0,j=0,maxi=0,nz=0;
        while(j<nums.size()){
            if(nums[j]==0)
                ++nz;
            while(nz>1){
                if(nums[i]==0)
                    --nz;
                ++i;
            }
            maxi = max(maxi,(j-i));
            ++j;
        }
        return maxi;
    }
};