class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        int i=1,sum=n;
        while(i<n){
            if(ratings[i]==ratings[i-1]){
                ++i;
                continue;
            }
            int up=0;
            while(i<n && ratings[i]>ratings[i-1]){
                ++up;
                sum += up;
                ++i;
            }
            int down=0;
            while(i<n && ratings[i]<ratings[i-1]){
                ++down;
                sum += down;
                ++i;
            }
            sum -= min(up,down);
        }
        return sum;
    }
};