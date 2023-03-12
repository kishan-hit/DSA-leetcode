//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int sumSubarrayMins(int N, vector<int> &arr) {
        // code here
        stack<pair<int,int>> st;
        vector<int> left(N),right(N);
        for(int i=0;i<N;i++){
            int cnt=1;
            while(!st.empty() && arr[i]<=st.top().first){
                cnt += st.top().second;
                st.pop();
            }
            st.push({arr[i],cnt});
            left[i] = cnt;
        }
        while(!st.empty())
            st.pop();
        for(int i=N-1;i>=0;i--){
            int cnt=1;
            while(!st.empty() && arr[i]<st.top().first){
                cnt += st.top().second;
                st.pop();
            }
            st.push({arr[i],cnt});
            right[i] = cnt;
        }
        int mod = 1e9+7;
        int sum=0;
        for(int i=0;i<N;i++){
            sum = sum%mod + (((arr[i]%mod*left[i]%mod)%mod)*right[i]%mod)%mod;
        }
        return sum;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> arr(N);
        for (int i = 0; i < N; i++) cin >> arr[i];

        Solution obj;
        cout << obj.sumSubarrayMins(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends