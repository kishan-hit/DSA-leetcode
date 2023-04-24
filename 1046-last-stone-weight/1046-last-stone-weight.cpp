class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(auto it:stones)
            pq.push(it);
        while(true){
            if(pq.size()==1 || pq.size()==0)
                break;
            int t1 = pq.top();
            pq.pop();
            int t2 = pq.top();
            pq.pop();
            if(t1!=t2)
                pq.push(abs(t1-t2));
        }
        if(pq.empty())
            return 0;
        return pq.top();
    }
};