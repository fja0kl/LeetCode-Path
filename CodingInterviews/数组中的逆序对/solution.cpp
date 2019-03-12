class Solution {
public:
    int InversePairs(vector<int> data) {
        if (data.empty()) return 0;
        vector<int> copy(data.begin(), data.end());
        return inversePairsCore(data, copy, 0, data.size()-1);
    }
    // 归并排序，同时完成逆序数统计:data也发生了修改(中间状态)，copy最终结果
    int inversePairsCore(vector<int>& data, vector<int>& copy, int start, int end){
        // 终止条件
        if (start == end){
            // copy归并后有序数组
            copy[start] = data[start];
            return 0;
        }
        // 对半分
        int length = (end - start) / 2;
        // 递归：排序，并完成逆序数统计
        int left = inversePairsCore(data, copy, start, start+length)%1000000007;
        int right = inversePairsCore(data, copy, start+length+1, end)%1000000007;
        // 统计子数组之间的逆序数：子数组已经完成排序
        // i初始化为前半段的右边界
        int i = start+length;
        // j初始化为后半段的右边界
        int j = end;
        // indexCopy初始化为copy数组的右边界，方便对copy进行赋值
        int indexCopy = end;
        int count = 0;
        // 遍历左右数组，完成排序以及逆序数统计
        while (i>=start && j>= start+length+1){
            if (data[i] > data[j]){//存在逆序数：所以用data比较
                copy[indexCopy--] = data[i--];
                count += j - start - length;//右半数组元素数目
                if(count >= 1000000007)//数值过大求余
                    count %= 1000000007;
            } else{
                copy[indexCopy--] = data[j--];
            }
        }
        // 左半部分数组对copy赋值
        for(; i>=start; i--)
            copy[indexCopy--] = data[i];
        for (; j>= start+length+1; j--)
            copy[indexCopy--] = data[j];
        for(int i=start; i<=end; i++)
            data[i] = copy[i];
    
        return (left+right+count)%1000000007;
    }
};
