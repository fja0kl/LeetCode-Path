/**
主要问题在:32位.
uint32_t类型的数字,二进制后一定是32位,不够时也要补齐[否则翻转后会出错]
**/
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        for(int i=0; i<32; i++)
//             n >> i & 1 判断当前末尾是0还是1;赋值给res. res先左移一位.
            res = (res << 1) + (n>>i & 1);
        return res;
    }
};
