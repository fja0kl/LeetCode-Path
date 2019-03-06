class Solution {
public:
    bool isNumeric(char* string)
    {
        if (string == nullptr) return false;
        bool numeric = scanInt(&string);
        //如果出现‘.’，接下来是数字的小数部分
        if (*string == '.'){
            ++string;
            numeric = scanUnsignedInt(&string) || numeric;
        }
        // 出现‘e’，‘E’，科学计数法，接下来比较整数部分
        if (*string == 'e' || *string == 'E'){
            ++string;
            numeric = numeric && scanInt(&string);
        }
        // 直到终止符
        return numeric && *string == '\0';
    }
    bool scanUnsignedInt(char** str){
         char* before = *str;
        while (**str != '\0' && **str >= '0' && **str <= '9')
            ++(*str);
        //当str中出现若干0~9时，返回true
        return before < *str;
    }
    bool scanInt(char** str){
        //如果开头是'+'，'-'正负号，跳过这一位；
        if (**str == '+' || **str == '-')
            ++(*str);
        //比较是否含有整数(头部)
        return scanUnsignedInt(str);
    }
};
