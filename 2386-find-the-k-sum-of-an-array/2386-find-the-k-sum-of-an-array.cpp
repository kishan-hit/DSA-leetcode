class Solution {
public:
    long long kSum(vector<int>& nums, int k) {
        long long sum=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0)
                sum += nums[i];
            nums[i] = abs(nums[i]);
        }
        sort(nums.begin(),nums.end());
        priority_queue<pair<long long,int>> pq;
        pq.push({sum-nums[0],0});
        long long temp=sum;
        while(--k){
            temp = pq.top().first;
            int i = pq.top().second;
            pq.pop();
            if(i<nums.size()-1){
                pq.push({temp+nums[i]-nums[i+1],i+1});
                pq.push({temp-nums[i+1],i+1});
            }
        }
        return temp;
    }
};