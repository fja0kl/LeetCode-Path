/**
n & (n-1) 位运算用途:
1. 判断n是否是2的幂次方;
2. 将n二进制表示中的最低位1变为0;因此可以用来统计n的二进制表示中有几个1.
**/
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt = 0;
        while(n){
            n &= (n-1);
            cnt++;
        }
        return cnt;
    }
};
