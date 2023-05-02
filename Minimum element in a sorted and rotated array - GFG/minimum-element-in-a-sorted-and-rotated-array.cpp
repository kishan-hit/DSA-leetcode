//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int findMin(int nums[], int n){
        //complete the function here
        int l=0,r=n-1;
         while(l<=r){
            if(nums[l]<nums[r])
                return nums[l];
            int mid = l + (r-l)/2;
            int next = (mid+1)%n;
            int prev = (mid-1+n)%n;
            if(nums[mid]<=nums[prev] && nums[mid]<=nums[next])
                return nums[mid];
            if(nums[mid]>=nums[l])
                l = mid + 1;
            else
                r = mid - 1;
        }
        return 0;
    }
};

//{ Driver Code Starts.


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution ob;
		cout<<ob.findMin(a, n)<<endl;
	}
	return 0;
}
// } Driver Code Ends