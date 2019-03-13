/**
根据异或运算结果，从后往前数第一个1的下标，对原始数组分类，分成两类，然后对两类数组分别异或计算，得到最终的两个结果。
**/
class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        if (data.size() < 2) return;
        int res = 0;
        for (int i=0; i<data.size(); i++)
            res ^= data[i];
        int first1Idx = findFirst1Idx(res);
        *num1 = *num2 = 0;
        for (int i=0; i< data.size(); i++){
            if (isBit1(data[i], first1Idx))
                *num1 ^= data[i];
            else
                *num2 ^= data[i];
        }
    }
    bool isBit1(int num, int index){
        num = num >> index;
        return (num & 1);
    }
    int findFirst1Idx(int num){
        int idx = 0;
        while (((num & 1) == 0) && (idx < 8 * sizeof(int))){
            num = num >> 1;
            idx++;
        }
        return idx;
    }
};
