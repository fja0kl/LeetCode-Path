/**
统计二进制中1的个数。
**/
class Solution {
public:
     int  NumberOf1(int n) {
         int temp = n;
         // 每一位1个数求和： 55（0101 0101）aa（1010 1010）
         temp = (temp & 0x55555555) + ((temp & 0xaaaaaaaa) >> 1);
         // 每两位1个数求和：33(0011 0011) cc (1100 1100) 
         temp = (temp & 0x33333333) + ((temp & 0xcccccccc) >> 2);
         // 每四位1个数求和：0f(0000 1111) f0 (1111 0000) 
         temp = (temp & 0x0f0f0f0f) + ((temp & 0xf0f0f0f0) >> 4);
         // 每八位1个数求和：ff(1111 1111) 00 (0000 0000) 
         temp = (temp & 0x00ff00ff) + ((temp & 0xff00ff00) >> 8);
         // 每十六位1个数求和：fffff(1111 1111 1111 1111) 0000 (0000 0000 0000 0000) 
         temp = (temp & 0x0000ffff) + ((temp & 0xffff0000) >> 16);
         
         // 统计32位数中1的个数
         return temp;
     }
};
