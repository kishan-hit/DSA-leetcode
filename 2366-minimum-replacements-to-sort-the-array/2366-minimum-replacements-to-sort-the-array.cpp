class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        int n=nums.size(),right=nums[n-1];
        long long res=0,temp;
        if(n==1)
            return 0;
        for(int i=n-2;i>=0;i--){
            if(right>=nums[i])
                right = nums[i];
            else{
                temp = ((nums[i]-1)/right)+1;
                right = nums[i]/temp;
                res +=(temp-1);
            }       
        }
        return res;   
    }
};