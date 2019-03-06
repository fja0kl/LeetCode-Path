class Solution {
public:
     int  NumberOf1(int n) {
         int count = 0;//主要问题在：负数，负数右移补充符号位，最后陷入死循环
         while (n){//n有多少1，能进行多少次运算
             count++;
             n = n & (n-1);//将n最右边的1变为0
         }
         return count;
     }
};
