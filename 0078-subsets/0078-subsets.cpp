class Solution {
public:
    void fun(int i,vector<int> v,vector<vector<int>>&vec,vector<int>&nums){
        if(i==nums.size()){
            vec.push_back(v);
            return;
        }
        fun(i+1,v,vec,nums);
        v.push_back(nums[i]);
        fun(i+1,v,vec,nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> vec;
        vector<int> v;
        fun(0,v,vec,nums);
        return vec;
    }
};