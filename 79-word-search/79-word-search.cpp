class Solution {
public:
    bool fun(int i,int j,vector<vector<char>>&board,string word,int k){
        if(k==word.length())
            return true;
        if(i<0 || i>=board.size() || j<0 || j>=board[0].size() || board[i][j]!=word[k])
            return false;
        board[i][j] = '0';
        bool res = (fun(i+1,j,board,word,k+1) || fun(i-1,j,board,word,k+1) ||
                   fun(i,j+1,board,word,k+1) || fun(i,j-1,board,word,k+1));
        board[i][j] = word[k];
        return res;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(),m = board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0] && fun(i,j,board,word,0))
                    return true;
            }
        }
        return false;
    }
};