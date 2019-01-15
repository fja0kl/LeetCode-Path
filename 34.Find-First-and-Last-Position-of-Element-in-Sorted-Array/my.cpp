/**
递归形式:将每次查找结果保存到临时数组里,然后再对临时数组排序,寻找最大值和最小值作为最终结果.

当前解法是:如果第一次找到了,那么接着在两边数组继续查找,不断保存在临时数组里,最后再做最终结果计算.

Ye不错,毕竟是自己想出来的,还利用到了递归的思想.Not Bad~

方法可以优化:因为nums数组是有序数组,要求时间复杂度是O(logn),一定是二分法;
如果第一次查找已经找到,直接变成线性搜索,由找到的下标作为中心位置,向两边探索,不断变更边界范围.
*/
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        //if(nums.size() == 0) return vector<int>{-1,-1};
        int l = 0, r = nums.size() - 1;
        vector<int> temp;
        biSearch(nums,l,r,target,temp);
        if(temp.size() == 0) return vector<int>{-1,-1};
        sort(temp.begin(), temp.end());
        return vector<int>{temp[0], temp[temp.size()-1]};
    }
private:
    void biSearch(vector<int>& nums, int l, int r, int target, vector<int>& result){
        int i = binSearch(nums, l, r, target);
        if(i == -1) return;
        result.push_back(i);
        biSearch(nums, l, i-1, target, result);
        biSearch(nums, i+1, r, target, result);
    }
    int binSearch(vector<int>& nums, int l, int r, int target){
        while(l <= r){
            int mid = l + (r - l)/2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] < target)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return -1;
    }
};
