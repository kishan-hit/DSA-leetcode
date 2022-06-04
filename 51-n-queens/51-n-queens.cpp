class Solution {
public:
    bool isValid(int i,int j,vector<string>&v,int n){
        int temp1=i;
        int temp2=j;
        while(i>=0 && j>=0){
            if(v[i][j]=='Q')
                return false;
            i--;
            j--;
        }
        i = temp1;
        j = temp2;
        while(j>=0){
            if(v[i][j]=='Q')
                return false;
            --j;
        }
        i = temp1;
        j = temp2;
        while(i<n && j>=0){
            if(v[i][j]=='Q')
                return false;
            ++i;
            --j;
        }
        return true;
    }
    void fun(int i,int n,vector<string>&v,vector<vector<string>>&vec){
        if(i==n){
            vec.push_back(v);
            return;
        }
        for(int j=0;j<n;j++){
            if(isValid(j,i,v,n)){
                v[j][i] = 'Q';
                fun(i+1,n,v,vec);
                v[j][i] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> vec;
        vector<string> v(n);
        string s(n,'.');
        for(int i=0;i<n;i++)
            v[i] = s;
        fun(0,n,v,vec);
        return vec;
    }
};