//{ Driver Code Starts

#include <bits/stdc++.h>

using namespace std;

pair<int, int> getFloorAndCeil(int arr[], int n, int x);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        auto ans = getFloorAndCeil(arr, n, x);
        cout << ans.first << " " << ans.second << "\n";
    }
    return 0;
}

// } Driver Code Ends


pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
    // code here
    pair<int,int>p1;
    int floor1=-1;
    int ceil1=INT_MAX;
    for(int i=0;i<n;i++){
        if(arr[i]>floor1 && arr[i]<=x){
            floor1=arr[i];
        }
        if(arr[i]<ceil1 && arr[i]>=x){
            ceil1=arr[i];
        }
    }
    if(ceil1==INT_MAX){
        ceil1=-1;
    }
    p1.first=floor1;
    p1.second=ceil1;
    return p1;
}