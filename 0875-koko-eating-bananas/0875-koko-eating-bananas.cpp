class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1,high = INT_MIN;
        for(auto it:piles)
            high = max(it,high); 
        while(low<high){
            int mid = (low+high)/2,val = 0;
            for(auto it:piles) 
                val += (it+mid-1)/mid; 
            if(val<=h) 
                high = mid; 
            else low = mid+1; 
        }
        return low;
    }
};