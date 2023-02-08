//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int characterReplacement(string S, int K) {
        // code here
        int i=0,j=0,maxi=0,res=0;
        unordered_map<char,int> mp;
        while(j<S.length()){
            mp[S[j]]++;
            maxi = max(maxi,mp[S[j]]);
            while((j-i+1)-maxi > K){
                mp[S[i]]--;
                if(mp[S[i]]==0)
                    mp.erase(S[i]);
                ++i;
            }
            res = max(res,(j-i+1));
            ++j;
        }
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        int K;
        cin >> K;

        Solution obj;
        cout << obj.characterReplacement(S, K) << endl;
    }
    return 0;
}
// } Driver Code Ends