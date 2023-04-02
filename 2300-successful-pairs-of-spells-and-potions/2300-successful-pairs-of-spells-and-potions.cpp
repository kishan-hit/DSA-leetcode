class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> v;
        sort(potions.begin(),potions.end());
        for(int i=0;i<spells.size();i++){
            long long temp = ceil((success*1.0)/spells[i]);
            int ind = lower_bound(potions.begin(),potions.end(),temp) - potions.begin();
            v.push_back(potions.size() - ind);
        }
        return v;
    }
};