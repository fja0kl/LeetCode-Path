/**
位运算:shift 右移,相当于除以2.

出错是因为:n >> 1. 没有对n赋值,导致时间溢出.[因为如果没有赋值,n不变,陷入死循环.]
**/
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt = 0;
        while(n){
            cnt += n & 1;
            n = n >> 1;
        }
        return cnt;
    }
};
