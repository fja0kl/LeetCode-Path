/**
 * backtracking 回溯法： 深搜 + 剪枝
 *
 * 数字排列：
 * 1 2 3
 *
 * 对1 2 3排列：从第一个元素开始，之后固定前面结果，对后面元素进行递归排列，直到找到最终答案；对原来的元素进行复原，方便下次循环。
 * 对2 1 3排列
 * 对3 2 1排列
 *
 */
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> > res;
        if(nums.empty()) return res;
        if(nums.size() == 1){
            res.push_back(nums);
            return res;
        }
        helper(nums,0,res);
        
        return res;
    }
private:
    void helper(vector<int>& nums, int begin, vector<vector<int> >& res){
        if(begin == nums.size())
            res.push_back(nums);
        // nums[0..begin-1] 是固定的，已经排列好的，对剩下的元素进行排列；最后固定
        for(int i=begin; i< nums.size(); i++){
            swap(nums[i],nums[begin]);//交换,排列一个元素
            helper(nums,begin+1,res);//对后面元素进行递归，排列元素减少了
            swap(nums[i],nums[begin]);//复原，方便下次循环
        }
    }
};
