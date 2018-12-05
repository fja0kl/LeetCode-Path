/**
自己写的时候,很挣扎;过程很烦,因为是26进制:0-25,但问题中却是1-26;
所以,在每次计算之前,都减一,变成0-25;
这样就和之前的进制转换一毛一样了!

真厉害
**/
class Solution {
public:
    string convertToTitle(int n) {
        string res = "";
        char c;
        while(n){
            n -= 1;
            c = 'A' + n % 26;
            res = c + res;
            n /= 26;
        }
        return res;
    }
};
