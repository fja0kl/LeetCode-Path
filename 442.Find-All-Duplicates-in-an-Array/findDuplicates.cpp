/**
 * 重复利用数组---因为新建数组长度和原始数组长度相同；
 * 只对数组元素进行取反操作，并不改变绝对值；而反---相当于新元素的1
 * 参考 448
 */

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        
        for(int i=0;i<nums.size();i++){
            int idx = abs(nums[i]) -1;//数组下标
            nums[idx] = -nums[idx];//出现一次，就翻转；如果出现两次变正--取正;;漏洞：没有出现对应下标也为正。
            
            if(nums[idx] > 0) res.push_back(idx+1);//进一步判断是否是正数-----由负得正
        }
                
        return res;
    }
};
