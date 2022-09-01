class Solution {
public:
    static bool comp(vector<int> &a,vector<int> &b) {
	    return a[1]<b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),comp);
        int cnt=0;
        vector<int> v = intervals[0];
        for(int i=1;i<intervals.size();i++){
            if(v[1]>intervals[i][0])
                ++cnt;
            else
                v = intervals[i];
        }
        return cnt;
    }
};