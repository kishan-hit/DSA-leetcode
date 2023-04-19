class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        unordered_map<int,int> mp;
        for(auto it:nums1)
            mp[it]++;
        for(auto it:nums2)
            if(mp.find(it)!=mp.end())
                return it;
        int t1 = nums1[0];
        int t2 = nums2[0];
        int num1 = t1*10 + t2;
        int num2 = t2*10 + t1;
        return min(num1,num2);
    }
};