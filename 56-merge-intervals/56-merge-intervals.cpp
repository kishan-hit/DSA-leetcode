class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> v;
        vector<int> vec;
        vec = intervals[0];
        int i=1;
        while(i<n){
            if(intervals[i][0]>vec[1]){
                v.push_back(vec);
                vec = intervals[i];
            }
            else{
                vec[0] = min(vec[0],intervals[i][0]);
                vec[1] = max(vec[1],intervals[i][1]);
            }
            ++i;
        }
         v.push_back(vec);
        return v;
    }
};