/**
直接计算当前进位位权重,26的幂次方;从前往后算
其实,用循环更好
**/
class Solution {
public:
    int titleToNumber(string s) {
        int res = 0, len = s.size();
        for(int i=0; i<len; i++){
            int tmp = getNum26(s[i]);
            tmp *= pow(26, len-i-1);
            res += tmp;
        }
        return res;
    }
private:
    int getNum26(char a){
        return a - 'A' + 1;
    }
};
