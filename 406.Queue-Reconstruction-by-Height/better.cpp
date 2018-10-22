/**
 * 题干中：关注的是大于等于身高的人；歧视低身高的人；身高最低的人，一定在最后，而对应数目就是前面所有人的数目---也就是说他的数目就是数组中对应的位置[0-based index]，所以这就可以转换成一个子问题，对第二低、第三低依次插入。
 *
 *
 * 好聪明----还要充分理解题干中的信息。
 *
 * 所以我们先按照身高降序排序，然后按数目升序排序；
 *
 * 遍历排序后的数组，
 *
 * 前后遍历数组：元素的第二元素就是在新数组中的位置下标.
 *
 *
 * 1. 排序
 * 2. 插入
 *
 */
class Solution {    
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        vector<pair<int, int>> res;
        if(people.empty()) return res;
        sort(people.begin(), people.end(), myComp);
        
        for(auto p : people){
            res.insert(res.begin() + p.second, p);
        }
        
        return res;
       
    }
    static bool myComp(pair<int,int> a,pair<int,int> b){
        //先按第一关键字排序(降序)，再按第二关键字排序(升序)
        if(a.first != b.first)
            return a.first > b.first;
        
        return a.second < b.second;
    }
};
