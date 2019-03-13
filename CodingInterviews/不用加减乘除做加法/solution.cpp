class Solution {
public:
    int Add(int num1, int num2)
    {
        int sum, carray;
        //num1当做最终结果，num2为进位位--当进位位不为0时，循环
        while (num2 != 0){
            sum = num1 ^ num2;//不带进位计算加法
            carray = (num1 & num2) << 1;//计算进位位
            num1 = sum;//计算不带进位计算结果和进位相加的结果
            num2 = carray;// 终止条件是进位位为0
        }
        return num1;
    }
};
