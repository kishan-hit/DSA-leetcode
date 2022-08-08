class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n1=s1.length(),n2=s2.length(),n3=s3.length();
        if(n3!=(n1+n2))
            return false;
        vector<int> prev(n2+1),cur(n2+1);
        for(int i=n1;i>=0;i--){
            for(int j=n2;j>=0;j--){
                int k=i+j;
                if(i==n1 && j==n2)
                    cur[j] = 1;
                else if(s1[i]==s3[k] && s2[j]==s3[k])
                    cur[j] = prev[j] || cur[j+1];
                else if(s1[i]==s3[k])
                    cur[j] = prev[j];
                else if(s2[j]==s3[k])
                    cur[j] = cur[j+1];
                else
                    cur[j] = 0;
            }
            prev = cur;
        }
        return cur[0];
    }
};