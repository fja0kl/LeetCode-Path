/**
 * Bit Manipulation
 * 如果n是2的幂；则再n为一定只有一个1.：2^t
 *
 * 判断在n右移一位不为0的基础上，如果末尾为1，false；
 * 右移一位为0，说明是二进制最高位了如果n==1，true；
 *
 */
class Solution {
public:
    bool isPowerOfTwo(int n) {
        while(n>>1){
            if(n&0x1 == 1)
                return false;
            n = n >> 1;
        }
        if(n == 1)
            return true;
        return false;
    }
};
