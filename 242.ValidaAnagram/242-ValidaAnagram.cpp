/*变位词：字符顺序变换后得到的新单词；
 *主要思路：对两个字符串排序，之后，比较；
 */
class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(),s.end());//c++ 字符串排序，之间对原字符串更改
        sort(t.begin(),t.end());
        return s==t;
    }
};
