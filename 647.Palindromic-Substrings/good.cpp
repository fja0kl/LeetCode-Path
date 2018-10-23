/**
 * 
 * _以字符串中的每一个字符都当作回文串中间的位置，然后向两边扩散_，
 * 每当成功匹配两个左右两个字符，结果res自增1，然后再比较下一对。
 * 注意_回文字符串有奇数和偶数两种形式_，如果是奇数长度，
 * 那么i位置就是中间那个字符的位置，所以我们左右两遍都从i开始遍历；
 * 如果是偶数长度的，那么i是最中间两个字符的左边那个，右边那个就是i+1，
 * 这样就能cover所有的情况啦，而且都是不同的回文子字符串
 *
 */
class Solution {
public:
    int countSubstrings(string s) {
        if(s.empty()) return 0;
        int cnt = 0, n = s.size();
        for(int i=0; i<n; i++){
            helper(s,i,i,cnt);
            helper(s,i,i+1,cnt);
        }
        
        return cnt;
    }
private:
    void helper(string s, int i, int j, int & cnt){
        while(i>=0 && j<s.size() && s[i] == s[j]){
            --i;
            ++j;
            ++cnt;
        }
    }
};
