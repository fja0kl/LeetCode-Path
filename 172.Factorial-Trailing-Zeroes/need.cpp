/**
如果先计算阶乘,然后对结果计算10的倍数,时间超时.

这个计算5的倍数,不太理解
**/
class Solution {
public:
    int trailingZeroes(int n) {
        int cnt = 0;
        while(n){
            cnt += n/5;
            n /= 5;
        }
        return cnt;
    }
};
