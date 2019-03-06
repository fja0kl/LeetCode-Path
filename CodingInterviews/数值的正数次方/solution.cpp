class Solution {
public:
    bool g_InvalidInput = false;// 全局变量：用来判断程序是否出现异常，而且返回值可以直接使用，给变量赋值
    double Power(double base, int exponent) {
        g_InvalidInput = false;
        // 异常值：base为0，exponent为负数；
        if (fabs(base-0.0)<1e-9 && exponent < 0){
            g_InvalidInput = true;
            return 0.0;
        }
        // 功能性考虑：exponent为正数，负数，0；
        unsigned int absExponent = (unsigned int) exponent;
        if (exponent < 0)
            absExponent = (unsigned int)(-exponent);
        double result = absExponentPower(base, absExponent);
        if (exponent < 0) return 1.0/result;
        
        return result;
    }
    double absExponentPower1(double base, int exponent){
        double res = 1.0;
        for (int i=1; i<=exponent; i++)
            res *= base;
        return res;
    }
    double absExponentPower(double base, int exponent){
        if (exponent == 0) return 1;
        else if (exponent == 1) return base;
        else {
            double result = absExponentPower(base, exponent >> 1);
            result *= result;
            if (exponent & 0x1)
                result *= base;
            return result;
        }
    }
};
