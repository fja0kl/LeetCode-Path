/**
0~9字符的ascii码为16进制表示30~39；可以直接用ascii码的后4位直接表示数字0~9---------ascii_code & 0xf   [位运算比字符做减法速度快]
**/
class Solution {
public:
    bool isValid = true;//是否是合法输入
    // 还可以通过isValid判断返回值0是正常输出，还是异常值
    int StrToInt(string str) {
        if (str.empty()){//字符串为空
            isValid = false;
            return 0;
        }
        // 正负号
        int flag = 1;
        if (str[0] == '-') flag = -1;
        int size = str.size();
        long long result;
        //遍历字符串
        for (int i=(str[0]=='+'||str[i]=='-') ? 1 : 0; i< size; i++){
            if (str[i]>='0' && str[i] <= '9'){
                result = (result<<1) + (result << 3) + flag*(str[i] & 0xf);
            } else{//特殊字符
                isValid = false;
                return 0;
            }
        }
        // 判断是否溢出
        /**if ((flag== 1 && result > 0x7fffffff) || (flag==-1 &&result < 0x80000000)){
            isValid = false;
            return 0;
        }**/
        // 返回结果
        return result;
    }
};
