class Solution {
public:
    bool b_InvalidInputs = false;
    int FindGreatestSumOfSubArray(vector<int> array) {
        if (array.empty()){
            // 区分无效输入 和 最大值为0 的情况
            b_InvalidInputs = true;
            return 0;
        }
        b_InvalidInputs = false;
        int curSum = 0, maxSum = INT_MIN;
        for (int i=0; i< array.size(); i++){
            if (curSum <= 0)
                curSum = array[i];
            else
                curSum += array[i];
            
            if (curSum > maxSum)
                maxSum = curSum;
        }
        
        return maxSum;
    }
};
