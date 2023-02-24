class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int mini = INT_MAX;
        priority_queue<int> pq;
        for(auto it:nums){
            if(it&1)
                it *= 2;
            pq.push(it);
            mini = min(mini,it);
        }
        int res=INT_MAX;
        while(true){
            int num = pq.top();
            pq.pop();
            res = min(res,(num-mini));
            if(num&1)
                break;
            pq.push(num/2);
            mini = min(mini,num/2);
        }
        return res;
    }
};