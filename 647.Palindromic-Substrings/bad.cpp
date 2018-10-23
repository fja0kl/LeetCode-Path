/**
 * 先定义一个辅助函数：判断一个字符串是否是回文串；
 *
 * 对字符串s取所有子串，一次判断是否是回文串。
 *
 */
class Solution {
public:
    int countSubstrings(string s) {
        vector<string> sub;
        int cnt = s.size();
        for(int i=2;i<=s.size();i++){
            for(int j=0;j<s.size();j++){
                string sub = s.substr(j,i);//比较坑：如果长度大于边界，它会取从当前起点开始到结束的所有字符，尽管长度不等于给定值
                if(sub.size() == i && helper(sub) == true){
                    cnt++;
                }
            }
        }
        return cnt;
    }
private:
    bool helper(string s){
        // if(s.size() == 0 || s.size() == 1)
        //     return true;
        int n = s.size();
        for(int i=0;i< n;i++){
            if(s[i] != s[n-1-i])
                return false;
        }
        return true;
    }
};
