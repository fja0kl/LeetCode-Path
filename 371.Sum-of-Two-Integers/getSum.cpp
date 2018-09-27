/**
 * a^b 不带进位加法
 * (a&b)<<1 进位结果
 *
 * 两个相加，得到最终结果
 * 循环，直到进位为0为止。
 *
 * 因为可能会反复产生进位
 */
class Solution {
public:
    int getSum(int a, int b) {
        while(a){//当进位位不为0时循环;相加不产生进位
            int x = a ^ b;//不带进位加法
            a = (a & b)<<1;//进位位
            b = x;
        }
        return b;
    }
};
