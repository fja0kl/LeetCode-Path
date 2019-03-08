class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        return verifyCore(sequence, 0, sequence.size()-1);
    }
    bool verifyCore(vector<int> arr, int start, int end){
        if (arr.empty()) return false;
        // 递归终止条件
        if (start >= end) return true;
        // 根节点是最后一个元素
        int root = arr[end];
        // 前半部分都大于根节点:向后遍历，找到第一个大于根的下标
        int i = 0;
        for (; i< end-1; i++)//此时i可以看做是左分支节点的数目
            if (arr[i] > root)
                break;
        //接着遍历右半分支：如果出现小于根节点的元素，直接返回false
        for (int j=i; j<end-1;j++)
            if (arr[j] < root)
                return false;
        // 接着进行递归
        return verifyCore(arr, start, i-1) && verifyCore(arr, i, end-1);
    }
};
