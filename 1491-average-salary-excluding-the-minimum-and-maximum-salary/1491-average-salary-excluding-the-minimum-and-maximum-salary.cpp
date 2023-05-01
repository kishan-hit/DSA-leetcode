class Solution {
public:
    double average(vector<int>& salary) {
        sort(salary.begin(),salary.end());
        int n = salary.size();
        double sum=0.0;
        for(int i=1;i<=n-2;i++)
            sum += salary[i];
        return (double)(sum*1.0)/(n-2);
    }
};