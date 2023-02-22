class Solution {
public:
    int findDays(vector<int>&weights,int cap){
        int n = weights.size();
        int i=0,days=1,sum=0;
        while(i<n){
            while(i<n && (sum+weights[i])<=cap){
                sum += weights[i];
                ++i;
            }
            if(i==n)
                break;
            if(i<n){
                ++days;
                sum=0;
            }
        }
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int lo=INT_MIN,hi=0,res=INT_MAX;
        for(auto it:weights){
            hi += it;
            lo = max(lo,it);
        }
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            int temp = findDays(weights,mid);
            if(temp<=days){
                res = min(res,mid);
                hi = mid-1;
            }
            else
                lo = mid + 1;
        }
        return res;
    }
};