class SmallestInfiniteSet {
public:
    map<int,int> mp;
    int cnt=0;
    SmallestInfiniteSet() {
        
    }
    
    int popSmallest() {
        if(mp.empty()){
            cnt += 1;
            return cnt;
        }
        int temp = mp.begin()->first;
        mp.erase(temp);
        return temp;
    }
    
    void addBack(int num) {
        if(cnt>=num)
            mp[num]++;
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */