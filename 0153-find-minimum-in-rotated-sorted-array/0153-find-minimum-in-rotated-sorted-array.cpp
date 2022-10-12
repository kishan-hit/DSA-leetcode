class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0,r=nums.size()-1;
        while(l<=r){
            if(nums[l]<nums[r])
                return nums[l];
            int mid = l + (r-l)/2;
            int next = (mid+1)%nums.size();
            int prev = (mid-1+nums.size())%nums.size();
            if(nums[mid]<=nums[prev] && nums[mid]<=nums[next])
                return nums[mid];
            if(nums[mid]>=nums[l])
                l = mid + 1;
            else
                r = mid - 1;
        }
        return 0;
    }
};