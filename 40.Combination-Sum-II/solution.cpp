/**
排除相同的答案.
*/
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        backtracking(result, temp, candidates, target, 0);
        
        return result;
    }
private:
    void backtracking(vector<vector<int>>& result, vector<int>& temp, vector<int>& nums, int remain, int start){
        if(remain < 0) return;
        else if(remain == 0) result.push_back(temp);
        else{
            for(int i=start; i<nums.size(); i++){
		// 如果当前要添加元素和上一轮(一大轮)相同,跳过;
                if(i>start && nums[i] == nums[i-1]) continue;
                temp.push_back(nums[i]);
                backtracking(result, temp, nums, remain-nums[i], i+1);
                temp.pop_back();
            }
        }
    }
};
