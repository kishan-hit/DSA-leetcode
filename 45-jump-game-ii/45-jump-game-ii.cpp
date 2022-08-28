class Solution {
public:
    int jump(vector<int>& nums) {
        int maxi=0,cnt=0,cur=0;
        for(int i=0;i<nums.size()-1;i++){
            maxi = max(maxi,(i+nums[i]));
            if(i==cur){
                ++cnt;
                cur = maxi;
            }
        }
        return cnt;
    }
};