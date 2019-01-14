/**
* 先查询分割点pivot;
* pivot前,后分别为两个有序数组;
* 在两个有序数组之间,进行二分查找,
* 最后比较两个过程的查询结果,输出最终结果.
* 
* 有一点需要注意的是:如果是空数组,直接返回-1.
* 否则出错.
*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size()==0) return -1;
        int i = 0;
        //i 分界点
        while(i < nums.size()-1 && nums[i]<nums[i+1]) i++;
        int n1 = biSearch(nums, 0, i, target);
        int n2 = biSearch(nums, i+1, nums.size()-1, target);
        if(n1 == n2) return -1;
        return n1 == -1 ? n2 : n1;
    }
private:
    int biSearch(vector<int>& nums, int left, int right, int target){
        while(left <= right){
            int mid = left + (right - left)/2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return -1;
    }
};
