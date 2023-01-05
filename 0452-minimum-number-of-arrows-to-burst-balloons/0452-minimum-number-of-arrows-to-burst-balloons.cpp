class Solution {
public:
    static bool comp(vector<int>&a,vector<int>&b){
        return a[1]<b[1];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        int cnt=1;
        sort(points.begin(),points.end(),comp);
        int i=0,j=1;
        while(j<points.size()){
            if(points[i][1]<points[j][0]){
                ++cnt;
                i=j;
            }
            ++j;
        }
        return cnt;
    }
};