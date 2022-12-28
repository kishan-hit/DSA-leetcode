class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;
        for(auto it:piles)
            pq.push(it);
        while(k){
            int temp = pq.top();
            pq.pop();
            pq.push(temp-temp/2);
            --k;
        }
        long long sum = 0;
        while(!pq.empty()){
            sum += (long long)pq.top();
            pq.pop();
        }
        return (int)sum;
    }
};