/**
3Sum 3SumCloseset变种;
解法都相同;


但有一个疑问:最后处理number 3和number 4时,为什么用do while循环? 我使用while 循环,提示memory limitation error.

**/
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        if(nums.size() < 4) return res;
        //sort the array
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size()-3; i++){
            //processing the duplicates of number 1
            if(i>0 && nums[i]==nums[i-1]) continue;
            for(int j=i+1; j<nums.size()-2; j++){
                //processing the duplicates of number 2
                if(j>i+1 && nums[j] == nums[j-1]) continue;
                int left = j+1, right = nums.size()-1;
                while(left < right){
                    int sum = nums[i] + nums[j] + nums[left] + nums[right];
                    if(sum < target) left++;
                    else if(sum > target) right--;
                    else{
                        res.push_back(vector<int>{nums[i],nums[j],nums[left],nums[right]});
                        //processing the duplicates of number 3
                        do{left++;}while(left<right && nums[left]==nums[left-1]);
                        do{right--;}while(left<right && nums[right]==nums[right+1]);
                    }
                }
            }
        }
        return res;
    }
};
