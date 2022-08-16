class Solution {
public:
    int addDigits(int num) {
        while(true){
            int sum = 0;
            while(num){
                sum += num%10;
                num /= 10;
            }
            if(sum>=10)
                num = sum;
            else{
                num = sum;
                break;
            }
        }
        return num;
    }
};