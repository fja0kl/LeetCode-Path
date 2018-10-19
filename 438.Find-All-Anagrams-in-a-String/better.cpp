/**
 * 滑动窗口 复杂版--容易理解
 *
 */
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(s.size() < p.size()) return {};
        //left，right窗口的左右边界；
        //cnt是需要查找串的长度；n的查找范围s的长度
        int left=0, right = 0, cnt = p.size(), n = s.size();
        vector<int> res, map(256,0);//res结果；map是p串的统计结果

        for(char c : p)//对p串字符出现情况做统计，如果没有出现，对应位置为0
            ++map[c];

        while(right < n){//遍历s串
	    //后缀加法、后缀减法：在做完判断之后才进行加减运算的，也就是说在做完'>0'判断，才会对right和map进行加减运算
            if(map[s[right++]]-- > 0)//当前字符是否在map中，>0在;//map对应下标位置处-1；//移动到下一个位置
                cnt--;//如果在map中，cnt--，需要匹配的串长度减1

            if(cnt == 0)//是否查找到子串
                res.push_back(left);//将窗口左边界放到结果中

            if(right - left == p.size() && map[s[left++]]++ >= 0){//窗口大小等于子串长度,需要移动左边界
                //移动之前，先看左边界对应字符是否在map中
                cnt++;//如果map位置>=0,说明字符原来在map里，需要匹配长度+1；如果不在的话对应位置至少变为-1；
            }
        }

        return res;
    }

};

