//默认字母可以转换为整数；所以把字母当做数字，直接异或运算。
class Solution {
public:
    char findTheDifference(string s, string t) {
        int res = 0;
        for(int i=0;i<t.length();i++)
            res ^= t[i];
        for(int i=0;i<s.length();i++)
            res ^= s[i];
        return (char)res;
    }
};
