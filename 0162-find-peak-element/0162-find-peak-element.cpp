class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int maxi = *max_element(nums.begin(),nums.end());
        int ind;
        for(int i=0;i<nums.size();i++)
            if(nums[i]==maxi){
                ind = i;
                break;
            }
        return ind;
    }
};