/**
 * 滑动窗口方法：保存最新出现的位置 
 */
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty()) return 0;
        int map[256] = {0}, left = 0, res = 0;
        for(int i=0; i<s.size(); i++){
            if(map[s[i]] == 0 || map[s[i]] < left){
                res = max(res, i-left+1);
            }else{
                left = map[s[i]];
            }
            map[s[i]] = i+1;//下一个位置
        }
        
        return res;
    }
};
