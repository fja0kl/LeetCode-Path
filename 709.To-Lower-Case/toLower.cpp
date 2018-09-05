/**
 * String 转小写
 * ASCII 计算：大写字母比对应小写字母小32
 * 直接在原地址运算，修改原字符串；
 */

class Solution {
public:
    string toLowerCase(string str) {
        for(char& c : str)
            if(c >= 'A' && c<='Z') c += 32;
        
        return str;
    }
};
