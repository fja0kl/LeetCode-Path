class Solution {
public:
    int Add(int num1, int num2)
    {
        int sum, carray;
        //num1当做最终结果，num2为进位位--当进位位不为0时，循环
        while (num2 != 0){
            sum = num1 ^ num2;
            carray = (num1 & num2) << 1;
            num1 = sum;
            num2 = carray;
        }
        return num1;
    }
};
