/**
空间换时间
*/
class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        if (index <= 0) return 0;
        int* uglyNums = new int[index];
        uglyNums[0] = 1;
        int pNextUglyIdx = 1;
        // 初始指针:
        //pMul2指针指向:这个index之前的数乘2都小于当前最大的丑数，
        //这个index开始，乘2都大于最大丑数；pMul3，pMul5类似
        int* pMul2 = uglyNums;
        int* pMul3 = uglyNums;
        int* pMul5 = uglyNums;
        while (pNextUglyIdx < index){
            // 新丑数，取最小
            int min = getMin(*pMul2*2, *pMul3*3, *pMul5*5);
            uglyNums[pNextUglyIdx] = min;//保存到数组中
            // 更新指针
            while (*pMul2 * 2 <= uglyNums[pNextUglyIdx])
                pMul2++;
            while (*pMul3 * 3 <= uglyNums[pNextUglyIdx])
                pMul3++;
            while (*pMul5 * 5 <= uglyNums[pNextUglyIdx])
                pMul5++;
            pNextUglyIdx++;// 计算下一个丑数
        }
        int ugly = uglyNums[index-1];
        delete[] uglyNums;
        return ugly;
    }
    int getMin(int a, int b, int c){
        int min = a < b ? a : b;
        return min < c ? min : c;
    }
};
