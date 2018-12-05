/**
本质上就是一种进制转换:和二进制转10进制相同.

从后往前算:循环计算进位位;
初始进位位为1,之后乘26.
**/
class Solution {
public:
    int titleToNumber(string s) {
        int res = 0, len = s.size() - 1;
        int weight = 1;
        for(int i=len; i>=0; i--){
            res += (s[i] - 'A' + 1) * weight;
            weight *= 26;
        }
        return res;
    }
};
