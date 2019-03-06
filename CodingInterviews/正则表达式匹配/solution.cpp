class Solution {
public:
    bool match(char* str, char* pattern)
    {
        if (str == nullptr || pattern == nullptr) return false;
        
        return matchCore(str, pattern);
    }
    bool matchCore(char* str, char* pattern){
        if (*str == '\0' && *pattern == '\0') return true;
        if (*str != '\0' && *pattern == '\0') return false;
        if (*(pattern+1) == '*'){// 下一个字符是*，
            // 当前字符匹配：相等，或者是模式是'0';
            if (*pattern == *str || (*pattern == '.' && *str != '\0')){
                return matchCore(str,pattern+2) //模式中当前字符出现0次
                    //|| matchCore(str+1,pattern+2) //模式中当前字符出现1次
                    || matchCore(str+1,pattern);//模式中当前字符出现若干次；
            }
            // 当前字符不匹配，但下一个字符是'*',跳过当前模式:ac ab*c;指向c和b
            return matchCore(str, pattern+2);
        }
        if (*pattern == *str || (*pattern == '.' && *str != '\0'))
            return matchCore(str+1, pattern+1);
        return false;
    }
};
