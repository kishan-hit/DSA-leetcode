class Solution {
public:
    int addDigits(int num) {
        while(true){
            int sum = 0;
            while(num){
                sum += num%10;
                num /= 10;
            }
            num = sum;
            if(num>=0 && num<=9)
                break;
        }
        return num;
    }
};