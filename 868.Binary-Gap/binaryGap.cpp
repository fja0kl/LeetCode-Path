/*
 * 位运算
 */
class Solution {
public:
    int binaryGap(int N) {
        int maxd = 0, d = 0;
        bool count = false;//计数
        
        while(N){
            if(N&1){//判断末尾是0还是1：如果是1
                count = true;
                maxd = max(maxd, d);
                d = 0;//重置d
            }
            if(count)//1和1之间有间隔
                d++;
            N = N>>1;
        }
        
        return maxd;
    }
};
