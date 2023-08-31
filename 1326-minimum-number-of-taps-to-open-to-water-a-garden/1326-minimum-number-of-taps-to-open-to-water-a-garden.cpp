class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        for(int i=1;i<ranges.size();i++){
            if(ranges[i]==0) 
                ranges[i]=i;
            else{
                int range = max(0, i-ranges[i]);
                ranges[range] = max(i+ranges[i],ranges[range]);
            }
        }
        int maxIdx = 0;
        int pos = 0;
        int jump = 0;
        for(int i=0;i<n;i++){
            if(maxIdx<i) 
                return -1; 
            maxIdx = max(maxIdx, ranges[i]);
            if(i==pos){
                jump++;
                pos = maxIdx;
            }
        }
        return maxIdx>=n ? jump : -1;
    }
};