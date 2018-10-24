/**
 * 思路和python解法相同：字典计数；排序
 *
 * 使用大顶堆完成对字典值进行排序
 *
 * 看看STL：好多方便的数据结构
 *
 */
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> cnt;
        priority_queue<pair<int, int>> q;
        vector<int> res;
        
        for(auto i : nums) ++cnt[i];
        //大顶堆：priority_queue默认是大顶堆：
        //添加后，自动构建大顶堆(默认按照键值排序--所以翻转顺序)
        for (auto it : cnt) q.push({it.second, it.first});
        
        //前k个大顶推元素添加到res中
        for(int i=0;i<k;i++){
            res.push_back(q.top().second);
            q.pop();
        }
        
        return res;
    }
};
