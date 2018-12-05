/**
更精简:
从前往后算,先按照长度为1计算,循环后,再乘26,向前挪一位[26进制]
省略了底数幂次方计算;
刚开始是0次幂,之后循环再乘.
**/
class Solution {
public:
    int titleToNumber(string s) {
        int res = 0;
        for(auto c : s){
            res *= 26;
            res += (c -'A' + 1);
        }
        return res;
    }
};
