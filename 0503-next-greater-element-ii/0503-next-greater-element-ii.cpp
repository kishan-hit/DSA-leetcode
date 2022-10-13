class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> v(n,-1);
        stack<int> s;
        for(int i=0;i<2*n;i++){
            int j=i%n;
            while(!s.empty() && nums[s.top()]<nums[j]){
                v[s.top()] = nums[j];
                s.pop();
            }
            s.push(j);
        }
        return v;
    }
};