class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n=capacity.size();
        int cnt=0;
        for(int i=0;i<n;i++)
            capacity[i]=capacity[i]-rocks[i];
        sort(capacity.begin(),capacity.end());
        for(int i=0;i<n;i++){
            if(additionalRocks<capacity[i]) 
                break;
            ++cnt;
            additionalRocks=additionalRocks-capacity[i];
        }
        return cnt;
    }
};