/**
只有一个解.

unordered_map:可以用作hash表----查找速度O(1);

对于hash表冲突问题,这里处理方法是:
当前元素先不插入到hash表中,先对目标元素进行查找,如果找到了,就不用插入了[根本在于解决问题,find a solution];如果没有找到,再把元素插入到hash表;

Notes:
Hash表不一定非要事先初始化,可以与业务同步进行;
unordered_map:不能解决冲突问题:不能有相同的key--如果当前key在hash表中已经存在,那么不会进行插入操作.

**/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
	//hash: key元素值,value元素所在数组下标.
        unordered_map<int,int> hash;
        vector<int> res;
        for(int i=0;i<nums.size();i++){
            int numToFind = target - nums[i];
// 判断目标元素是否在hash表?
            if(hash.find(numToFind) != hash.end()){
                res.push_back(hash[numToFind]);
                res.push_back(i);
                break;
            }
            hash[nums[i]] = i;
        }
        return res;
    }
};
