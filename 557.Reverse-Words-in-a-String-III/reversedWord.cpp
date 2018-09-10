/**
 * stringstream 查询
 */
class Solution {
public:
    string reverseWords(string s) {
        string ans="";
        stringstream ss(s);
        while(ss>>s){//默认按照空格划分字符串
            if(ans!="") ans += " ";
            reverse(s.begin(),s.end());//翻转单个单词
            ans += s;
        }
        return ans;
    }
};
