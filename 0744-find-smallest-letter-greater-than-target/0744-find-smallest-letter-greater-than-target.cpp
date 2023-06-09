class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int mini=27,f=0;
        for(int i=0;i<letters.size();i++){
            if((letters[i]-'a')>(target-'a')){
                f=1;
                mini = min(mini,(letters[i]-'a'));
            }
        }
        if(f==0)
            return letters[0];
        return mini+'a';
    }
};