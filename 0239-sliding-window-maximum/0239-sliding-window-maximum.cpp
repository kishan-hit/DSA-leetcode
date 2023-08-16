class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> v;
        deque<int> q;
        int n=nums.size();
        int i=0,j=0;
        while(j<n){
            while(!q.empty() && nums[j]>q.back())
                q.pop_back();
            q.push_back(nums[j]);
            if((j-i+1)==k){
                v.push_back(q.front());
                if(nums[i]==q.front())
                    q.pop_front();
                ++i;
            }
            ++j;
        }
        return v;
    }
};