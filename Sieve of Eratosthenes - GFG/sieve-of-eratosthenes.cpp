//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    vector<int> sieveOfEratosthenes(int N)
    {
        // Write Your Code here
        vector<bool> v(N,false);
        for(int i=2;i<=N;i++){
            for(int j=i*i;j<=N;j++){
                if(j%i==0 && !v[j])
                    v[j] = true;
            }
        }
        vector<int> res;
        for(int i=2;i<=N;i++)
            if(!v[i])
                res.push_back(i);
        return res;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        Solution ob;
        vector<int> primes  = ob.sieveOfEratosthenes(N);
        for(auto prime : primes) {
            cout<< prime <<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends