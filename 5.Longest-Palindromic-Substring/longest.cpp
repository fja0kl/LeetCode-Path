/**
* 还是回文串的查找问题
*/
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        
        int maxlen = 0, start = 0;
        for(int i=0; i<s.size(); i++){
            helper(s, i, i, maxlen, start);//奇对称
            helper(s, i, i+1, maxlen, start);//偶对称
        }
        
        return s.substr(start, maxlen);
    }
private:
    void helper(string s, int i, int j, int& maxlen, int& start){
        while(i>=0 && j<s.size() && s[i] == s[j]){//i，j表示要比较的两个字符位置
            i--; j++;
        }
        if(maxlen < j-i-1){//判断大小，保存最大长度和对应起始位置
            maxlen = j-i-1;//长度：i,j不相等，但i和j都变化了，计算相等之前的子串长度
            start = i + 1;
        }
    }
};
