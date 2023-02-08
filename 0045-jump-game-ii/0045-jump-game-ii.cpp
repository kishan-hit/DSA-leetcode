class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size(),maxi=0,curr=0,jump=0;
        for(int i=0;i<n-1;i++){
            maxi = max(maxi,i+nums[i]);
            if(i==curr){
                ++jump;
                curr = maxi;
            }
        }
        return jump;
    }
};