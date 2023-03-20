class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int cnt=0,size=flowerbed.size(),prev,next;
        for(int i=0;i<size;i++){
            if(flowerbed[i]==0){
                prev = (i==0 || flowerbed[i-1]==0) ? 0 : 1;
                next = (i==size-1 || flowerbed[i+1]==0) ? 0 : 1;
                if(prev==0 && next==0){
                    flowerbed[i] = 1;
                    ++cnt;
                }
            }
        }
        return cnt>=n;
    }
};