class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;
        long long sum = 0;
        for(auto it:piles){
            pq.push(it);
            sum += it;
        }
        while(k){
            int temp = pq.top();
            pq.pop();
            sum -= temp;
            pq.push(temp-temp/2);
            sum += (temp-temp/2);
            --k;
        }
        return (int)sum;
    }
};