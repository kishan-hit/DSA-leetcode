class Solution {
public:
    bool canJump(vector<int>& nums) {
        int res=0;
        for(int i=0;i<nums.size();i++){
            if(i>res)
                return false;
            res = max(res,i+nums[i]);
        }
        return true;
    }
};