/**
 * 对p的字符出现情况做个统计；
 * 
 * 遍历s串中与p长度相同的子串，每次遍历相同子串都复制一下p的统计情况，对统计结果中相应index的值做减法，如果小于0，说明
 * s串的当前字符没有出现在p串中，终止当前遍历，进行下一次遍历；
 * 如果遍历完s相同长度的子串后，都没有出现<0，说明这个子串满足要求，添加到结果中。
 *
 */
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        
        int ns = s.length(), np = p.length();
        if(ns < np)
            return res;
        
        vector<int> cnt(26,0);//用来对p串字符计数
        for(char c : p)
            ++cnt[c-'a'];
        int i=0;
        while(i < ns-np+1){
            vector<int> tmp = cnt;//每次都要对cnt进行复制，防止直接操作破坏cnt的计数结果
            bool success = true;
            for(int j = i;j < i + np; j++){
                if(--tmp[s[j]-'a'] < 0){//首先对cnt结果进行‘-’操作，如果结果小于0，说明字符在p中没有出现；直接返回
                    success = false;
                    break;
                }
            }
            if(success)
                res.push_back(i);
            i++;//下一次循环
        }
        return res;
    }
 
};
