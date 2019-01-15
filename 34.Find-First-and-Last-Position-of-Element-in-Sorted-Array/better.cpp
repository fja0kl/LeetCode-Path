/**
优化版:找到后,采用线性探索,直接处理;方法更简洁,直观.
*/
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        //if(nums.size() == 0) return vector<int>{-1,-1};
        int t = binSearch(nums, 0, nums.size()-1, target);
        // 没找到
        if(t == -1) return {-1, -1};
        // 找到了,向两边进行线性探索
        int left = t, right = t;
        while(left>0 && nums[left-1]== nums[left]) left--;
        while(right<nums.size()-1 && nums[right] == nums[right+1]) right++;
        return {left, right};
    }
private:
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

