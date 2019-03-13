/**
值得注意的是：要注意n的取值范围，大于length；

异常值；边界值。
**/
class Solution {
public:
    string LeftRotateString(string str, int n) {
        if (str.empty() || n <= 0) return str;
        n %= str.size();
        reverse(str.begin(), str.begin()+n);
        reverse(str.begin()+n, str.end());
        
        reverse(str.begin(), str.end());
        
        return str;
    }
};
